#include <iostream>
#include <dlfcn.h>
#include <vector>
#include <string>
#include "../include/PluginInterface.hpp"

PluginInterface *load_plugin(const std::string &path, void *&handle_out)
{
    handle_out = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle_out)
    {
        std::cerr << "Failed to load plugin: " << path << "\n";
        return nullptr;
    }

    auto create = (PluginInterface * (*)()) dlsym(handle_out, "create");
    if (!create)
    {
        std::cerr << "Missing create() in plugin: " << path << "\n";
        dlclose(handle_out);
        return nullptr;
    }

    return create();
}

int main(int argc, char *argv[])
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<std::string> plugin_names;

    // Default plugin
    plugin_names.push_back("default_plugin");

    // Load additional plugins by user input
    for (int i = 1; i < argc; ++i)
    {
        plugin_names.push_back(argv[i]);
    }

    std::vector<void *> handles;
    for (const auto &name : plugin_names)
    {
        std::string path = "../plugins/lib" + name + ".so";
        void *handle = nullptr;
        PluginInterface *plugin = load_plugin(path, handle);
        if (plugin)
        {
            std::cout << "[RUNNING] " << name << "\n";
            plugin->run();

            // Destroy
            auto destroy = (void (*)(PluginInterface *))dlsym(handle, "destroy");
            if (destroy)
                destroy(plugin);
            handles.push_back(handle);
        }
    }

    // Clean up
    for (auto h : handles)
        dlclose(h);

    return 0;
}
