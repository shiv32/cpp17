#include <iostream>
#include <coroutine>

using namespace std;

namespace normalFunction
{
    void printNumbers()
    {
        cout << 1 << '\n';
        cout << 2 << '\n';
        cout << 3 << '\n';
    }
}

namespace coroutineExample1
{
    //This example only shows co_return. 
    //It doesn't pause, so it's not very interesting.
    struct Task
    {
        struct promise_type
        {
            Task get_return_object() { return {}; }

            std::suspend_never initial_suspend() { return {}; }
            std::suspend_never final_suspend() noexcept { return {}; }

            void return_void() {}
            void unhandled_exception() {}
        };
    };

    Task hello()
    {
        std::cout << "Hello\n";
        co_return;
    }
}

namespace coroutineExample2
{
    /*
        Small Example with Pause (co_yield)
        This is the classic use of coroutines: 
        generate one value at a time while automatically remembering where execution stopped.
    */
    class Generator
    {
    public:
        struct promise_type;
        using Handle = std::coroutine_handle<promise_type>;

        struct promise_type
        {
            int current;

            Generator get_return_object()
            {
                return Generator{Handle::from_promise(*this)};
            }

            std::suspend_always initial_suspend() { return {}; }
            std::suspend_always final_suspend() noexcept { return {}; }

            std::suspend_always yield_value(int value)
            {
                current = value;
                return {};
            }

            void return_void() {}
            void unhandled_exception() { std::terminate(); }
        };

        explicit Generator(Handle h) : handle(h) {}

        ~Generator()
        {
            if (handle)
                handle.destroy();
        }

        bool next()
        {
            handle.resume();
            return !handle.done();
        }

        int value() const
        {
            return handle.promise().current;
        }

    private:
        Handle handle;
    };

    Generator numbers()
    {
        co_yield 1;
        co_yield 2;
        co_yield 3;
    }

    void test()
    {
        auto g = numbers();

        while (g.next())
            std::cout << g.value() << '\n';
    }
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // normalFunction::printNumbers();
    // coroutineExample1::hello();
    coroutineExample2::test();

    return 0;
}
