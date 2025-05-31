// plugins/NewPlugin.cpp
#include <iostream>
#include "PluginInterface.hpp"

class NewPlugin : public PluginInterface {
public:
    void run() override {
        std::cout << "New Plugin is running!\n";
    }
};

extern "C" PluginInterface* create() {
    return new NewPlugin();
}

extern "C" void destroy(PluginInterface* p) {
    delete p;
}
