#include "ThreadPool.hpp"
#include <iostream>
#include <chrono>

int main() {
    
    ThreadPool pool(4);

    for (int i = 0; i < 10; ++i) {
        pool.enqueue([i] {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "Task " << i << " done\n";
        });
    }

    return 0;
}
