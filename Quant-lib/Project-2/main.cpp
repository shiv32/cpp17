#include <ql/quantlib.hpp>
#include <iostream>
#include <memory>

using namespace QuantLib;
using namespace std;

// Interface for Bonds
class BondInterface
{
public:
    virtual boost::shared_ptr<Bond> getQLBond() const = 0;
    virtual boost::shared_ptr<YieldTermStructure> getYieldCurve() const = 0;
    virtual ~BondInterface() = default;
};

// Concrete Bond implementation
class FixedRateBondWrapper : public BondInterface
{
    boost::shared_ptr<FixedRateBond> bond_;
    boost::shared_ptr<YieldTermStructure> curve_;

public:
    FixedRateBondWrapper()
    {
        Calendar calendar = TARGET();
        Date settlementDate(15, June, 2025);
        Settings::instance().evaluationDate() = settlementDate;

        Date issueDate(15, June, 2020);
        Date maturity(15, June, 2030);

        bond_ = boost::make_shared<FixedRateBond>(
            3,      // settlement days
            1000.0, // face value
            Schedule(issueDate, maturity, Period(Annual), calendar,
                     Unadjusted, Unadjusted, DateGeneration::Backward, false),
            std::vector<Rate>{0.05}, // 5% coupon
            ActualActual(ActualActual::Bond),
            Unadjusted,
            100.0, // redemption
            issueDate);

        curve_ = boost::make_shared<FlatForward>(
            settlementDate, 0.04, ActualActual(ActualActual::Bond), Compounded, Annual);
    }

    boost::shared_ptr<Bond> getQLBond() const override { return bond_; }
    boost::shared_ptr<YieldTermStructure> getYieldCurve() const override { return curve_; }
};

// Pricing Strategy Interface
class PricingStrategy
{
public:
    virtual double calculatePrice(const BondInterface &bond) const = 0;
    virtual ~PricingStrategy() = default;
};

// Concrete Strategy: Discounting
class DiscountingStrategy : public PricingStrategy
{
public:
    double calculatePrice(const BondInterface &bond) const override
    {
        return BondFunctions::cleanPrice(
            *bond.getQLBond(),
            bond.getYieldCurve(),
            0.0, // zSpread
            ActualActual(ActualActual::Bond),
            Compounded,
            Annual,
            Settings::instance().evaluationDate());
    }
};

// Pricing context (strategy user)
class BondPricer
{
    unique_ptr<PricingStrategy> strategy_;

public:
    void setStrategy(unique_ptr<PricingStrategy> strategy)
    {
        strategy_ = std::move(strategy);
    }

    double getPrice(const BondInterface &bond) const
    {
        if (!strategy_)
            throw runtime_error("No strategy set");
        return strategy_->calculatePrice(bond);
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    try
    {
        FixedRateBondWrapper bond;
        BondPricer pricer;

        pricer.setStrategy(make_unique<DiscountingStrategy>());

        double price = pricer.getPrice(bond);
        cout << "Bond Clean Price: " << price << endl;
    }
    catch (const std::exception &ex)
    {
        cerr << "Exception: " << ex.what() << endl;
    }

    return 0;
}
