#include <iostream>

class led_base
{
};

class pwm
{
};

class led_pwm : public led_base
{
    // led_pwm is-a led_base.

private:
    // led_pwm has-a pwm.
    pwm *my_pwm;
};

class led_pwm2 : public led_base
{
    // led_pwm2 is-a led_base.

    // This led_pwm2 uses the use-a relationship to toggle.
    virtual void toggle(pwm *p)
    {
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}
