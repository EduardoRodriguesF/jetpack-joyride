#include "static_shock.h"
#include "../constants.h"
#include "SDL2/SDL_render.h"

StaticShock::StaticShock(StaticShockPattern pattern, float y, size_t length) : a_edge({WINDOW_WIDTH,y}), b_edge({WINDOW_WIDTH,y}) {
    switch (pattern) {
        case StraightVertical:
            this->b_edge.y += length;
            break;
        case StraightHorizontal:
            this->b_edge.x += length;
            break;
        case DiagonalDown:
            this->b_edge.x += length;
            this->b_edge.y += length;
            break;
        case DiagonalUp:
            this->b_edge.x += length;
            this->b_edge.y -= length;
    }
}

void StaticShock::update(const float delta_time) {}

void StaticShock::draw(SDL_Renderer *renderer) const {
    SDL_RenderDrawLine(renderer, a_edge.x, a_edge.y, b_edge.x, b_edge.y);
}
