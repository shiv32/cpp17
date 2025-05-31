#include <iostream>
#include "../include/PluginInterface.hpp"

class ConvertPlugin : public PluginInterface {
public:
    std::string name() const override {
        return "convert";
    }

    void run(int argc, char* argv[]) override {
        std::cout << "[ConvertPlugin] Converting data...\n";
    }
};

extern "C" PluginInterface* create() {
    return new ConvertPlugin();
}

extern "C" void destroy(PluginInterface* p) {
    delete p;
}
