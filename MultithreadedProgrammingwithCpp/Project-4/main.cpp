/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Thread with Member Function

            g++ main.cpp -o test -pthread && ./test && rm test
 *
 *
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <thread>

class Request
{
public:
    Request(int id) : mId(id) 
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }

    void process()
    {
        std::cout << "Processing request " << mId << std::endl;
    }

private:
    int mId;
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Request req(100);

    std::thread t{&Request::process, &req};

    t.join();
}