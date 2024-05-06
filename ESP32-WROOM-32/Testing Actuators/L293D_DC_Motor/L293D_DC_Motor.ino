const int in1Pin = 6; // Replace with your PWM-capable GPIO pin number
const int in2Pin = 7; // Replace with your GPIO pin number

void setup() {
  // Set GPIO pins as outputs
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  // Initially, set motor to stop
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);

// ANALOG
  // analogWrite(in1Pin, 0);
  // analogWrite(in2Pin, 0);
}

bool fast = false;
void loop() {
  // Rotate motor clockwise for 2 seconds

  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  delay(2000);

  // STOP
  
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  delay(2000);

  // Speed up motor

// ANALOG
  // digitalWrite(in1Pin, LOW);
  // digitalWrite(in2Pin, LOW);
  // for(int i = 0; i < 255; i++) {
  //   analogWrite(in1Pin, i);
  //   delay(10);
  // }

  // Rotate motor counterclockwise for 2 seconds

  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  delay(2000);

// ANALOG
  // if(fast) {
  //   analogWrite(in1Pin, 255);
  //   fast = false;
  // } else {
  //   analogWrite(in1Pin, 200);
  //   fast = true;
  // }
  // delay(2000);

  // STOP

  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  delay(2000);

// STOP | ANALOG
  // analogWrite(in1Pin, 0);
  // analogWrite(in2Pin, 0);
  // delay(2000);

}
