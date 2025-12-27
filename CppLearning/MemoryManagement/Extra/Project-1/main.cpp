#include <memory>
#include <iostream>

struct Data
{
    int x = 10;
    int y = 20;
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto spData = std::make_shared<Data>();

    // Aliasing shared_ptr
    // std::shared_ptr<int> spX(spData, &spData->x);
    auto aliasing = std::shared_ptr<int>(spData, &spData->x);

    // std::cout << *spX << '\n'; // 10
    std::cout << *aliasing << '\n'; // 10

    spData.reset(); // Data still alive

    // std::cout << *spX << '\n'; // still valid
    std::cout << *aliasing << '\n'; // 10

    return 1;
}