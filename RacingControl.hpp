#ifndef RACING_CONTROL_HPP
#define RACING_CONTROL_HPP

#include "Pin.hpp"

#define ABS(a) ((a) < 0 ? -(a) : (a))
#define RACING_LOG 1
#define MAX_SPEED 250
#define MAX_ANGLE 90

extern int angle;
extern int throttle;
extern bool reverse;

enum BtTransferState {
  Angle = 0xF0,
  Throttle = 0xF1,
  Reverse = 0xF2,
  None,
};

extern BtTransferState btTransferState;

void handleRacingControl(BtTransferState state, char input);

#endif
