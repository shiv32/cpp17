#include <iostream>
#include <unordered_map>
#include <string>

class Player
{
public:
    int health = 100;
    int mana = 50;

    // Reflection-like map
    std::unordered_map<std::string, int *> properties;

    Player()
    {
        properties["health"] = &health;
        properties["mana"] = &mana;
    }

    void setProperty(const std::string &name, int value)
    {
        if (properties.find(name) != properties.end())
        {
            *properties[name] = value;
        }
    }

    void print()
    {
        std::cout << "Health: " << health << "\n";
        std::cout << "Mana: " << mana << "\n";
    }
};

int main()
{
    Player p;

    p.setProperty("health", 200); // dynamic access
    p.setProperty("mana", 80);

    p.print();
}