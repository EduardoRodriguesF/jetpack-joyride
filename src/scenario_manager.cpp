#include "scenario_manager.h"
#include "constants.h"

ScenarioManager::ScenarioManager() : scene_speed(UNIT) {
    static_shock_list.push_back(StaticShock(WINDOW_WIDTH, 10, WINDOW_WIDTH, 64));
}

void ScenarioManager::update(const float delta_time) {
    for (auto &static_shock : this->static_shock_list) {
        float acc = this->scene_speed * delta_time;

        static_shock.a_edge.x -= acc;
        static_shock.b_edge.x -= acc;

        static_shock.update(delta_time);
    }

    this->scene_speed += SCENE_ACCELERATION;
}

void ScenarioManager::draw(SDL_Renderer *renderer) {
    for (const auto &static_shock : this->static_shock_list) {
        static_shock.draw(renderer);
    }
}
