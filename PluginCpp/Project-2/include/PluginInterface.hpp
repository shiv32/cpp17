#pragma once
#include <string>

class PluginInterface {
public:
    virtual ~PluginInterface() = default;
    virtual std::string name() const = 0;
    virtual void run(int argc, char* argv[]) = 0;
};

extern "C" PluginInterface* create();
extern "C" void destroy(PluginInterface*);
