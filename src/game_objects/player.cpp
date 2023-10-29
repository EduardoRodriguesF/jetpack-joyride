#include "player.h"
#include "SDL2/SDL_render.h"
#include <algorithm>

Player::Player() : transform({0.0f, FLOOR_Y - 32.0f, 32.0f, 32.0f}) {};

void Player::update(const float delta_time) {
    if (flying) {
        y_speed = std::max(y_speed - FLY_ACCELERATION * delta_time, -MAX_FLY_SPEED);
    } else {
        y_speed = std::min(y_speed + GRAVITY_FORCE * delta_time, MAX_FALL_SPEED);
    }

    transform.y += y_speed * delta_time;

    if (transform.y >= FLOOR_Y) {
        transform.y = FLOOR_Y;
        y_speed = 0;
    }
}

void Player::draw(SDL_Renderer *renderer) const {
    SDL_RenderDrawRectF(renderer, &this->transform);
}
