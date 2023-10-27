#include "SDL2/SDL.h"
#include "../constants.h"

#define MAX_FLY_SPEED 10.0f
#define MAX_FALL_SPEED 10.0f
#define FLY_ACCELERATION 5.0f

struct Player {
    Player();

    SDL_FRect transform;
    float y_speed;
    bool flying = false;

    void update(float delta_time);
    void draw(SDL_Renderer *renderer) const;
};
