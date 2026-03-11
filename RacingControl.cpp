#include <Arduino.h>
#include "RacingControl.hpp"
#include "RacingUtil.hpp"

int angle = 0;
int throttle = 0;
bool reverse = false;

BtTransferState btTransferState = None;

using BtTrans = BtTransferState;

void handleRacingControl(BtTransferState state, unsigned char input) {
  switch (state) {
  case BtTrans::Angle:
    // NOTE:
    // clamp here is redundent b/c operation below use another layer of clamp
    // angle = clamp((int)input, -MAX_ANGLE, MAX_ANGLE) - MAX_ANGLE;
    angle = (int)input - MAX_ANGLE;
    break;
  case BtTrans::Throttle:
    throttle = clamp((int)input, 0, 100);
    break;
  case BtTrans::Reverse:
    reverse = (int)input;
    break;
  }

  if (RACING_LOG) {
    Serial.print("Racing:");
    Serial.println(input);
  }

  // NOTE:
  // +angle: R: 250 | L: 0~90 -> 250~-250
  // -angle: R: 0~-90 -> 250~-250 | L: 250
  // R: angle 90~-90 -> clamp to 0~-90 -> amp to 250~-250
  // L: same as R, but with negative angle input
  int magnitude = amplify(throttle, 0, 100, 0, MAX_SPEED);
  int right = amplify(clamp(angle, -MAX_ANGLE, 0), -MAX_ANGLE, 0, -magnitude, magnitude) * (reverse ? -1 : 1);
  int left = amplify(clamp(-angle, -MAX_ANGLE, 0), -MAX_ANGLE, 0, -magnitude, magnitude) * (reverse ? -1 : 1);

  // NOTE:
  // this is for inertia system, but this requires experiment
  // int counterWheel = differentialCounterWheelMap(angle, magnitude);
  // int right = amplify(clamp(angle, -MAX_ANGLE, 0), -MAX_ANGLE, 0, counterWheel, magnitude) * (reverse ? -1 : 1);
  // int left = amplify(clamp(-angle, -MAX_ANGLE, 0), -MAX_ANGLE, 0, counterWheel, magnitude) * (reverse ? -1 : 1);

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
