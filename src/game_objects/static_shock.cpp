#include "static_shock.h"
#include "SDL2/SDL_render.h"

StaticShock::StaticShock(float x1, float y1, float x2, float y2) : a_edge({x1, y1}), b_edge({x2, y2}) {}

void StaticShock::update(const float delta_time) {
}

void StaticShock::draw(SDL_Renderer *renderer) const {
    SDL_RenderDrawLine(renderer, a_edge.x, a_edge.y, b_edge.x, b_edge.y);
}
