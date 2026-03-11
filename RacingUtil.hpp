#ifndef RACING_UTIL_HPP
#define RACING_UTIL_HPP

int clamp(int target, int min, int max);
int amplify(int target, int fromMin, int fromMax, int toMin, int toMax);

/// NOTE:
/// reserve for future
int differentialCounterWheelMap(int angle, int speed);

#endif
