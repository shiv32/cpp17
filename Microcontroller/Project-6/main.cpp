/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Pulse Width Modulation (PWM) simulation
 * @version 0.1
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm> // For std::max and std::min

// C++ 11
//  class PWM
//  {
//  public:
//      PWM(int pin, int frequency) : pin(pin), frequency(frequency)
//      {
//          // Set up PWM parameters (in this case, just print to console)
//      }

//     void setDutyCycle(int dutyCycle)
//     {
//         // Clamp the duty cycle to be within the valid range (0 to 100)
//         dutyCycle = std::max(0, std::min(dutyCycle, 100));
//         this->dutyCycle = dutyCycle;
//     }

//     void simulate()
//     {
//         // Simulate a PWM signal by printing "HIGH" or "LOW" based on the duty cycle
//         auto highTime = std::chrono::milliseconds((dutyCycle * 1000) / frequency);      // Time spent on HIGH
//         auto lowTime = std::chrono::milliseconds((100 - dutyCycle) * 1000 / frequency); // Time spent on LOW

//         std::cout << "Simulating PWM on pin " << pin << " with "
//                   << dutyCycle << "% duty cycle at " << frequency
//                   << "Hz.\n";

//         while (true)
//         {
//             // "HIGH" signal
//             std::cout << "HIGH\n";
//             std::this_thread::sleep_for(highTime);

//             // "LOW" signal
//             std::cout << "LOW\n";
//             std::this_thread::sleep_for(lowTime);
//         }
//     }

// private:
//     int pin;
//     int frequency;
//     int dutyCycle;
// };

// C++17
class PWM
{
public:
    PWM(int pin, int frequency) : pin(pin), frequency(frequency)
    {
        // Set up PWM parameters (in this case, just print to console)
    }

    void setDutyCycle(int dutyCycle)
    {
        // Clamp the duty cycle to be within the valid range (0 to 100)
        dutyCycle = std::max(0, std::min(dutyCycle, 100));
        this->dutyCycle = dutyCycle;
    }

    void simulate() const
    {
        // Simulate a PWM signal by printing "HIGH" or "LOW" based on the duty cycle
        auto highTime = std::chrono::milliseconds((dutyCycle * 1000) / frequency);      // Time spent on HIGH
        auto lowTime = std::chrono::milliseconds((100 - dutyCycle) * 1000 / frequency); // Time spent on LOW

        std::cout << "Simulating PWM on pin " << pin << " with "
                  << dutyCycle << "% duty cycle at " << frequency
                  << "Hz.\n";

        // Use very short sleep time for fast printing
        const auto fastDelay = std::chrono::milliseconds(1000); // 1s for fast printing

        while (true)
        {
            // "HIGH" signal
            std::cout << "HIGH\n";
            // std::this_thread::sleep_for(highTime);
            std::this_thread::sleep_for(fastDelay);

            // "LOW" signal
            std::cout << "LOW\n";
            // std::this_thread::sleep_for(lowTime);
            std::this_thread::sleep_for(fastDelay);
        }
    }

private:
    int pin;
    int frequency;
    int dutyCycle;
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Simulate PWM on pin 9 with a frequency of 1 Hz and a duty cycle of 50%
    PWM pwm(9, 1);        // 1 Hz frequency
    pwm.setDutyCycle(50); // 50% duty cycle
    pwm.simulate();       // Start the simulation

    return 0;
}