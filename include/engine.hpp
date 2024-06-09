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
    Image map_col = LoadImage("res/env/map.png");

    Player player;
};
