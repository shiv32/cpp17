// Thread with Member Function

// g++ main.cpp -o test -pthread

#include <iostream>
#include <thread>

class Request
{
public:
    Request(int id) : mId(id) {}
    void process()
    {
        std::cout << "Processing request " << mId << std::endl;
    }

private:
    int mId;
};

int main()
{
    Request req(100);

    std::thread t{&Request::process, &req};
    
    t.join();
}