#pragma once
#include "Context.hpp"

class ICommand {
public:
    virtual void execute(Context& ctx) = 0;
    virtual ~ICommand() = default;
};

class StartCommand : public ICommand {
public:
    void execute(Context& ctx) override;
};

class PauseCommand : public ICommand {
public:
    void execute(Context& ctx) override;
};

class ResumeCommand : public ICommand {
public:
    void execute(Context& ctx) override;
};

class CompleteCommand : public ICommand {
public:
    void execute(Context& ctx) override;
};

class ErrorCommand : public ICommand {
public:
    void execute(Context& ctx) override;
};

class ResetCommand : public ICommand {
public:
    void execute(Context& ctx) override;
};