#include "Wire.h"
#include "AD533X.h"

#define RESOLUTION_BITS 12

AD533X dac(0x0C, RESOLUTION_BITS);
  
void setup() {
  Wire.begin();
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // dac.setOutput(0, 4095);
  // dac.setOutput(1, 4095);
  // while(1) {}
  for (int i = 0; i < (2 << RESOLUTION_BITS); i+=100) {
    Serial.println(i);
    dac.setOutput(0, i);
    dac.setOutput(1, i);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    //
    // Wire.beginTransmission(0x0c);
    // Wire.write(0);
    // Wire.endTransmission();
    // Wire.requestFrom(0x0c, 2);
    // if (Wire.available()) {
    //   Serial.println("read was available. results:");
    //   while (Wire.available()) {
    //     Serial.println(Wire.read());
    //   }
    // } else {
    //   Serial.println("No response from other side on readback.");
    // }
  }
}