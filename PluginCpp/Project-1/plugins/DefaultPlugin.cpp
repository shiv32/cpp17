#include <iostream>
#include "PluginInterface.hpp"

class DefaultPlugin : public PluginInterface {
public:
    void run() override {
        std::cout << "Default Plugin running.\n";
    }
};

extern "C" PluginInterface* create() {
    return new DefaultPlugin();
}

extern "C" void destroy(PluginInterface* p) {
    delete p;
}
