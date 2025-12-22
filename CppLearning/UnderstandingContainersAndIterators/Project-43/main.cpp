/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Strings
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "cableCompany.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    CableCompany myCC;

    auto basic_pkg = "1111000000";
    auto premium_pkg = "1111111111";
    auto sports_pkg = "0000100111";

    myCC.addPackage("basic", std::bitset<kNumChannels>(basic_pkg));
    myCC.addPackage("premium", std::bitset<kNumChannels>(premium_pkg));
    myCC.addPackage("sports", std::bitset<kNumChannels>(sports_pkg));

    myCC.newCustomer("shiv", "basic");
    myCC.addPackageToCustomer("shiv", "sports");

    std::cout << myCC.getCustomerChannels("shiv") << std::endl;

    return 0;
}
