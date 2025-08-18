#ifndef RACING_CONTROL_HPP
#define RACING_CONTROL_HPP

#include "Pin.hpp"

#define RACING_LOG 1
#define MAX_SPEED 250
#define MAX_ANGLE 90

extern int angle;
extern int throttle;
extern bool reverse;

void handleRacingControl(char angleInput, char throttleInput, char reverseInput);

#endif
