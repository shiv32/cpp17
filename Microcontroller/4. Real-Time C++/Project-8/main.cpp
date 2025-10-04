#include <iostream>
#include <cstdint>

#define TRACE std::clog << __PRETTY_FUNCTION__ << std::endl;

/*
The interrupt attribute is a target-specific GCC extension
(for some microcontroller architectures such as AVR or certain ARM targets).
On x86 or other unsupported targets it rejects anything that doesn’t match the strict prototype it expects.
*/
// isr ->  interrupt service routine.
//  extern "C" //for no name mangling in C++ for C fun
//  void com_recv_isr() __attribute__((interrupt));
void com_recv_isr(); // Linux desktop simulation of interrupts

// Simulated memory array for testing
// The size of the array is specified as 256,
// meaning it can hold 256 individual 8-bit unsigned integers (or bytes).
// Simulated memory buffer with 256 bytes, initialized to 0
std::uint8_t simulated_memory[256] = {0};

class communication
{
public:
    communication() : recv_buf(0U), has_recv(false) {}
    ~communication() {}

    bool send_byte(const std::uint8_t by) const
    {
        //*reinterpret_cast<volatile std::uint8_t *>(tbuf) = by;
        *reinterpret_cast<volatile std::uint8_t *>(&simulated_memory[tbuf]) = by;
        return true; // indicate success
    }

    bool recv_ready() const { return has_recv; }

    std::uint8_t recv_byte()
    {
        if (has_recv)
        {
            has_recv = false;
            return recv_buf;
        }

        return 0U;
    }

private:
    static constexpr std::uint8_t tbuf = 0xAAU;
    static constexpr std::uint8_t rbuf = 0xAEU;

    std::uint8_t recv_buf;
    bool has_recv;

    communication(const communication &) = delete;
    const communication &operator=(const communication &) = delete;

    //  friend void com_recv_isr() __attribute__((interrupt));
    friend void com_recv_isr();
};

bool wakeup(const communication &com)
{
    TRACE

    // OK. Call a const member of a const reference.
    return com.send_byte(0x12U);
}

// bool login(const communication &com)
// {
//     // OK. Call the const send_byte on a const reference.
//     const bool wakeup_is_ok = com.send_byte(0x12U);

//     if (wakeup_is_ok)
//     {
//         // Compiler error!
//         return (com.recv_byte() == 0x34U);
//     }
//     else
//     {
//         return false;
//     }
// }

bool login2(communication &com)
{
    TRACE

    // OK. Call the const send_byte on a reference.
    const bool wakeup_is_ok = com.send_byte(0x12U);

    if (wakeup_is_ok)
    {
        // OK.
        return (com.recv_byte() == 0x34U);
    }
    else
    {
        return false;
    }
}

// extern communication com;
communication com;

// Communication’s friend and also an ISR(interrupt service routine).
void com_recv_isr()
{
    // Asynchronous byte reception can use the private members of com.
    com.recv_buf = *reinterpret_cast<volatile std::uint8_t *>(communication::rbuf);

    com.has_recv = true;
}

void task_poll_the_com()
{
    if (com.recv_ready())
    {
        const std::uint8_t the_byte = com.recv_byte();

        // Do something with the_byte.
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    communication com;

    std::clog << wakeup(com) << std::endl;

    std::clog << login2(com) << std::endl;

    return 0;
}
