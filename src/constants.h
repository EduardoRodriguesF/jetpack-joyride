#pragma once

#define FPS 60
constexpr int TARGET_FRAME_TIME = 1000 / FPS;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

constexpr float UNIT = 100.0f;

constexpr float GRAVITY_FORCE = 6.0f * UNIT;

constexpr float MAX_FLY_SPEED = 10.0f * UNIT;
constexpr float MAX_FALL_SPEED = 10.0f * UNIT;
constexpr float FLY_ACCELERATION = 10.0f * UNIT;
