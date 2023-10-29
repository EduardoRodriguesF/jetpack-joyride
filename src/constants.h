#pragma once

#define FPS 60
constexpr int TARGET_FRAME_TIME = 1000 / FPS;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

constexpr float UNIT = 100.0f;

constexpr float GRAVITY_FORCE = 5.0f * UNIT;

constexpr float MAX_FLY_SPEED = 3.0f * UNIT;
constexpr float MAX_FALL_SPEED = 10.0f * UNIT;
constexpr float FLY_ACCELERATION = 7.0f * UNIT;

constexpr int FLOOR_Y = WINDOW_HEIGHT - 48;

#define SCENE_ACCELERATION 0.001f * UNIT;

#define ROCKET_LAUNCH_TIME 1000
constexpr float ROCKET_SPEED = 5.0f * UNIT;
constexpr float ROCKET_AIM_SPEED = 0.8f * UNIT;
