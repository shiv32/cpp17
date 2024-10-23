#include "State.hpp"

State::~State() {}

void State::set_context(Context *context) { this->context_ = context; }