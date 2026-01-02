#pragma once

#include "Command.h"
#include <memory>
#include <string>

class CommandFactory
{
public:
    static std::unique_ptr<Command> createCommand(const std::string &cmdName);
};
