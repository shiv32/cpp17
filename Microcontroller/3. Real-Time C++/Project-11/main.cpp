#include <iostream>
#include <array>
#include <cstdint>
#include <vector>

// A login key stored in an std::array.
constexpr std::array<std::uint8_t, 3U> login_key{
    {UINT8_C(0x01),
     UINT8_C(0x02),
     UINT8_C(0x03)}};

// Function that checks if the received key matches
bool validate_key(const std::vector<std::uint8_t> &received)
{
    if (received.size() < login_key.size())
        return false;

    for (std::size_t i = 0; i < login_key.size(); ++i)
    {
        if (received[i] != login_key[i])
            return false;
    }
    
    return true;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Example data packet coming from somewhere
    std::vector<std::uint8_t> packet = {0x01, 0x02, 0x03, 0x55, 0xAA};

    if (validate_key(packet))
    {
        std::cout << "Key matched. Processing packet...\n";
    }
    else
    {
        std::cout << "Invalid key. Rejecting packet.\n";
    }

    return 0;
}
