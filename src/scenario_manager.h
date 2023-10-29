#pragma once

#include "SDL2/SDL.h"
#include <list>
#include <vector>
#include "game_objects/static_shock.h"
#include "game_objects/rocket.h"

struct ScenarioManager {
    ScenarioManager();
    ScenarioManager(Player *player);
    float scene_speed;
    void update(const float delta_time);
    void draw(SDL_Renderer *renderer);
    std::list<StaticShock> static_shock_list;
    std::list<Rocket> rocket_list;
    Player *player; // TODO: Change strategy

private:
    void spawn_static_shock();
    float obstacle_timer = 1.5f;
};
