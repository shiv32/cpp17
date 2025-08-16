#include <iostream>
#include <cstdint>
#include <iomanip>

// Simulated memory array for testing
std::uint8_t simulated_memory[256] = {0};

void alignofFun()
{
    auto as = alignof(short); // Could be 2, 4,...
    std::clog << "as : " << as << std::endl;

    auto ai = alignof(int); // Could be 2, 4,...
    std::clog << "ai : " << ai << std::endl;

    auto aL = alignof(long); // Could be 4, 8,...
    std::clog << "aL : " << aL << std::endl;

    auto aLL = alignof(long long); // Could be 8,...
    std::clog << "aLL : " << aLL << std::endl;
}

struct alignas(16) timer_register_type
{
    std::uint32_t tmr_ctrl1;
    std::uint32_t tmr_ctrl2;
    std::uint32_t tmr_cntr1;
    std::uint32_t tmr_cntr2;
};

//-----
// constexpr std::uintptr_t TIMER_BASE = 0x40000000;
// volatile timer_register_type *const TIMER = reinterpret_cast<volatile timer_register_type *>(TIMER_BASE);

constexpr std::uintptr_t TIMER_BASE = 0x00000000;
volatile timer_register_type *const TIMER = reinterpret_cast<volatile timer_register_type *>(&simulated_memory[TIMER_BASE]);

void simulateFun()
{
    // simulate TIMER at offset 0x00 in fake memory
    // auto *TIMER = reinterpret_cast<timer_register_type *>(&simulated_memory[0]);

    // write to "registers"
    TIMER->tmr_ctrl1 = 0x01; // Start timer
    TIMER->tmr_cntr1 = 0x00; // Reset counter

    // read back
    std::cout << "tmr_ctrl1 = " << TIMER->tmr_ctrl1 << "\n";
    std::cout << "tmr_cntr1 = " << TIMER->tmr_cntr1 << "\n";
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    alignofFun();

    std::clog << "Size: " << sizeof(timer_register_type) << " bytes\n";
    std::clog << "Alignment: " << alignof(timer_register_type) << " bytes\n";

    timer_register_type reg{};
    std::clog << "Address: " << &reg << "\n";

    //----
    TIMER->tmr_ctrl1 = 0x01; // Start timer
    TIMER->tmr_cntr1 = 0x00; // Reset counter

    simulateFun();

    return 0;
}
