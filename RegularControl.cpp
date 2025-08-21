#include <Arduino.h>
#include "RegularControl.hpp"

int customV = 0;

void forward(int v) {
  analogWrite(RightMotorH, v);
  analogWrite(RightMotorL, 0);
  analogWrite(LeftMotorH, v);
  analogWrite(LeftMotorL, 0);
}

void backward(int v) {
  analogWrite(RightMotorH, 0);
  analogWrite(RightMotorL, v);
  analogWrite(LeftMotorH, 0);
  analogWrite(LeftMotorL, v);
}

void turnleft(int v) {
  analogWrite(RightMotorH, v);
  analogWrite(RightMotorL, 0);
  analogWrite(LeftMotorH, 0);
  analogWrite(LeftMotorL, v);
}

void turnright(int v) {
  analogWrite(RightMotorH, 0);
  analogWrite(RightMotorL, v);
  analogWrite(LeftMotorH, v);
  analogWrite(LeftMotorL, 0);
}

void stay() {
  analogWrite(RightMotorH, 0);
  analogWrite(RightMotorL, 0);
  analogWrite(LeftMotorH, 0);
  analogWrite(LeftMotorL, 0);
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
