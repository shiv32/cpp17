#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

// A simple message queue
namespace messaging
{
    struct message_base // 1 Base class of your queue entries
    {
        virtual ~message_base()
        {
        }
    };

    template <typename Msg>
    struct wrapped_message : message_base // 2 Each message type has a specialization.
    {
        Msg contents;
        explicit wrapped_message(Msg const &contents_) : contents(contents_)
        {
        }
    };

    class queue // 3 Your message queue
    {
        std::mutex m;
        std::condition_variable c;
        std::queue<std::shared_ptr<message_base>> q; // 4 Internal queue stores pointers to message_base

    public:
        template <typename T>
        void push(T const &msg)
        {
            std::lock_guard<std::mutex> lk(m);
            q.push(std::make_shared<wrapped_message<T>>(msg)); // 5  Wrap posted message and store pointer
            c.notify_all();
        }

        std::shared_ptr<message_base> wait_and_pop()
        {
            std::unique_lock<std::mutex> lk(m);

            c.wait(lk, [&]
                   { return !q.empty(); }); // 6 Block until queue isn’t empty

            auto res = q.front();
            q.pop();

            return res;
        }
    };
}

int main(int argc, char *argv[])
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}