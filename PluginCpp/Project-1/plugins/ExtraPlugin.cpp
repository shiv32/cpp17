#include <iostream>
#include "PluginInterface.hpp"

class ExtraPlugin : public PluginInterface {
public:
    void run() override {
        std::cout << "Extra Plugin running.\n";
    }
};

extern "C" PluginInterface* create() {
    return new ExtraPlugin();
}

extern "C" void destroy(PluginInterface* p) {
    delete p;
}
