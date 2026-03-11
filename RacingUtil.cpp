#include "RacingUtil.hpp"
#include "RacingControl.hpp"

int clamp(int target, int min, int max) {
  return target > max
    ? max
    : target < min
    ? min
    : target;
}

float amplifyFloat(float target, float fromMin, float fromMax, float toMin, float toMax) {
  float ratio = (target - fromMin) / (fromMax - fromMin);
  float mapping = ratio; // reserve for nonlinear mapping
  return mapping * (toMax - toMin) + toMin;
}

int amplify(int target, int fromMin, int fromMax, int toMin, int toMax) {
  return amplifyFloat(target, fromMin, fromMax, toMin, toMax);
}

/// NOTE:
/// reserve for future mapping
/// to calculate sqrt(x), use `x * qrsqrt(x)`
float qrsqrt(float number) {
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));
  // y  = y * (threehalfs - (x2 * y * y));

	return y;
}

/// NOTE:
/// reserve for future
int differentialCounterWheelMap(int angle, int speed) {
  // b/c of clamp, we only need to focus on -90 ~ 0
  // -90 ~ 0 -> 255 * 0.7 ~ -255
  float ratio = amplifyFloat(angle, -MAX_ANGLE, 0, 0.2, -1);
  // TODO: should test out suitable mapping here
  float mapping = ratio;
  // int sign = ratio > 0 ? 1 : -1;
  return speed * mapping;
}
