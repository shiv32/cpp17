// Copying and Rethrowing Exceptions
// g++ main.cpp -o test -pthread

#include <iostream>
#include <thread>

void doSomeWork()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << i << std::endl;
    }
    
    std::cout << "Thread throwing a runtime_error exception..." << std::endl;

    throw std::runtime_error("Exception from thread");
}

void threadFunc(std::exception_ptr &err)
{
    try
    {
        doSomeWork();
    }
    catch (...)
    {
        std::cout << "Thread caught exception, returning exception..." << std::endl;
        err = std::current_exception();
    }
}

void doWorkInThread()
{
    std::exception_ptr error;
    
    // Launch thread
    std::thread t{threadFunc, std::ref(error)};
    
    // Wait for thread to finish
    t.join();
    
    // See if thread has thrown any exception
    if (error)
    {
        std::cout << "Main thread received exception, rethrowing it..." << std::endl;
        rethrow_exception(error);
    }
    else
    {
        std::cout << "Main thread did not receive any exception." << std::endl;
    }
}

int main()
{
    try
    {
        doWorkInThread();
    }
    catch (const std::exception &e)
    {
        std::cout << "Main function caught: '" << e.what() << "'" << std::endl;
    }
    return 0;
}