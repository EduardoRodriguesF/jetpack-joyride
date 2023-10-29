#include "rocket.h"
#include "SDL2/SDL_render.h"
#include <valarray>

Rocket::Rocket(Player *target, float y) : target(target), transform({WINDOW_WIDTH - 32.0f, y, 32.0f, 32.0f}) {}

void Rocket::update(const float delta_time) {
    switch (state) {
        case RocketState::Aiming:
            update_aiming(delta_time);
            break;
        case RocketState::Launching:
            update_launching(delta_time);
            break;
        case RocketState::Flying:
            update_flying(delta_time);
            break;
    }
}

void Rocket::update_aiming(const float delta_time) {
    this->maximum_launch_delay -= delta_time * 1000;
    this->launch_threshold_delay -= delta_time * 1000;

    if (!target) {
        if (launch_threshold_delay <= 0) {
            state = RocketState::Launching;
        }

        return;
    };

    float diff = target->transform.y - this->transform.y;

    if (std::abs(diff) <= 16) {
        // Close enough, do not move
        if (launch_threshold_delay <= 0) {
            state = RocketState::Launching;
        }

        return;
    }

    int direction = (diff > 0) - (diff < 0); // Resolves -1 or 1 based on the target's relative direction
    transform.y += ROCKET_AIM_SPEED * direction * delta_time;

    if (maximum_launch_delay <= 0) {
        state = RocketState::Launching;
    }
}

void Rocket::update_flying(const float delta_time) {
    transform.x -= ROCKET_SPEED * delta_time;
}

void Rocket::update_launching(const float delta_time) {
    launching_delay -= delta_time * 1000;

    if (launching_delay <= 0) {
        state = RocketState::Flying;
    }
}

void Rocket::draw(SDL_Renderer *renderer) const {
    SDL_RenderDrawRectF(renderer, &this->transform);
}
