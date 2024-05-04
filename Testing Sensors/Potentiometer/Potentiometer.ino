const int potPin = 4; // Analog pin connected to the potentiometer

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read the value from the potentiometer
  int potValue = analogRead(potPin);
  potValue = map(potValue, 0,4095, 0, 100);
  // Print the value to the Serial monitor
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  delay(500); // Delay for stability
}
