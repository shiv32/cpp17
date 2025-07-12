#include <cstdint>
#include <iostream>
#include <type_traits>

template <typename T> T
add(const T &a, const T &b)
{
    return a + b;
}

// Template version of the xy-coordinate class.
template<typename short_type, typename long_type>
class point
{
  public:
    static_assert(std::is_integral<short_type>::value &&
                  std::is_integral<long_type>::value,
                  "the short and long types must be integral");

    short_type my_x;
    short_type my_y;

    point(const short_type& x = short_type(), const short_type& y = short_type())
        : my_x(x),
          my_y(y)
    {
    }

    long_type squared_euclidean_distance() const
    {
        // Squared Euclidean distance from the origin.
        const long_type x2(long_type(my_x) * my_x);
        const long_type y2(long_type(my_y) * my_y);
        return x2 + y2;
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    const int n = add(1, 2);
    std::clog << "n : " << n << std::endl;

    const float f = add(1.2F, 3.4F);
    std::clog << "f : " << f << std::endl;
    
    const std::string s = add(std::string("abc"), std::string("xyz"));
    std::clog << "s : " << s << std::endl;

    point<std::int16_t, std::int32_t> p{INT16_C(-2129), INT16_C(+5471)};
    const std::int32_t d = p.squared_euclidean_distance();
    std::clog << "d : " << d << std::endl;
    
    return 0;
}
