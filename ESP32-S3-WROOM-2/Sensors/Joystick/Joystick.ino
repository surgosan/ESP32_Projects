// Define pin numbers
#define JOYSTICK_SW_PIN 3
#define JOYSTICK_VRX_PIN 9 // Replace with appropriate GPIO pin
#define JOYSTICK_VRY_PIN 10 // Replace with appropriate GPIO pin

void setup() {
  Serial.begin(115200);
  // Configure joystick switch pin as input
  pinMode(JOYSTICK_SW_PIN, INPUT);

  // Configure joystick analog pins as inputs
  pinMode(JOYSTICK_VRX_PIN, INPUT);
  pinMode(JOYSTICK_VRY_PIN, INPUT);
}

void loop() {
  // Read joystick switch state
  int sw_state = analogRead(JOYSTICK_SW_PIN);
  if(sw_state > 5) {
    sw_state = 0;
  } else {
      sw_state = 1;
  }

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
  Serial.printf("Switch: %d  |  X: %d  |  Y: %d \n\n", sw_state, vrx_value, vry_value);
  

  // Add delay if needed
  delay(10);
}
