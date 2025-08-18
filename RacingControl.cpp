#include <Arduino.h>
#include "RacingControl.hpp"

int angle = 0;
int throttle = 0;
bool reverse = false;

int clamp(int target, int min, int max) {
  return target > max
    ? max
    : target < min
    ? min
    : target;
}

int amplify(int target, int fromMin, int fromMax, int toMin, int toMax) {
  float ratio = (float)(target - fromMin) / (fromMax - fromMin);
  float mapping = ratio; // reserve for nonlinear mapping
  return (int)(mapping * (toMax - toMin)) + toMin;
}

void handleRacingControl(char angleInput, char throttleInput, char reverseInput) {
  // NOTE:
  // clamp here is redundent b/c operation below use another layer of clamp
  // angle = clamp((int)angleInput, -MAX_ANGLE, MAX_ANGLE);
  angle = (int)angleInput;
  throttle = clamp((int)throttleInput, 0, 100);
  reverse = (bool)reverseInput;

  if (RACING_LOG) {
    Serial.println("Racing:");
    // angle
    Serial.print(" angle: ");
    Serial.println((int)angleInput);
    // throttle
    Serial.print(" throttle: ");
    Serial.println((int)throttleInput);
    // reverse
    Serial.print(" reverse: ");
    Serial.println(reverse);
  }

  // NOTE:
  // +angle: R: 250 | L: 0~90 -> 250~-250
  // -angle: R: 0~-90 -> 250~-250 | L: 250
  // R: angle 90~-90 -> clamp to 0~-90 -> amp to 250~-250
  // L: same as R, but with negative angle input
  int magnitude = amplify(throttle, 0, 100, 0, MAX_SPEED);
  int right = amplify(clamp(angle, -MAX_ANGLE, 0), -MAX_ANGLE, 0, -magnitude, magnitude);
  int left = amplify(clamp(-angle, -MAX_ANGLE, 0), -MAX_ANGLE, 0, -magnitude, magnitude);

  // NOTE:
  // need to check sign of `left`, `right`
  // for each motor：
  //   +: H1L0
  //   -: H0L1
  if (right < 0) {
    analogWrite(RightMotorH, 0);
    analogWrite(RightMotorL, -right);
  } else {
    analogWrite(RightMotorH, right);
    analogWrite(RightMotorL, 0);
  }
  if (left < 0) {
    analogWrite(LeftMotorH, 0);
    analogWrite(LeftMotorL, -left);
  } else {
    analogWrite(LeftMotorH, left);
    analogWrite(LeftMotorL, 0);
  }
}
