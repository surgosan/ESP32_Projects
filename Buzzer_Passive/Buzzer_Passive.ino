#define BUZZER_PIN 2

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Generate a square wave with a frequency of 1000 Hz
  tone(BUZZER_PIN, 1000); // You can adjust the frequency as needed
  delay(1000); // Sound the buzzer for 1 second
  noTone(BUZZER_PIN); // Turn off the buzzer
  delay(1000); // Wait for 1 second before next tone
}
