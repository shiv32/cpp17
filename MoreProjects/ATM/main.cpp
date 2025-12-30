#include <iostream>

namespace machine
{
    class ATM
    {
    public:
        void run()
        {
            std::clog << "ATM start" << std::endl;
        }
    };

}

int main(int argc, char **argv)
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    machine::ATM atm;
    atm.run();

    return 0;
}