void setup() {
  pinMode(2, OUTPUT); // Set the built-in LED pin as output
}

void loop() {
  digitalWrite(2, HIGH);   // Turn the LED on
  delay(100);              // Wait for 100 milliseconds
  digitalWrite(2, LOW);    // Turn the LED off
  delay(100);              // Wait for 100 milliseconds
}
