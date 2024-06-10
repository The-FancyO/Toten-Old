#include <engine.hpp>
#include <raylib.h>

Engine::Engine() {}

Engine::~Engine() {
}

void Engine::update() {
    player.update();
}

void Engine::render() {
    DrawTextureEx(map, {0,0}, 0.0f, 2.0f, WHITE);

    for (int x = 0; x < 40; x++)
	{
		for (int y = 0; y < 40; y++)
		{
			Color pixel = GetImageColor(map_col, x, y);

			if (color_equal(pixel, BLACK))
			{
                DrawRectangle(32 * x, 32 * y, 32, 32, BLACK);
			}
		}
	}

    player.render();
}
