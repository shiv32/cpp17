#include "Proxy.hpp"

Proxy::Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject))
{
}

Proxy::~Proxy()
{
    delete real_subject_;
}

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