#pragma once
#include <string>

namespace hal {

class UART {
public:
    UART(const std::string& name, int baudrate);
    void write(const std::string& msg);
    std::string getName() const;

private:
    std::string uart_name;
    int baud;
};

}
