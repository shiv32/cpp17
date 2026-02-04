#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// ---- Abstraction ----
class BrandSource
{
public:
    virtual bool isValid(const std::string &brand) const = 0;
    virtual ~BrandSource() = default;
};

// ---- Concrete implementation ----
class StaticBrandSource : public BrandSource
{
    std::unordered_set<std::string> brands;

public:
    StaticBrandSource() : brands{"Nike", "Adidas", "Puma", "Reebok"}
    {
    }

    bool isValid(const std::string &brand) const override
    {
        return brands.count(brand) > 0;
    }
};

// ---- Client ----
class BrandResolver
{
    const BrandSource &source;
    std::string defaultBrand{"Generic"};

public:
    explicit BrandResolver(const BrandSource &src) : source(src) {}

    std::string resolve(const std::string &brand) const
    {
        return source.isValid(brand) ? brand : defaultBrand;
    }
};

int main()
{
    StaticBrandSource brandSource;
    BrandResolver resolver(brandSource);

    std::cout << resolver.resolve("Nike") << "\n";
    std::cout << resolver.resolve("XYZ") << "\n";
    std::cout << resolver.resolve("") << "\n";
    std::cout << resolver.resolve("Puma") << "\n";
}
