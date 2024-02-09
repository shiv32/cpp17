// CONDITION VARIABLES
// g++ --std=c++17 main.cpp -o test -pthread

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;


void ThreadF_1() {

    std::unique_lock lock(mtx);

    std::cout << "Thread 1: Acquired lock" << std::endl;
    
    // Wait until ready is true
    cv.wait(lock, []{ return ready; });
    
    // Do something
    std::cout << "Thread 1: Received notification" << std::endl;
}

// Function for thread 2
void ThreadF_2() {
    
    std::lock_guard lock(mtx);
    
    std::cout << "Thread 2: Acquired lock" << std::endl;
    
    // Modify ready
    ready = true;
    
    // Notify waiting threads
    cv.notify_one();
    
    std::cout << "Thread 2: Released lock and notified" << std::endl;
}

int main() {
    // Create threads
    std::thread t1(ThreadF_1);
    std::thread t2(ThreadF_2);

    // Join threads
    t1.join();
    t2.join();

    std::cout << "All threads finished" << std::endl;

    return 0;
}
