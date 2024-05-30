#include <Wire.h>
#include <Adafruit_APDS9960.h>

#define SDA_PIN 2
#define SCL_PIN 4
#define INT_PIN 6

Adafruit_APDS9960 apds;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  Serial.println("Starting APDS9960");

  Wire.begin(SDA_PIN, SCL_PIN);

  if (!apds.begin()) {
    Serial.println("Failed to initialize APDS-9960!");
    while (1);
  }
  Serial.println("APDS-9960 initialized!");

  apds.enableProximity(true);
  apds.setProximityInterruptThreshold(0, 175);
  apds.enableProximityInterrupt();

  apds.enableGesture(true);
  apds.enableColor(true);
}

void loop() {
//------------------------ PROXIMITY ------------------------
  if(!digitalRead(INT_PIN)) {
    uint8_t proximity = apds.readProximity();
    Serial.print("Proximity: ");
    Serial.println(proximity);

    apds.clearInterrupt();
  }

//------------------------- GESTURE -------------------------
  uint8_t gesture = apds.readGesture();
  switch (gesture) {
    case APDS9960_UP: Serial.println("Gesture: UP"); break;
    case APDS9960_DOWN: Serial.println("Gesture: DOWN"); break;
    case APDS9960_LEFT: Serial.println("Gesture: LEFT"); break;
    case APDS9960_RIGHT: Serial.println("Gesture: RIGHT"); break;
    default: Serial.println("Gesture: NONE"); break;
  }

//-------------------------- COLOR --------------------------
  uint16_t r, g, b, c;


  apds.getColorData(&r, &g, &b, &c);
  Serial.print("R: "); Serial.print(r); 
  Serial.print(" G: "); Serial.print(g); 
  Serial.print(" B: "); Serial.print(b); 
  Serial.print(" C: "); Serial.println(c);

  delay(1000);
}
