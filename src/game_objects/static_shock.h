#include "SDL2/SDL.h"

struct StaticShock {
    StaticShock(float x1, float y1, float x2, float y2);
    SDL_FPoint a_edge;
    SDL_FPoint b_edge;
    void update(const float delta_time);
    void draw(SDL_Renderer *renderer) const;
};
