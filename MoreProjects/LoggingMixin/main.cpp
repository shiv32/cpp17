/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Logging Mixin
 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>

// Mixin
template <typename Derived>
class LoggerMixin
{
public:
    void log(const std::string &msg) const
    {
        std::cout << "[" << static_cast<const Derived *>(this)->name() << "] " << msg << "\n";
    }
};

// Base class using mixin
class Component : public LoggerMixin<Component>
{
public:
    std::string name() const { return "Component"; }

    void doWork()
    {
        log("Doing some work.");
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Component c;
    c.doWork();

    return 0;
}