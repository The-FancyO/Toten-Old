#pragma once

#include <raylib.h>
#include <player.hpp>

class Engine {
public:
    Engine();
    ~Engine();
   
    void update();
    void render();

    Player get_player();

private:
    Image map_col;
    Texture2D map;

    Player player;

    void render_map_col();
};
