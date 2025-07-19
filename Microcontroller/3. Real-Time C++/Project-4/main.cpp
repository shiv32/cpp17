#include <iostream>
#include <cstdint> //uint32_t, uint16_t, etc. are fixed-width integer types

// Namespace for the microcontroller abstraction layer.
namespace mcal
{
    // The mcal initialization.
    void init();

    // The general purpose timer stuff in the mcal.
    namespace gpt
    {
        void init();
        std::uint32_t get_time_elapsed();
    }

    // The ADC stuff in the mcal.
    namespace adc
    {
        void init();
        std::uint16_t read_value(const unsigned);
    }
}

void mcal::gpt::init()
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;
}

void mcal::adc::init()
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;
}

// Initialize the mcal.
// Note the clean organization with namespaces.
void mcal::init()
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;
    mcal::gpt::init();
    mcal::adc::init();
}

//-------------------------------------------------------------------------
/*
    A file-local anonymous namespace.
    Prevent name clashes across multiple .cpp files.
    Keep internal helper variables, functions, or types private to a source file.
*/

namespace
{
    unsigned local_counter;
}

//--------------------------------------------------------------------------
// A traditional namespace definition.
namespace X
{
    namespace Y
    {
        namespace Z
        {
            int value;
        }
    }
}

// A C++17 nested namespace definition.
namespace X::Y::Z
{
    int value2;
}

void do_something()
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;

    X::Y::Z::value = 1;
    X::Y::Z::value2 = 1;
}
//-------------------------------------------------------------------------

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    mcal::init();

    local_counter = 0;

    do_something();

    return 0;
}
