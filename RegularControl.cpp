#include <Arduino.h>
#include "RegularControl.hpp"

int customV = 0;

void forward(int v) {
  analogWrite(RightMotorH, 0);
  analogWrite(LeftMotorH, 0);
  analogWrite(RightMotorL, v);
  analogWrite(LeftMotorL, v);
}

void backward(int v) {
  analogWrite(RightMotorL, 0);
  analogWrite(LeftMotorL, 0);
  analogWrite(RightMotorH, v);
  analogWrite(LeftMotorH, v);
}

void turnleft(int v) {
  analogWrite(LeftMotorL, v);
  analogWrite(RightMotorL, 0);
  analogWrite(RightMotorH, v);
  analogWrite(LeftMotorH, 0);
}

void turnright(int v) {
  analogWrite(RightMotorL, v);
  analogWrite(LeftMotorL, 0);
  analogWrite(RightMotorH, 0);
  analogWrite(LeftMotorH, v);
}

void stay() {
  analogWrite(RightMotorH, 0);
  analogWrite(RightMotorL, 0);
  analogWrite(LeftMotorL, 0);
  analogWrite(LeftMotorH, 0);
}

void handleRegularControl(char directive) {
  if (REGULAR_LOG) {
    Serial.print("Regular: ");
    Serial.println(directive);
  }

  switch (directive) {
  case 'w':
    forward(DEFAULT_V);
    break;
  case '0':
    stay();
    break;
  case 'a':
    turnleft(DEFAULT_V);
    break;
  case 'd':
    turnright(DEFAULT_V);
    break;
  case 's':
    backward(DEFAULT_V);
    break;
  default:
    stay();
    break;
  }
}
