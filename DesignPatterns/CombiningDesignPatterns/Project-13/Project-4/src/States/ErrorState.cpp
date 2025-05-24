#include "States/ErrorState.hpp"
#include "Context.hpp"

ErrorState& ErrorState::instance() {
    static ErrorState inst;
    return inst;
}

void ErrorState::handle(Context& ctx) {
    // Reset to Idle
}

std::string ErrorState::name() const {
    return "Error";
}