#define trigPIN 12 // Change to a suitable GPIO pin
#define echoPIN 13 // Change to a suitable GPIO pin

void setup() {
  Serial.begin(115200);
  pinMode(trigPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
}

void loop() {
  // Trigger pulse
  digitalWrite(trigPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPIN, LOW);

  // Read echo pulse duration
  long duration = pulseIn(echoPIN, HIGH, 30000); // 30000 microsecond timeout

  // Calculate distance (in cm)
  float distance_cm = duration * 0.034 / 2;

  // Print distance to serial monitor
  Serial.print("Distance: ");
  if (duration == 0) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance_cm);
    Serial.println(" cm");
  }

  delay(1000); // Wait 1 second before taking the next measurement
}
