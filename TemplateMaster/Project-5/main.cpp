#include <iostream>
#include <type_traits>
#include <stdexcept>

// 🔧 Function templates for basic operations
template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <typename T>
T subtract(T a, T b)
{
    return a - b;
}

template <typename T>
T multiply(T a, T b)
{
    return a * b;
}

template <typename T>
T divide(T a, T b)
{
    if constexpr (std::is_floating_point<T>::value)
    {
        if (b == 0.0)
            throw std::runtime_error("Division by zero");
    }
    else
    {
        if (b == 0)
            throw std::runtime_error("Division by zero");
    }

    return a / b;
}

// 🎯 Class template for generic calculator
template <typename T>
class Calculator
{
public:
    T a, b;

    Calculator(T a, T b) : a(a), b(b) {}

    void showResults()
    {
        std::cout << "Add: " << add(a, b) << '\n';
        std::cout << "Subtract: " << subtract(a, b) << '\n';
        std::cout << "Multiply: " << multiply(a, b) << '\n';

        try
        {
            std::cout << "Divide: " << divide(a, b) << '\n';
        }
        catch (const std::exception &e)
        {
            std::cout << "Divide: Error - " << e.what() << '\n';
        }
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "=== Integer Calculator ===\n";
    Calculator<int> intCalc(10, 5);
    intCalc.showResults();

    std::cout << "\n=== Float Calculator ===\n";
    Calculator<float> floatCalc(10.5f, 3.2f);
    floatCalc.showResults();

    std::cout << "\n=== Division by Zero Test ===\n";
    Calculator<double> errorCalc(7.0, 0.0);
    errorCalc.showResults();

    return 0;
}
