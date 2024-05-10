#define transistorPIN 1

void setup() {
  Serial.begin(115200);
  pinMode(transistorPIN, OUTPUT);
  digitalWrite(transistorPIN, LOW);
  delay(1000);
  Serial.println("Starting Blink");
}

void loop() {
  Serial.println("Blink");
  digitalWrite(transistorPIN, HIGH);
  delay(2000);

  digitalWrite(transistorPIN, LOW);
  delay(2000);
  
  Serial.println("\n\n");
}
