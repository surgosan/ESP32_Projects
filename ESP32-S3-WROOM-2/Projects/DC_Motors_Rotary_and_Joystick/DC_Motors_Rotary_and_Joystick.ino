#define potPIN 1

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(potPIN);
  potValue = map(potValue, 0,4095, 0, 255);
  Serial.println(potValue);
  
  delay(1000);
}
