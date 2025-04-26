#include "Facade.hpp"
#include "Subsystem1.hpp"
#include "Subsystem2.hpp"

Facade::Facade(Subsystem1 *subsystem1, Subsystem2 *subsystem2)
{
    this->subsystem1_ = subsystem1 ?: new Subsystem1;
    this->subsystem2_ = subsystem2 ?: new Subsystem2;
}

Facade::~Facade()
{
    // in case of smart ptr no need it
    // delete subsystem1_;
    // delete subsystem2_;
}

std::string Facade::Operation()
{
    std::string result = "Facade initializes subsystems:\n";
    result += this->subsystem1_->Operation1();
    result += this->subsystem2_->Operation1();

    result += "Facade orders subsystems to perform the action:\n";
    result += this->subsystem1_->OperationN();
    result += this->subsystem2_->OperationZ();

    return result;
}
