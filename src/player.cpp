#include <player.hpp>

using namespace std;

Player::Player()
{
    current_texture_val = "idle";
    current_texture = texture[current_texture_val].first;

    pos = { (float)GetScreenWidth()/2 - dest.width/2, (float)GetScreenHeight()/2 - dest.height/2 };
    vel = { 5, 5 };
    scale = { 3, 3 };
    size = { (float)current_texture.width/texture[current_texture_val].second, (float)current_texture.height };

    src = {
        0,
        0,
        size.x,
        size.y
    };

    frame_counter = 0;
    current_frame = 0;
    anim_speed = 10;

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

    debug = false;
}

Player::~Player() {}

void Player::update_motion()
{
    is_moving = false;
    is_idle = true;

    // Veritcal
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        is_moving = true;
        is_idle = false;

        pos.y -= (vel.y * GetFrameTime()) * dest.height;
    }
    else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        is_moving = true;
        is_idle = false;

        pos.y += (vel.y * GetFrameTime()) * dest.height;
    }

    // Horizontal
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        is_moving = true;
        is_flipped = true;
        is_idle = false;

        pos.x -= (vel.x * GetFrameTime()) * dest.width;
    }
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        is_moving = true;
        is_flipped = false;
        is_idle = false;

        pos.x += (vel.x * GetFrameTime()) * dest.width;
    }

    if (is_moving)
        current_texture_val = "move";
    else
        current_texture_val = "idle";

    if (is_flipped)
        src.width = -size.x;
    else
        src.width = size.x;
}

void Player::update()
{
    if (IsKeyPressed(KEY_V) && !debug) {
        debug = true;
    }
    else if (IsKeyPressed(KEY_V) && debug) {
        debug = false;
    }

    size = { (float)current_texture.width/texture[current_texture_val].second, (float)current_texture.height };
    src.width = size.x;
    src.height = size.y;

    update_motion();

    current_texture = texture[current_texture_val].first;

    frame_counter++;

    if (frame_counter >= (GetFPS() / anim_speed))
    {
        frame_counter = 0;
        current_frame++;

        if (current_frame > (texture[current_texture_val].second - 1))
        {
            current_frame = 0;
        }
        src.x = (float)current_frame * (float)src.width;
    }

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

void Player::render()
{
    DrawTexturePro(current_texture, src, dest, {dest.width/2,dest.height/2}, 0.0f, WHITE);

    if (debug) {
        DrawRectangleLinesEx(col, 3, RED);
    }
}
