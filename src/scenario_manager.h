#pragma once

#include "SDL2/SDL.h"
#include <vector>
#include "game_objects/static_shock.h"

struct ScenarioManager {
    ScenarioManager();
    float scene_speed;
    void update(const float delta_time);
    void draw(SDL_Renderer *renderer);
    std::vector<StaticShock> static_shock_list;
};
