#pragma once
#include <string>

namespace hal
{
    enum class GPIOMode
    {
        INPUT,
        OUTPUT
    };

    class GPIO
    {
    public:
        GPIO(const std::string &name, GPIOMode mode);
        void write(bool value);
        bool read() const;

    private:
        std::string pin_name;
        GPIOMode mode;
        bool state;
    };
}
