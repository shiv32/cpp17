#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

namespace BrandConfig
{
    // Centralized brand list
    inline const std::unordered_set<std::string> ValidBrands{"Nike", "Adidas", "Puma", "Reebok"};
    inline const std::string DefaultBrand{"Generic"};
}

std::string resolveBrand(const std::string &input)
{
    if (BrandConfig::ValidBrands.count(input))
        return input;

    return BrandConfig::DefaultBrand;
}

int main()
{
    //std::string brand;

    // while (true)
    // {
    // std::cout << "Enter brand (or exit): ";
    // std::cin >> brand;

    // if (brand == "exit")
    //     break;

    // std::cout << "Resolved brand: "
    //           << resolveBrand(brand) << "\n\n";
    // }

    std::cout << "Resolved brand: " << resolveBrand("Adidas") << "\n";
    std::cout << "Resolved brand: " << resolveBrand("") << "\n";
}
