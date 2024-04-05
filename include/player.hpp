#pragma once

#include <raylib.h>
#include <map>
#include <tuple>

using namespace std;

class Player
{
public:
    Player();
    ~Player();

    void update();
    void render();

private:
    // Bool
    bool is_moving;
    bool is_idle;
    bool is_flipped;

    // Texture stuff
    const char* current_texture_val;
    Texture2D current_texture;

    map <const char*, pair<Texture2D, int>> texture
    {
        {"idle", {LoadTexture("res/entity/player/test_idle_spritesheet.png"), 6}},
        {"move", {LoadTexture("res/entity/player/test_run_spritesheet.png"), 6}},
        {"test", {LoadTexture("res/entity/player/test.png"), 1}}
    };

    // Vectors
    Vector2 pos;
    Vector2 vel;
    Vector2 scale;
    Vector2 size;

    // Rects
    Rectangle src;
    Rectangle dest;
    Rectangle col;

    // Animation
    int anim_speed;
    int frame_counter;
    int current_frame;

    // Functions
    void update_motion();
};