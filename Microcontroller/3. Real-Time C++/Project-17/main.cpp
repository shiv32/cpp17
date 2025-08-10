#include <iostream>
#include <string>
#include <chrono>
#include <complex>

inline constexpr float operator"" _inch(long double inches)
{
    // the L is a literal suffix in C++ that makes the number a long double literal instead of the default double.
    return static_cast<float>(inches * 0.0254L);
}

inline constexpr float operator"" _foot(long double feet)
{
    return static_cast<float>(feet * 0.294L);
}

inline constexpr float operator"" _yard(long double yards)
{
    return static_cast<float>(yards * 0.9144L);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    constexpr float one_foot = 12.0_inch;         // 0.3048m
    constexpr float basketball_player = 7.0_foot; // 2.058m
    constexpr float football_field = 100.0_yard;  // 91.44m

    std::clog << "one_foot : " << one_foot << std::endl;
    std::clog << "basketball_player : " << basketball_player << std::endl;
    std::clog << "football_field : " << football_field << std::endl;

    using namespace std::string_literals;
    std::string str = "creativity"s;

    std::clog << "str : " << str << std::endl;

    using namespace std::chrono_literals;

    // time_span is 10.
    std::chrono::milliseconds time_span = 10ms;

    std::clog << "time_span : " << time_span.count() << std::endl;

    using namespace std::complex_literals;

    std::complex<float> z = 1.2f + 3.4if;
    std::clog << "z : " << z << std::endl;

    const std::complex<double> z2 = 1.2 + 3.4i;
    // (13.9794,5.42282)
    const std::complex<double> s = std::sin(z2);
    std::clog << "s : " << s << std::endl;

    // (1,1)
    std::complex<double> z3 = 1.0 + 0b0000'0001i;
    std::clog << "z3 : " << z3 << std::endl;

    return 0;
}
