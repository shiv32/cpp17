#include <CLI/CLI.hpp>
#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
    CLI::App app{"Greeting CLI App"};

    std::string name;
    int repeat = 1;
    bool shout = false;

    app.add_option("-n,--name", name, "Name to greet")->required();
    app.add_option("-r,--repeat", repeat, "Number of times to repeat greeting");
    app.add_flag("-s,--shout", shout, "Shout the greeting");

    CLI11_PARSE(app, argc, argv);

    for (int i = 0; i < repeat; ++i) {
        std::string greeting = "Hello, " + name + "!";
        if (shout) {
            std::transform(greeting.begin(), greeting.end(), greeting.begin(), ::toupper);
        }
        std::cout << greeting << std::endl;
    }

    return 0;
}
