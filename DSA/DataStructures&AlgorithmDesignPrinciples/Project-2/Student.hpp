#pragma once

#include <string>
#include <sstream>

// struct student
// {
//     std::string name;
//     int standard;
// };

// std::ostream &operator<<(std::ostream &os, const student &s)
// {
//     return (os << "[Name: " << s.name << ", Standard: " << s.standard << "]");
// }


//------------------------------------------------------------
struct student
{
    std::string name;
    int standard;
};

std::ostream &operator<<(std::ostream &os, const student &s)
{
    return (os << "[Name: " << s.name << ", Standard: " << s.standard << "]");
}