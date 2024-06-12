#include <global.hpp>

#include <engine.hpp>

Engine::Engine() {
    map_col = LoadImage("res/env/map_col.png");
    map = LoadTexture("res/env/test.png");
}

Engine::~Engine() {
    UnloadImage(map_col);
}

void Engine::update() {
    player.update();
}

void Engine::render() {
    DrawTextureEx(map, {0,0}, 0.0f, 2.0f, WHITE);

    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            Color pixel = GetImageColor(map_col, x, y);

            if (ColorIsEqual(pixel, BLACK)) {
                DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, RED);
            }
        }
    }

    player.render();
}
