#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

using json = nlohmann::json;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::string jsonFile{"/home/shiv/Projects/cpp17/nlohmann-json/Project-1/test_file/example.json"};

    json j;

    j["name"] = "Shiv";
    j["age"] = 25;
    j["skills"] = {"C++", "CMake", "Linux"};

    std::cout << j.dump(4) << '\n';

    try
    {
        std::ifstream f(jsonFile);
        json data = json::parse(f);
        std::cout << data.dump(4) << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
