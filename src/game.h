#pragma once

#include "SDL2/SDL.h"
#include "clock/clock.h"
#include "game_objects/player.h"
#include "scene.h"

class Game {
public:
    Game();
    ~Game();
    void setup();
    void run();
    void handle_input();
    void update();
    void draw();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Clock clock;
    bool running = true;
    Scene scene;
};
