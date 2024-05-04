#pragma once

#include <player.hpp>
#include <raylib.h>

class Engine {
public:
    Engine();
    ~Engine();

    void update();
    void render();

private:
    Player player;
};
