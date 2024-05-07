#include <Wire.h>
#include <Adafruit_VEML7700.h>

Adafruit_VEML7700 veml = Adafruit_VEML7700();

bool sensorConnected = false;
void startSensor() {
 if(!veml.begin()) {
    Serial.println("Failed to communicate with VEML7700 sensor.");
    sensorConnected = false;
  }
  Serial.println("Re-established Connection.");
  sensorConnected = true;
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting");
  Serial.println("VEML7700 test");

  startSensor();
  while(!sensorConnected) {
    delay(2000);
    startSensor();
  }
}

void loop() {
  if(!veml.readLux()) {
    Serial.println("Lost connection with VEML7700 sensor.");
    sensorConnected = false;
    while(!sensorConnected) {
      Serial.println("Attempting to re-establish communication with VEML7700 sensor.");
      startSensor();
      delay(2000);
    }
  } else {
    // Read lux value from sensor
    float lux = veml.readLux();

    // Print lux value to serial monitor
    Serial.print("Lux: ");
    Serial.println(lux);

    float white = veml.readWhite();
    Serial.print("White: ");
    Serial.println(white);

    Serial.println();
    Serial.println();

    // Wait for a short delay before reading again
    delay(2000);
  }
}
