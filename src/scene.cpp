#include "scene.h"
#include "constants.h"

Scene::Scene() : scene_speed(UNIT) {}

void Scene::update(const float delta_time) {
    player.update(delta_time);

    for (auto &static_shock : this->static_shock_list) {
        float acc = this->scene_speed * delta_time;

        static_shock.a_edge.x -= acc;
        static_shock.b_edge.x -= acc;

        static_shock.update(delta_time);
    }

    for (auto &rocket : this->rocket_list) {
        rocket.target_y = player.transform.y;
        rocket.update(delta_time);
    }

    this->scene_speed += SCENE_ACCELERATION;

    this->obstacle_timer -= delta_time;
    if (this->obstacle_timer <= 0) {
        this->obstacle_timer = 1.5f;
        
        int obstacle = rand() % 2;

        switch (obstacle) {
            case 0:
                spawn_static_shock();
                break;
            case 1:
                spawn_rocket();
                break;
        }
    }
}

void Scene::draw(SDL_Renderer *renderer) {
    for (const auto &static_shock : this->static_shock_list) {
        static_shock.draw(renderer);
    }

    for (const auto &rocket : this->rocket_list) {
        rocket.draw(renderer);
    }

    player.draw(renderer);
}

void Scene::spawn_static_shock() {
    auto pattern = static_cast<StaticShockPattern>(rand() % 4);
    int y = rand() % WINDOW_HEIGHT;
    size_t length = 64 + (rand() % 64);

    if (pattern == StaticShockPattern::DiagonalDown || pattern == StaticShockPattern::StraightVertical) {
        y -= length;
    }

    static_shock_list.push_back(StaticShock(pattern, y, length));
}

void Scene::spawn_rocket() {
    rocket_list.push_back(Rocket(player.transform.y));
}
