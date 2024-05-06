#include <Wire.h>
/* 
PIN SETUP (ESP to BME):
ESP32 3.3V (3V3) -> BME688 VIN
ESP32 GND -> BME688 GND
ESP32 D22 (SCL) -> BME688 SCK
ESP32 D21 (SDA) -> BME688 SDI
*/
void setup() {
  Wire.begin();

  Serial.begin(9600);
  while (!Serial);

  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int deviceCount = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Found device at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      deviceCount++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (deviceCount == 0) {
    Serial.println("No I2C devices found.");
  }

  delay(5000); // Wait 5 seconds before scanning again
}
