#ifndef PLUGIN_INTERFACE_HPP
#define PLUGIN_INTERFACE_HPP

class PluginInterface {
public:
    virtual void run() = 0;
    virtual ~PluginInterface() = default;
};

// C-style symbols to be loaded dynamically
extern "C" {
    PluginInterface* create();
    void destroy(PluginInterface* p);
}

#endif // PLUGIN_INTERFACE_HPP
