#pragma once
#include <string>
#include "Context.hpp"

class InputHandler {
protected:
    InputHandler* next = nullptr;

public:
    virtual ~InputHandler() = default;
    void setNext(InputHandler* handler) { next = handler; }
    virtual bool handle(const std::string& input, Context& ctx);
};