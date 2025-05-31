#include <iostream>
#include <filesystem>
#include <dlfcn.h>
#include <vector>
#include <string>
#include "../include/PluginInterface.hpp"

namespace fs = std::filesystem;

struct PluginHandle {
    void* handle = nullptr;
    PluginInterface* instance = nullptr;
};

PluginHandle load_plugin(const std::string& path) {
    PluginHandle ph;
    ph.handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!ph.handle) {
        std::cerr << "Failed to load plugin: " << path << "\n";
        return ph;
    }

    auto create = (PluginInterface* (*)())dlsym(ph.handle, "create");
    if (!create) {
        std::cerr << "Missing create() in plugin: " << path << "\n";
        dlclose(ph.handle);
        ph.handle = nullptr;
        return ph;
    }

    ph.instance = create();
    return ph;
}

void unload_plugin(PluginHandle& ph) {
    if (!ph.handle) return;
    auto destroy = (void(*)(PluginInterface*))dlsym(ph.handle, "destroy");
    if (destroy && ph.instance)
        destroy(ph.instance);
    dlclose(ph.handle);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <command> [args...]\n";
        return 1;
    }

    std::string command = argv[1];
    std::string plugin_path = "../plugins/lib" + command + ".so";

    PluginHandle plugin = load_plugin(plugin_path);
    if (!plugin.instance) {
        std::cerr << "Command not found: " << command << "\n";
        return 1;
    }

    plugin.instance->run(argc - 1, &argv[1]);
    unload_plugin(plugin);
    return 0;
}
