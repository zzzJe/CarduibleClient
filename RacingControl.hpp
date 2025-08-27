#ifndef RACING_CONTROL_HPP
#define RACING_CONTROL_HPP

#include "Pin.hpp"

/// NOTE:
/// toggle logging functionality for racing mode
/// value should be 0 or 1
#define RACING_LOG 0
/// NOTE:
/// speed of racing mode
/// value should be 0 ~ 255
#define MAX_SPEED 250

/// NOTE:
/// change MAX_ANGLE is not recommended
#define MAX_ANGLE 90
#define ABS(a) ((a) < 0 ? -(a) : (a))

extern int angle;
extern int throttle;
extern bool reverse;

enum BtTransferState {
  Angle = (unsigned char)0xF0,
  Throttle = (unsigned char)0xF1,
  Reverse = (unsigned char)0xF2,
  None = (unsigned char)0,
};

extern BtTransferState btTransferState;

void handleRacingControl(BtTransferState state, unsigned char input);

#endif
