#include "game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_error.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_log.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <cstdlib>

Game::Game() : clock(FPS) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(0, "Failed to initialize SDL: %s", SDL_GetError());
        exit(1);
    }

    this->window = SDL_CreateWindow("Jetpack Joyride", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    if (!window) {
        SDL_LogError(0, "Failed to create window: %s", SDL_GetError());
        exit(2);
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_LogError(0, "Failed to create renderer: %s", SDL_GetError());
        exit(3);
    }
}

Game::~Game() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);

    SDL_Quit();
}

void Game::run() {
    while (running) {
        this->handle_input();
        this->update();
        this->draw();

        clock.tick();
        clock.lock_remaining();
    }
}

void Game::handle_input() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                running = false;
                break;
        }
    }
}

void Game::update() {
    float delta_time = clock.delta / 1000.0f;

    player.update(delta_time);
}

void Game::draw() {
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 1);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 1);
    player.draw(renderer);

    SDL_RenderPresent(renderer);
}
