#include <ql/quantlib.hpp>
#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    QuantLib::Date today(15, QuantLib::June, 2025);
    QuantLib::Settings::instance().evaluationDate() = today;

    QuantLib::Calendar calendar = QuantLib::TARGET();
    QuantLib::Date settlement = calendar.advance(today, 2, QuantLib::Days);

    std::cout << "Settlement Date: " << settlement << std::endl;
    return 0;
}