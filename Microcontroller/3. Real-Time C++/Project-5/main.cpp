#include <iostream>
#include <cstdint>

// An unsigned xy-coordinate point with some geometry.
class point
{
    std::uint8_t my_x;
    std::uint8_t my_y;

public:
    // std::uint8_t my_x;
    // std::uint8_t my_y;

    point(const std::uint8_t x = UINT8_C(0),
          const std::uint8_t y = UINT8_C(0))
        : my_x(x), my_y(y)
    {
    }

    std::uint16_t squared_euclidean_distance() const
    {
        // Squared Euclidean distance from the origin.
        const std::uint16_t x2(std::uint16_t(my_x) * my_x);
        const std::uint16_t y2(std::uint16_t(my_y) * my_y);

        return x2 + y2;
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    point p1;
    point p2{UINT8_C(31), UINT8_C(47)};

    // The squared Euclidean distance d1 is 0.
    std::uint16_t d1 = p1.squared_euclidean_distance();
    std::clog << "d1 : " << d1 << std::endl;

    // The squared Euclidean distance d2 is 3,170.
    std::uint16_t d2 = p2.squared_euclidean_distance();
    std::clog << "d2 : " << d2 << std::endl;

    return 0;
}
