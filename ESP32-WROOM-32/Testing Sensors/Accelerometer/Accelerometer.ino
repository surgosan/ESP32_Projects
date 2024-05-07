#include <Wire.h>
#include <Adafruit_LIS3DH.h>

Adafruit_LIS3DH lis = Adafruit_LIS3DH();

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!lis.begin()) {
    Serial.println("Could not initialize LIS3DH sensor");
    while (1);
  }
  
  lis.setRange(LIS3DH_RANGE_4_G);
}

void loop() {
  lis.read(); // Read sensor data
  
  Serial.print("X: "); Serial.print(lis.x); // Print X-axis acceleration
  Serial.print(", Y: "); Serial.print(lis.y); // Print Y-axis acceleration
  Serial.print(", Z: "); Serial.println(lis.z); // Print Z-axis acceleration

  delay(500); // Delay between readings
}
