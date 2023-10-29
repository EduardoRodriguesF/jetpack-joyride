#include "SDL2/SDL.h"

enum StaticShockPattern {
    StraightVertical,
    DiagonalDown,
    DiagonalUp,
    StraightHorizontal,
};

struct StaticShock {
    StaticShock(StaticShockPattern pattern, float y, size_t length);
    SDL_FPoint a_edge;
    SDL_FPoint b_edge;
    void update(const float delta_time);
    void draw(SDL_Renderer *renderer) const;
};
