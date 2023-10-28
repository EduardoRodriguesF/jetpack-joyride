#pragma once

#include "SDL2/SDL_stdinc.h"
#include <SDL.h>

struct Clock {
    Clock(Uint32 fps);
    Uint32 target_frame_time = 0;
    Uint32 last_tick_time = 0;
    Uint32 delta = 0;
    void tick();
    void lock_remaining() const;
};
