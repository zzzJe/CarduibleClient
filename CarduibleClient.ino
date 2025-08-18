#include <SoftwareSerial.h>
#include "RegularControl.hpp"
#include "RacingControl.hpp"

SoftwareSerial BT(10, 11); // Bluetooth (RX, TX)

char btReciving; // Recivings from BT
bool racingTranferOngoing = false;

void setup() {
  // Freq. in Serial Monitor
  Serial.begin(9600);

  // BT freq.
  // for HC-05 -> 38400
  // for BT-05 -> 9600
  BT.begin(9600);
}

void loop() {
  if (BT.available()) {
    btReciving = BT.read();
    // Serial.print(btReciving);
  }
  if (Serial.available()) {
    btReciving = Serial.read();
    BT.print(btReciving);
  }

  if (btReciving == 0xFF) {

  } else if (1) {
    // handleRacingControl();
  } else {
    handleRegularControl(btReciving);
  }
}
