#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

class Reflectable
{
protected:
    std::unordered_map<std::string, void *> properties;
    std::unordered_map<std::string, std::function<void()>> functions;

public:
    // Property setter (int only for simplicity)
    void set(const std::string &name, int value)
    {
        if (properties.count(name))
        {
            *static_cast<int *>(properties[name]) = value;
        }
    }

    void print(const std::string &name)
    {
        if (properties.count(name))
        {
            std::cout << name << " = "
                      << *static_cast<int *>(properties[name]) << "\n";
        }
    }

    void call(const std::string &name)
    {
        if (functions.count(name))
        {
            functions[name]();
        }
    }
};

class Player : public Reflectable
{
public:
    int health = 100;
    int mana = 50;

    Player()
    {
        // Register properties
        properties["health"] = &health;
        properties["mana"] = &mana;

        // Register functions
        functions["printStats"] = [this]()
        {
            std::cout << "Health: " << health
                      << ", Mana: " << mana << "\n";
        };

        functions["heal"] = [this]()
        {
            health += 10;
            std::cout << "Healed! Health = " << health << "\n";
        };
    }
};

int main()
{
    Player p;

    // Modify via reflection
    p.set("health", 200);
    p.set("mana", 75);

    // Read via reflection
    p.print("health");
    p.print("mana");

    // Call functions dynamically
    p.call("printStats");
    p.call("heal");
    p.call("printStats");
}