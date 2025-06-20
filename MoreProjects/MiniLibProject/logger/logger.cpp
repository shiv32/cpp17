#include <iostream>
#include "logger.h"

void logMessage(const char* msg) {
    std::cout << "[LOG]: " << msg << std::endl;
}
