#pragma once

#include <map>
#include <raylib.h>
#include <raymath.h>

using namespace std;

class Player {
public:
    Player();
    ~Player();

    void update();
    void render();

    // Collider
    Rectangle col;

    Vector2 old_pos;

    // Camera
    Camera2D cam;

    bool debug; // debugging
    
    Vector2 get_pos();
    void set_pos_x(float value);
    void set_pos_y(float value);

    Vector2 get_vel();
    void set_vel_x(float value);
    void set_vel_y(float value);

private:
    // Bool
    bool is_moving;
    bool is_idle;
    bool is_flipped;

    // Texture stuff
    const char *current_texture_val;
    Texture2D current_texture;

    map<const char *, pair<Texture2D, int>> texture{
        {"idle", {LoadTexture("res/entity/player/test_idle_spritesheet.png"), 6}},
        {"move", {LoadTexture("res/entity/player/test_run_spritesheet.png"), 6}},
        {"test", {LoadTexture("res/entity/player/test.png"), 1}}
    };

    // Vectors
    Vector2 pos;
    Vector2 vel; 
    Vector2 size;
    Vector2 scale;

    // Rects
    Rectangle src;
    Rectangle dest;

    // Animation
    int anim_speed;
    int frame_counter;
    int current_frame;

    // Functions
    void update_motion();
    void update_cam();
};
