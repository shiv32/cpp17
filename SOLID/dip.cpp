/*
    Dependency Inversion/Injection
        High-level modules should not depend on low-level modules.
        Both should depend on abstractions.
        Abstractions should not depend on details.
        Details should depend on abstractions.

        High-level modules
            It uses an abstraction to interact with different methods without
            knowing their specific implementations.

        Abstraction
            An abstract class.

        Details/Low-level modules
            Concrete implementations of the abstract class.

        g++ dip.cpp -o test && ./test && rm test
*/

#include <iostream>
#include <memory>

/*

    //Violate dip

    //Low-level module
    class LightBulb
    {
    public:
    void TurnOn()
        {
        std::cout << "Light bulb on..." << std::endl;
        }

    void TurnOff()
        {
        std::cout << "Light bulb off..." << std::endl;
        }
    };

    //High-level module(ElectricPowerSwitch class) depend on low-level module(LightBulb class)
    class ElectricPowerSwitch
    {
    public:
    ElectricPowerSwitch(LightBulb light_bulb) : light_bulb_{light_bulb}, on_{ false} {}

    void press()
    {
        if (on_)
        {
        light_bulb_.TurnOff();
        on_ = false;
        }
        else
        {
        light_bulb_.TurnOn();
        on_ = true;
        }
    }

    private:
    LightBulb light_bulb_;
    bool on_;
    };

*/

// Abstractions
class Switchable
{
public:
    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
    virtual ~Switchable() = default;
};

// Details/low-level modules
class LightBulb final : public Switchable
{
    void TurnOn() override
    {
        std::cout << "Turn on light bulb" << std::endl;
    }

    void TurnOff() override
    {
        std::cout << "Turn off light bulb" << std::endl;
    }
};

// Details/low-level modules
class Fan final : public Switchable
{
    void TurnOn() override
    {
        std::cout << "Turn on fan" << std::endl;
    }

    void TurnOff() override
    {
        std::cout << "Turn off fan" << std::endl;
    }
};

// // High-level module(ElectricPowerSwitch class) depending on abstraction(Switchable class)
// class ElectricPowerSwitch
// {
// public:
//     ElectricPowerSwitch(Switchable &switchable) : switchable_{switchable}, on_{false} {}

//     void press()
//     {
//         if (on_)
//         {
//             switchable_.TurnOff();
//             on_ = false;
//         }
//         else
//         {
//             switchable_.TurnOn();
//             on_ = true;
//         }
//     }

// private:
//     bool on_;
//     Switchable &switchable_;
// };

// using smart pointer
// High-level module(ElectricPowerSwitch class) depending on abstraction(Switchable class)
class ElectricPowerSwitch
{
public:
    ElectricPowerSwitch(std::unique_ptr<Switchable> switchable) : switchable_{std::move(switchable)}, on_{false}
    {
    }

    void press()
    {
        if (on_)
        {
            switchable_->TurnOff();
            on_ = false;
        }
        else
        {
            switchable_->TurnOn();
            on_ = true;
        }
    }

private:
    bool on_;
    std::unique_ptr<Switchable> switchable_{nullptr};
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // LightBulb light_bulb{};
    // ElectricPowerSwitch power_switch_bulb{light_bulb};
    // power_switch_bulb.press();
    // power_switch_bulb.press();

    // Fan fan{};
    // ElectricPowerSwitch power_switch_fan{fan};
    // power_switch_fan.press();
    // power_switch_fan.press();

    //------------(smart pointer)---------------------------------------

    auto light_bulb = std::make_unique<LightBulb>();
    auto power_switch_bulb = std::make_unique<ElectricPowerSwitch>(std::move(light_bulb));
    power_switch_bulb->press();
    power_switch_bulb->press();

    auto fan = std::make_unique<Fan>();
    auto power_switch_fan = std::make_unique<ElectricPowerSwitch>(std::move(fan));
    power_switch_fan->press();
    power_switch_fan->press();

    return 0;
}
