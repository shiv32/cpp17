#include <iostream>
#include <charconv>

using namespace std;

int main()
{
    std::string out(10, ' ');  // make string of size 10 filled with spaces
    //std::string out(10, 'k');  // make string of size 10 filled with k

    std::cout << out.size() << '\n';

    std::cout << out.data() << '\n';

    std::cout << out.data() + 9 << '\n';

    std::cout << out.data() + out.size() << '\n';

    auto result = std::to_chars(out.data(), out.data() + out.size(), 1234512345);

    if (result.ec == std::errc())
    {
        /* Conversion successful. */

        std::cout << "Converted string: "
                  << std::string(out.data(), result.ptr) << '\n';

        std::cout << "Converted string: "
                  << std::string(out.data(), result.ptr - 4) << '\n';

        //std::cout << result.ptr << '\n';

        // std::cout << out.data() << '\n';

        // std::cout << out.data() + out.size() << '\n';
    }

    return 0;
}