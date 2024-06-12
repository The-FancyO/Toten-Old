#pragma once

#include <raylib.h>
#include <player.hpp>

class Engine {
public:
    Engine();
    ~Engine();
   
    void update();
    void render();

private:
    Image map_col;
    Texture2D map;

    Player player;
};
