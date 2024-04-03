#pragma once

#include <raylib.h>
#include <map>

using namespace std;

class Player
{
public:
    Player();
    ~Player();

    void update();
    void render();
private:
    //Vectors
    Vector2 pos;
    Vector2 vel;
    Vector2 scale;
    Vector2 size;

    //Rects
    Rectangle src;
    Rectangle dest;

    //Textures
    map<const char*, Texture2D> texture
    {
        {"idle", LoadTexture("res/entity/player/test_idle_spritesheet.png")},
        {"move", LoadTexture("res/entity/player/test_run_spritesheet.png")}
    };
};