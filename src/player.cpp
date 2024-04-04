#include <player.hpp>
#include <iostream>

using namespace std;

Player::Player()
{
    current_texture_val = "idle";
    current_texture = get<0>(texture[current_texture_val]);

    frame_counter = 0;

    pos = {30,30};
    vel = {20, 20};
    scale = {3, 3};
    size = {(float)current_texture.width/get<1>(texture[current_texture_val]), (float)current_texture.height};

    src = {
        0,
        0,
        size.x,
        size.y,
    };

    dest = {
        pos.x,
        pos.y,
        size.x * scale.x,
        size.y * scale.y
    };

    col = {
        pos.x - ((size.x * scale.x) / 2),
        pos.y - ((size.y * scale.y) / 2),
        size.x * scale.x,
        size.y * scale.y
    };
}

Player::~Player() {}

void Player::move()
{

}

void Player::update()
{
    frames = get<1>(texture[current_texture_val]);
    anim_speed = 10;

    frame_counter++;

    if (frame_counter >= (60/anim_speed))
    {
        frame_counter = 0;
        current_frame++;

        if (current_frame > get<1>(texture[current_texture_val])-1) current_frame = 0;

        src.x = (float)current_frame*(float)src.width;
    }
}

void Player::render()
{
    DrawTexturePro(current_texture, src, dest, {dest.width/2,dest.height/2}, 0.0f, WHITE);
    // DrawRectangleLinesEx(col, 5, RED);
    // DrawRectangleLinesEx(dest, 3, BLUE);
}