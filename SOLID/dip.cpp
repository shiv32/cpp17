/*
High-level modules should not depend on low-level modules. Both should depend on abstractions.
Abstractions should not depend on details. Details should depend on abstractions.
*/

#include <iostream>

/*
class LightBulb {
 public:
  void TurnOn() {
    std::cout << "Light bulb on..." << std::endl;
  }

  void TurnOff() {
    std::cout << "Light bulb off..." << std::endl;
  }

};

class ElectricPowerSwitch {
 public:
  ElectricPowerSwitch(LightBulb light_bulb) : light_bulb_{light_bulb}, on_{ false} {}

  void press() {
    if (on_) {
      light_bulb_.TurnOff();
      on_ = false;
    } else {
      light_bulb_.TurnOn();
      on_ = true;
    }
  }

 private:
  LightBulb light_bulb_;
  bool on_;
};
*/

class Switchable
{
public:
    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
    virtual ~Switchable() = default;
};

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

class ElectricPowerSwitch
{
public:
    ElectricPowerSwitch(Switchable &switchable) : switchable_{switchable}, on_{false} {}
    void press()
    {
        if (on_)
        {
            switchable_.TurnOff();
            on_ = false;
        }
        else
        {
            switchable_.TurnOn();
            on_ = true;
        }
    }

private:
    bool on_;
    Switchable &switchable_;
};

int main()
{
    LightBulb light_bulb{};

    ElectricPowerSwitch power_switch{light_bulb};
    power_switch.press();
    power_switch.press();

    Fan fan{};
    ElectricPowerSwitch power_switch2{fan};
    power_switch2.press();
    power_switch2.press();

    return 0;
}
