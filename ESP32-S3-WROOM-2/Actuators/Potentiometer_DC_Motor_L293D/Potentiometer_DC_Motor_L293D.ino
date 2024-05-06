#define in1Pin 6
#define in2Pin 7

void setup() {
  // put your setup code here, to run once:
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  // Initially, set motor to stop
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  delay(2000);

  // STOP
  
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  delay(2000);
  
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  delay(2000);

  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  delay(2000);
}
