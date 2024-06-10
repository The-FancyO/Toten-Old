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
    Image map_col = LoadImage("res/env/map_col.png");
    Texture2D map = LoadTexture("res/env/test.png");

    Player player;
    
    bool color_equal(Color c_1, Color c_2){
        return (
            c_1.r == c_2.r
            && c_1.g == c_2.g
            && c_1.b == c_2.b
            && c_1.a == c_2.a
        );
    }
};
