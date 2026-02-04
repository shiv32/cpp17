#include <iostream>
#include <string>
#include <unordered_set>

// -------- Central Brand Registry --------
class BrandRegistry
{
public:
    static const std::unordered_set<std::string> &validBrands()
    {
        static const std::unordered_set<std::string> brands{"Nike", "Adidas", "Puma", "Reebok"};
        return brands;
    }
};

// -------- Specification --------
class BrandSpecification
{
public:
    virtual bool isSatisfiedBy(const std::string &brand) const = 0;
    virtual ~BrandSpecification() = default;
};

class ValidBrandSpecification : public BrandSpecification
{
public:
    bool isSatisfiedBy(const std::string &brand) const override
    {
        const auto &brands = BrandRegistry::validBrands();
        return brands.find(brand) != brands.end();
    }
};

// -------- Resolver --------
class BrandResolver
{
private:
    const BrandSpecification &specification;
    const std::string defaultBrand = "GenericBrand";

public:
    explicit BrandResolver(const BrandSpecification &spec)
        : specification(spec) {}

    std::string resolve(const std::string &inputBrand) const
    {
        return specification.isSatisfiedBy(inputBrand)
                   ? inputBrand
                   : defaultBrand;
    }
};

// -------- Simulation --------
int main()
{
    ValidBrandSpecification spec;
    BrandResolver resolver(spec);

    std::string inputBrand;

    while (true)
    {
        std::cout << "Enter brand (or exit): ";
        std::cin >> inputBrand;

        if (inputBrand == "exit")
            break;

        std::cout << "Using brand: "
                  << resolver.resolve(inputBrand) << "\n";
    }
}
