#pragma once

#include "raylib.h"
#include "player.hpp"

class Engine 
{
public:
    Engine();
    ~Engine();
    
    void update();
    void render();
private:
    Player player;
};
