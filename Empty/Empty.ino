void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println("Hello World");
  pinMode(48, OUTPUT);
  digitalWrite(48, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");
  delay(5000);
}
