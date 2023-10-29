#include "SDL2/SDL.h"
#include "../constants.h"
#include "player.h"

enum class RocketState {
    Aiming,
    Launching,
    Flying,
};

struct Rocket {
    Rocket(float y);
    void update(const float delta_time);
    void draw(SDL_Renderer *renderer) const;

    SDL_FRect transform;
    RocketState state = RocketState::Aiming;
    int launch_threshold_delay = ROCKET_LAUNCH_TIME;
    int maximum_launch_delay = ROCKET_LAUNCH_TIME * 2;
    int launching_delay = 800;
    float target_y;

private:
    void update_aiming(const float delta_time);
    void update_flying(const float delta_time);
    void update_launching(const float delta_time);
};
