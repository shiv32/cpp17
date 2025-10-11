#include <iostream>
#include <cstdint>

#define TRACE std::clog << __PRETTY_FUNCTION__ << std::endl;

class communication_base
{
public:
    virtual ~communication_base() {}

    // A virtual initialization function.
    virtual void init()
    {
        TRACE
    }

protected:
    communication_base()
    {
        // Undefined use of the virtual mechanism!
        // init(); // Remove initialization from the base class ctor.
    }
};

class communication_serial : public communication_base
{
public:
    // communication_serial(const std::uint16_t c, const std::uint8_t b)
    communication_serial(const std::uint16_t c, const std::uint32_t b)
        : channel(c),
          baud(b)
    {
    }

    virtual ~communication_serial()
    {
    }

    virtual void init()
    {
        // Initialize this communication_serial class.
        TRACE
    }

private:
    const std::uint8_t channel;
    const std::uint16_t baud;
};

void do_something()
{
    // Create com_serial on channel 1 with 9600bps.
    communication_serial com_serial(1U, 9600U);

    // Explicitly initialize com_serial.
    // It is fully formed.
    com_serial.init();

    // Use com_serial.
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    do_something();

    return 0;
}
