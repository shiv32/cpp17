/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Lock-Free Queue for Market Data
 * @version 0.1
 * @date 2024-12-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <atomic>
#include <iostream>
#include <thread>

// Node structure for the queue
template <typename T>
struct Node {
    T data;
    std::atomic<Node<T>*> next;

    explicit Node(const T& value) : data(value), next(nullptr) {}
};

// Lock-Free Queue Class
template <typename T>
class LockFreeQueue {
private:
    std::atomic<Node<T>*> head; // Head pointer
    std::atomic<Node<T>*> tail; // Tail pointer

public:
    // Constructor
    LockFreeQueue() {
        Node<T>* dummy = new Node<T>(T()); // Dummy node
        head.store(dummy);
        tail.store(dummy);
    }

    // Destructor
    ~LockFreeQueue() {
        while (Node<T>* node = head.load()) {
            head.store(node->next);
            delete node;
        }
    }

    // Enqueue: Adds an element to the queue
    void enqueue(const T& value) {
        Node<T>* newNode = new Node<T>(value); // Allocate new node
        Node<T>* oldTail;

        while (true) {
            oldTail = tail.load(std::memory_order_relaxed);
            Node<T>* next = oldTail->next.load(std::memory_order_relaxed);

            // If tail hasn't moved, proceed
            if (oldTail == tail.load(std::memory_order_acquire)) {
                if (next == nullptr) { // Tail is at the end
                    if (oldTail->next.compare_exchange_weak(next, newNode)) {
                        break; // Successfully linked the new node
                    }
                } else {
                    // Tail was lagging, advance it
                    tail.compare_exchange_weak(oldTail, next);
                }
            }
        }

        // Update the tail pointer to the new node
        tail.compare_exchange_weak(oldTail, newNode);
    }

    // Dequeue: Removes and returns an element from the queue
    bool dequeue(T& result) {
        Node<T>* oldHead;

        while (true) {
            oldHead = head.load(std::memory_order_relaxed);
            Node<T>* oldTail = tail.load(std::memory_order_relaxed);
            Node<T>* next = oldHead->next.load(std::memory_order_relaxed);

            // If head hasn't moved, proceed
            if (oldHead == head.load(std::memory_order_acquire)) {
                if (oldHead == oldTail) { // Queue might be empty
                    if (next == nullptr) {
                        return false; // Queue is empty
                    }
                    // Tail is lagging, advance it
                    tail.compare_exchange_weak(oldTail, next);
                } else {
                    // Retrieve the value and update the head
                    result = next->data;
                    if (head.compare_exchange_weak(oldHead, next)) {
                        break; // Successfully dequeued
                    }
                }
            }
        }

        delete oldHead; // Free the old head
        return true;
    }
};

int main() {
    LockFreeQueue<int> queue;

    // Example usage: Producer and Consumer
    // Producer thread
    std::thread producer([&queue]() {
        for (int i = 0; i < 1000; ++i) {
            queue.enqueue(i);
            std::cout << "Enqueued: " << i << std::endl;
        }
    });

    // Consumer thread
    std::thread consumer([&queue]() {
        int value;
        for (int i = 0; i < 1000; ++i) {
            while (!queue.dequeue(value)) {
                // Spin until data is available
            }
            std::cout << "Dequeued: " << value << std::endl;
        }
    });

    producer.join();
    consumer.join();

    return 0;
}
