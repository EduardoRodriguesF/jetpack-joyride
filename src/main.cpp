#include "constants.h"
#include "clock/clock.h"

int main() {
    Clock clock(FPS);

    while (true) {


        clock.tick();
        clock.lock_remaining();
    }
}
