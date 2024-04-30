const int fsrPin = 13; // GPIO pin connected to the FSR

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  digitalWrite(2, HIGH);
}

void loop() {
  // Read analog voltage from the FSR
  int fsrValue = analogRead(fsrPin);

  // Print the analog value to the serial monitor
  Serial.println(fsrValue);

  delay(100); // Delay for stability
}
