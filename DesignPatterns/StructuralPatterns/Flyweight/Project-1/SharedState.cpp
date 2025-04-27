#include "SharedState.hpp"

SharedState::SharedState(const std::string &brand, const std::string &model, const std::string &color)
    : brand_(brand), model_(model), color_(color)
{
}

std::ostream &operator<<(std::ostream &os, const SharedState &ss)
{
    return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
}
