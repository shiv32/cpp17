#include "Adapter.hpp"

 Adapter::Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}

std::string Adapter::Request() const
{
    std::string to_reverse = this->adaptee_->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
}