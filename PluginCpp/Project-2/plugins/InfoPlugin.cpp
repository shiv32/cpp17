#include <iostream>
#include "../include/PluginInterface.hpp"

class InfoPlugin : public PluginInterface {
public:
    std::string name() const override {
        return "Info";
    }

    void run(int argc, char* argv[]) override {
         std::cout << "Usage: " << argv[0] << " <command> [args...]\n";
    }
};

extern "C" PluginInterface* create() {
    return new InfoPlugin();
}

extern "C" void destroy(PluginInterface* p) {
    delete p;
}
