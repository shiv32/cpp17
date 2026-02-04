#include <iostream>
#include <string>
#include <unordered_set>

// ---------------- Specification ----------------
class BrandSpecification
{
public:
    virtual bool isSatisfiedBy(const std::string &brand) const = 0;
    virtual ~BrandSpecification() = default;
};

class ValidBrandSpecification : public BrandSpecification
{
private:
    std::unordered_set<std::string> validBrands{"Nike", "Adidas", "Puma", "Reebok"};

public:
    bool isSatisfiedBy(const std::string &brand) const override
    {
        return validBrands.count(brand) > 0;
    }
};

// ---------------- Resolver ----------------
class BrandResolver
{
private:
    const BrandSpecification &specification;
    const std::string defaultBrand = "GenericBrand";

public:
    explicit BrandResolver(const BrandSpecification &spec): specification(spec) 
    {
        
    }

    std::string resolve(const std::string &inputBrand) const
    {
        if (specification.isSatisfiedBy(inputBrand))
        {
            return inputBrand; // valid brand
        }
        return defaultBrand; // fallback brand
    }
};

// ---------------- Simulation ----------------
int main()
{
    ValidBrandSpecification validSpec;
    BrandResolver resolver(validSpec);

    std::string inputBrand;

    while (true)
    {
        std::cout << "Enter brand (or exit): ";
        std::cin >> inputBrand;

        if (inputBrand == "exit")
            break;

        std::string brandToUse = resolver.resolve(inputBrand);

        std::cout << "Using brand: " << brandToUse << "\n";

        // further processing with brandToUse
    }

    return 0;
}
