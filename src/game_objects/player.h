#include "SDL2/SDL.h"
#include "../constants.h"

struct Player {
    Player();

    SDL_FRect transform;
    float y_speed;
    bool flying = false;

    void update(const float delta_time);
    void draw(SDL_Renderer *renderer) const;
};
