#include <stdio.h>
#include "../RacingUtil.hpp"
#include "../RacingControl.hpp"

int main() {
    for (int angle = -90; angle <= 90; angle++) {
        for (int throttle = 0; throttle <= 100; throttle++) {
            int magnitude = amplify(throttle, 0, 100, 0, MAX_SPEED);
            int right = amplify(clamp(angle, -MAX_ANGLE, 0), -MAX_ANGLE, 0, -magnitude, magnitude);
            printf("%d %d %d %d\n", angle, throttle, right, magnitude - right);
        }
    }
    
    return 0;
}
