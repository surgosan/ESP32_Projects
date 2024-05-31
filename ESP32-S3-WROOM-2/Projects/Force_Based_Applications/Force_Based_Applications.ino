#define fsrPin 1
#define transistorPIN 5

void setup() {
  pinMode(fsrPin, INPUT);
  pinMode(transistorPIN, OUTPUT);
  digitalWrite(transistorPIN, LOW);
  Serial.begin(115200);
}

void loop() {
  int fsrValue = analogRead(fsrPin);
  if(fsrValue < 3500) {
    digitalWrite(transistorPIN, HIGH);
  } else {
    digitalWrite(transistorPIN, LOW);
  }
  Serial.print("FSR Value: ");
  Serial.println(fsrValue);
  delay(500); // Delay for stability
}
