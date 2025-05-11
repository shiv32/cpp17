#include "Game.hpp"
#include "ConsoleEngine/Engine.hpp"

int main() {
    Game game;
    Engine engine(game);
    engine.run();
    return 0;
}