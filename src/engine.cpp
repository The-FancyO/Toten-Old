#include <global.hpp>

#include <engine.hpp>
#include <raylib.h>

Engine::Engine() {
    map_col = LoadImage("res/env/map_col.png");
    map = LoadTexture("res/env/test.png");
}

Engine::~Engine() {
    UnloadImage(map_col);
}

void Engine::render_map_col() {
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            Color pixel = GetImageColor(map_col, x, y);

            if (ColorIsEqual(pixel, BLACK)) {
                tile = {x * (float)CELL_SIZE, y * (float)CELL_SIZE, CELL_SIZE, CELL_SIZE};
                
                if (CheckCollisionRecs(player.col, tile)) {
                    player.set_pos_x(player.old_pos.x);
                    player.set_pos_y(player.old_pos.y);
                }

                if (player.debug) {
                    DrawRectangleRec(tile, BLUE);
                }
            }
        }
    }
}

void Engine::update() {
    player.update();
}

void Engine::render() {
    DrawTextureEx(map, {0,0}, 0.0f, 3.0f, WHITE);

    render_map_col();
    
    player.render();
}

Player Engine::get_player() {
    return player;
}
