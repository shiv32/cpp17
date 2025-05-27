
#include "Context.hpp"
#include "State.hpp"
#include "IdleState.hpp"

Context::Context()
{
    setState(std::make_unique<IdleState>());
}

Context::~Context() = default;

void Context::setState(std::unique_ptr<State> state)
{
    state_ = std::move(state);
}

void Context::request(const std::string &command)
{
    if (state_)
    {
        state_->handle(*this, command);
    }
}
