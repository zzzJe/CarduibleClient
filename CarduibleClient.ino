#include <SoftwareSerial.h>
#include "RegularControl.hpp"
#include "RacingControl.hpp"

SoftwareSerial BT(10, 11); // Bluetooth (RX, TX)

unsigned char btReciving;

void setup() {
  // Freq. in Serial Monitor
  Serial.begin(9600);

  // BT freq.
  // for HC-05 -> 38400
  // for BT-05 -> 9600
  BT.begin(9600);
}

using BtTrans = BtTransferState;

void loop() {
  if (BT.available()) {
    btReciving = (unsigned char)BT.read();
    switch (btTransferState) {
    case BtTrans::Angle:
    case BtTrans::Throttle:
    case BtTrans::Reverse:
      handleRacingControl(btTransferState, btReciving);
      btTransferState = BtTrans::None;
      break;
    case BtTrans::None:
    default:
      switch (btReciving) {
      case BtTrans::Angle:
      case BtTrans::Throttle:
      case BtTrans::Reverse:
        btTransferState = btReciving;
        break;
      default:
        handleRegularControl(btReciving);
        break;
      }
      break;
    }
  }
  if (Serial.available()) {
    btReciving = Serial.read();
    BT.print(btReciving);
  }
}
