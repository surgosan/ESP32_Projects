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
  if(sw_state > 0) {
    sw_state = 1;
  }

  // Read joystick X and Y axes values
  int vrx_value = analogRead(JOYSTICK_VRX_PIN);
  vrx_value += 40;
  vrx_value = map(vrx_value, 0, 4095, 100, 0);
  if(vrx_value == 49 || vrx_value == 51) {
    vrx_value = 50;
  }
  int vry_value = analogRead(JOYSTICK_VRY_PIN);
  vry_value = map(vry_value, 0, 4095, 0, 100);
  if(vry_value == 49 || vry_value == 51) {
    vry_value = 50;
  }

  // Print values to serial console
  // Switch, X, Y
  Serial.print(sw_state);
  Serial.print(", ");
  Serial.print(vrx_value);
  Serial.print(", ");
  Serial.println(vry_value);
  Serial.println("");
  

  // Add delay if needed
  delay(10);
}
