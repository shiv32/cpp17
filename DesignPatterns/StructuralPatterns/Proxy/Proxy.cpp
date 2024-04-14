#include "Proxy.hpp"

bool Proxy::CheckAccess() const
{
    // Some real checks should go here.
    std::cout << "Proxy: Checking access prior to firing a real request.\n";
    return true;
}
void Proxy::LogAccess() const
{
    std::cout << "Proxy: Logging the time of request.\n";
}

void Proxy::Request() const
{
    if (this->CheckAccess())
    {
        this->real_subject_->Request();
        this->LogAccess();
    }
}