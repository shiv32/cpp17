#include <iostream>
#include "maths/maths.h"
#include "logger/logger.h"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int result = add(10, 20);

    logMessage("Addition complete");

    std::cout << "Result: " << result << std::endl;

    return 0;
}
