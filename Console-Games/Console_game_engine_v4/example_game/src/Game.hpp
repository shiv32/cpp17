#pragma once
#include "Player.hpp"
#include "Map.hpp"
#include "../ui/UIManager.hpp"
#include "ConsoleEngine/GameInterface.hpp"

class Game : public GameInterface
{
public:
    Game();
    void handleInput(int key) override;
    void update() override;
    void render() override;
    ~Game() override = default;

private:
    Player player_;
    Map map_;
    UIManager ui_;
};