#include "UniqueState.hpp"

UniqueState::UniqueState(const std::string &owner, const std::string &plates)
    : owner_(owner), plates_(plates)
{
}

std::ostream &operator<<(std::ostream &os, const UniqueState &us)
{
    return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
}
