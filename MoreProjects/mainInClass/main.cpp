#include <iostream>

namespace myApp
{
    class App
    {
    public:
        void main() // just a member function
        {
            std::cout << "Hello from App::main()" << std::endl;
        }
    };
};

namespace myApp2
{
    struct App
    {
        void main() // just a member function
        {
            std::clog << "hello C++ ." << std::endl;
        }
    };
};

namespace myApp3
{
    class MyApp
    {
    public:
        // run() does all the real work
        int run(int argc, char *argv[])
        {
            std::cout << "Program name: " << argv[0] << "\n";

            if (argc > 1)
            {
                std::cout << "Arguments passed:\n";
                for (int i = 1; i < argc; ++i)
                {
                    std::cout << "  " << i << ": " << argv[i] << "\n";
                }
            }
            else
            {
                std::cout << "No extra arguments.\n";
            }

            // Return 0 to indicate success
            return 0;
        }
    };
}

namespace myApp4
{
    class MyApp
    {
    public:
        // run() does all the real work
        int run(int argc, char *argv[])
        {
            std::cout << "Hello C++ " << "\n";

            // Return 0 to indicate success
            return 0;
        }
    };
}

int main(int argc, char *argv[]) // real entry point
{
    using namespace myApp4;

    // App app;
    // app.main(); // call the member function manually

    // Create a temporary MyApp object and immediately call run()
    return MyApp().run(argc, argv);

    return 0;
}