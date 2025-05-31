#include <iostream>
#include "../include/PluginInterface.hpp"

class ExportPlugin : public PluginInterface {
public:
    std::string name() const override {
        return "export";
    }

    void run(int argc, char* argv[]) override {
        std::cout << "[ExportPlugin] Exporting data...\n";
    }
};

extern "C" PluginInterface* create() {
    return new ExportPlugin();
}

extern "C" void destroy(PluginInterface* p) {
    delete p;
}
