#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>

#define SEALEVELPRESSURE_HPA (1013.25) // Define your local sea level pressure for altitude calculations

Adafruit_BME680 bme; // Create a BME680 object

bool bmeConnection = false;
void  startBME() {
  if(!bme.begin()) {
    Serial.println("Could not find a valid BME688 sensor, check wiring!");
    bmeConnection = false;
  }
  bmeConnection = true;
}

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Starting");
  
  while(!bmeConnection) {
    startBME();
    delay(1000);
  }

  

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320 degree Celsius for 150 ms
}

void loop() {
  if (! bme.performReading()) {
    bmeConnection = false;
    while(!bmeConnection) {
      startBME();
      delay(2000);
    }
  } else {
    Serial.print("Temperature = ");
    Serial.print(bme.temperature);
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bme.pressure / 100.0);
    Serial.println(" hPa");

    Serial.print("Humidity = ");
    Serial.print(bme.humidity);
    Serial.println(" %");

    Serial.print("Gas = ");
    Serial.print(bme.gas_resistance / 1000.0);
    Serial.println(" KOhms");

    Serial.println();

    delay(2000);
  }
}
