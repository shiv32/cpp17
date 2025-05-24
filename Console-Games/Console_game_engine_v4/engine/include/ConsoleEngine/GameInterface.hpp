#pragma once

class GameInterface {
public:
    virtual void handleInput(int key) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~GameInterface() = default;
};
