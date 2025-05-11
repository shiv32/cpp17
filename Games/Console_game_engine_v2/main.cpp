#include "engine/Engine.hpp"
#include "game/Game.hpp"

int main() {
    Game game;
    Engine engine(game);
    engine.run();
    return 0;
}
