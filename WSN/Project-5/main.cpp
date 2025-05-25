/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Template Method
 * @version 0.1
 * @date 2025-05-17
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <set>

//Template Method
class IController
{
public:
    static const std::vector<std::string> &getKeys()
    {
        static const std::vector<std::string> keys = {"Name", "Age", "City"};
        return keys;
    }

    virtual std::vector<std::string> getValues() const = 0;

    std::map<std::string, std::string> getData() const
    {
        const auto &keys = getKeys();
        auto values = getValues();

        std::map<std::string, std::string> result;
        for (size_t i = 0; i < keys.size() && i < values.size(); ++i)
        {
            result[keys[i]] = values[i];
        }
        return result;
    }

    virtual ~IController() = default;
};

//subclasses-----------------------------------
class ControllerA : public IController
{
public:
    std::vector<std::string> getValues() const override
    {
        return {"Alice", "25", "New York"};
    }
};

class ControllerB : public IController
{
public:
    std::vector<std::string> getValues() const override
    {
        return {"Bob", "30", "London"};
    }
};

class ControllerC : public IController
{
public:
    std::vector<std::string> getValues() const override
    {
        return {"Carol", "28", "Berlin"};
    }
};
//----------------------------------------------------------------

void displayUnifiedData(const std::vector<std::shared_ptr<IController>> &controllers)
{

    const auto &keys = IController::getKeys();
    std::vector<std::map<std::string, std::string>> allData;

    for (const auto &controller : controllers)
    {
        allData.push_back(controller->getData());
    }

    for (const auto &key : keys)
    {
        std::cout << key << ": ";
        for (const auto &data : allData)
        {
            auto it = data.find(key);
            std::cout << (it != data.end() ? it->second : "N/A") << " | ";
        }
        std::cout << "\n";
    }
}

// ---------- Main ----------
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto controllerC = std::make_shared<ControllerC>();
    auto controllerB = std::make_shared<ControllerB>();
    auto controllerA = std::make_shared<ControllerA>();

    std::vector<std::shared_ptr<IController>> controllers;

    controllers.emplace_back(controllerA);
    controllers.emplace_back(controllerB);
    controllers.emplace_back(controllerC);

    displayUnifiedData(controllers);

    return 0;
}
