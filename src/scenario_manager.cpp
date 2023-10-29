#include "scenario_manager.h"
#include "constants.h"

ScenarioManager::ScenarioManager() : scene_speed(UNIT) {}

void ScenarioManager::update(const float delta_time) {
    for (auto &static_shock : this->static_shock_list) {
        float acc = this->scene_speed * delta_time;

        static_shock.a_edge.x -= acc;
        static_shock.b_edge.x -= acc;

        static_shock.update(delta_time);
    }

    this->scene_speed += SCENE_ACCELERATION;

    this->obstacle_timer -= delta_time;
    if (this->obstacle_timer <= 0) {
        this->obstacle_timer = 1.5f;

        spawn_static_shock();
    }
}

void ScenarioManager::draw(SDL_Renderer *renderer) {
    for (const auto &static_shock : this->static_shock_list) {
        static_shock.draw(renderer);
    }
}

void ScenarioManager::spawn_static_shock() {
    auto pattern = static_cast<StaticShockPattern>(rand() % 4);
    int y = rand() % WINDOW_HEIGHT;
    size_t length = 64 + (rand() % 64);

    if (pattern == StaticShockPattern::DiagonalDown || pattern == StaticShockPattern::StraightVertical) {
        y -= length;
    }

    static_shock_list.push_back(StaticShock(pattern, y, length));
}
