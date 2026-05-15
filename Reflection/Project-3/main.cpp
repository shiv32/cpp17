#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include <variant>
#include <sstream>
#include <fstream>

using Value = std::variant<int, float, std::string>;

std::string toString(const Value &v)
{
    if (std::holds_alternative<int>(v))
        return std::to_string(std::get<int>(v));
    if (std::holds_alternative<float>(v))
        return std::to_string(std::get<float>(v));
    return std::get<std::string>(v);
}

// ---------------- REFLECTION ----------------
class Reflectable
{
public:
    std::unordered_map<std::string, Value *> properties;
    std::unordered_map<std::string, std::function<void()>> functions;

    void set(const std::string &name, const Value &v)
    {
        if (properties.count(name))
        {
            *properties[name] = v;
        }
    }

    Value get(const std::string &name)
    {
        return *properties[name];
    }

    void call(const std::string &name)
    {
        if (functions.count(name))
        {
            functions[name]();
        }
    }
};

// ---------------- GAME OBJECT ----------------
class Player : public Reflectable
{
public:
    Value health = 100;
    Value mana = 50;

    Player()
    {
        properties["health"] = &health;
        properties["mana"] = &mana;

        functions["heal"] = [this]()
        {
            int h = std::get<int>(health);
            health = h + 10;
            std::cout << "Healed! health=" << std::get<int>(health) << "\n";
        };
    }
};

// ---------------- REGISTRY ----------------
class Registry
{
    std::unordered_map<std::string, Reflectable *> objects;

public:
    void add(const std::string &name, Reflectable *obj)
    {
        objects[name] = obj;
    }

    Reflectable *get(const std::string &name)
    {
        return objects[name];
    }

    auto &all() { return objects; }
};

// ---------------- SERIALIZER ----------------
class Serializer
{
public:
    static void save(Registry &reg, const std::string &file)
    {
        std::ofstream out(file);

        for (auto &[name, obj] : reg.all())
        {
            for (auto &[prop, valPtr] : obj->properties)
            {
                out << name << "." << prop << "=" << toString(*valPtr) << "\n";
            }
        }

        std::cout << "Saved to " << file << "\n";
    }

    static void load(Registry &reg, const std::string &file)
    {
        std::ifstream in(file);
        std::string line;

        while (std::getline(in, line))
        {
            auto eq = line.find('=');
            auto dot = line.find('.');

            std::string objName = line.substr(0, dot);
            std::string prop = line.substr(dot + 1, eq - dot - 1);
            std::string val = line.substr(eq + 1);

            Reflectable *obj = reg.get(objName);

            // naive int parse
            obj->set(prop, std::stoi(val));
        }

        std::cout << "Loaded from " << file << "\n";
    }
};

// ---------------- COMMAND SYSTEM ----------------
class CommandSystem
{
    Registry &registry;

public:
    CommandSystem(Registry &r) : registry(r) {}

    void execute(const std::string &input)
    {
        std::istringstream iss(input);
        std::string cmd;
        iss >> cmd;

        if (cmd == "set")
        {
            std::string path;
            int value;
            iss >> path >> value;

            auto dot = path.find('.');
            auto obj = path.substr(0, dot);
            auto prop = path.substr(dot + 1);

            registry.get(obj)->set(prop, value);
        }
        else if (cmd == "get")
        {
            std::string path;
            iss >> path;

            auto dot = path.find('.');
            auto obj = path.substr(0, dot);
            auto prop = path.substr(dot + 1);

            std::cout << toString(registry.get(obj)->get(prop)) << "\n";
        }
        else if (cmd == "call")
        {
            std::string path;
            iss >> path;

            auto dot = path.find('.');
            auto obj = path.substr(0, dot);
            auto fn = path.substr(dot + 1);

            registry.get(obj)->call(fn);
        }
        else if (cmd == "save")
        {
            std::string file;
            iss >> file;
            Serializer::save(registry, file);
        }
        else if (cmd == "load")
        {
            std::string file;
            iss >> file;
            Serializer::load(registry, file);
        }
    }
};

// ---------------- MAIN ----------------
int main()
{
    Registry registry;
    Player player;

    registry.add("player", &player);

    CommandSystem cmd(registry);

    std::string input;

    std::cout << "Type commands:\n";

    while (true)
    {
        std::getline(std::cin, input);
        cmd.execute(input);
    }
}