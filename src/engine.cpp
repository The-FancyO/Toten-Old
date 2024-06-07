#include <engine.hpp>

Engine::Engine() {}

Engine::~Engine() {}

void Engine::update() {
    player.update();
}

void Engine::render() {
    player.render();    
}
