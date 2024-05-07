#define potPIN 1
#define JOYSTICK_SW_PIN 3
#define JOYSTICK_VRX_PIN 9
#define JOYSTICK_VRY_PIN 10
#define xLeft 6
#define xRight 7
#define yLeft 15
#define yRight 16

void setup() {
  Serial.begin(115200);
  pinMode(potPIN, INPUT);
  pinMode(JOYSTICK_SW_PIN, INPUT);
  pinMode(JOYSTICK_VRX_PIN, INPUT);
  pinMode(JOYSTICK_VRY_PIN, INPUT);

  pinMode(xLeft, OUTPUT);
  pinMode(xRight, OUTPUT);
  pinMode(yLeft, OUTPUT);
  pinMode(yRight, OUTPUT);

  analogWrite(xLeft, 0);
  analogWrite(xRight, 0);
  analogWrite(yLeft, 0);
  analogWrite(yRight, 0);
}

void loop() {
  //============================== Potentiometer ==================================
  int potIn = analogRead(potPIN);
  int potValue = map(potIn, 0,4095, 0, 100);
  
  //============================== Joystick ==================================
  // Read joystick X and Y axes values
  int vrx_value = analogRead(JOYSTICK_VRX_PIN);
  vrx_value += 40;
  vrx_value = map(vrx_value, 0, 4095, 101, -99);
  if(vrx_value > -3 && vrx_value < 3) {
    vrx_value = 0;
  }
  int vry_value = analogRead(JOYSTICK_VRY_PIN);
  vry_value = map(vry_value, 0, 4095, -100, 100);
  if(vry_value > -3 && vry_value < 3) {
    vry_value = 0;
  }
  Serial.printf("PWM: %d%%  |  X: %d  |  Y: %d \n", 
  potValue, vrx_value, vry_value);
  

  // ============================== Control ==================================
  // Use potentiometer to set speed  ||  Threshold of 80
  int maxPWM = map(potIn, 0,4095, 80, 255);
  int xOut = map(abs(vrx_value), 0, 100, 0, maxPWM);
  int yOut = map(abs(vry_value), 0, 100, 0, maxPWM);

  Serial.printf("X PWM: %d  | Y PWM: %d \n\n\n", xOut, yOut);
  // Handle X direction
  if(vrx_value > 0) {
    analogWrite(xRight, xOut);
  } else if(vrx_value < 0) {
    analogWrite(xLeft, xOut);
  } else {
    analogWrite(xLeft, 0);
    analogWrite(xRight, 0);
  }

  // Handle y direction
  if(vry_value > 0) {
    analogWrite(yRight, yOut);
  } else if(vry_value < 0) {
    analogWrite(yLeft, yOut);
  } else {
    analogWrite(yLeft, 0);
    analogWrite(yRight, 0);
  }

  delay(10);
}
