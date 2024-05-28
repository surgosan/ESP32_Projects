#define PWM_CHANNEL 2      // Define the PWM channel number you want to use
#define PWM_FREQUENCY 50   // Define the PWM frequency in Hz
#define PWM_RESOLUTION 12  // Define the PWM resolution (bits)
#define servoPin 2         // Define the GPIO pin connected to the servo

void setup() {
  // Initialize LEDC PWM

  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);

  // Attach GPIO pin to the PWM channel
  ledcAttachPin(servoPin, PWM_CHANNEL);
}

void loop() {
  // Sweep the servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    setServoAngle(angle); // Set the servo position
    delay(15); // Delay for smooth motion
  }

  // Sweep the servo from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    setServoAngle(angle); // Set the servo position
    delay(15); // Delay for smooth motion
  }
}

// Function to set servo angle
void setServoAngle(int angle) {
  // Map the angle (in degrees) to the servo pulse width (in microseconds)
  int pulseWidth = map(angle, 0, 180, 1000, 2500); // Adjust min and max values as needed
  
  // Generate PWM signal
  ledcWrite(PWM_CHANNEL, pulseWidth); // Use PWM_CHANNEL instead of hardcoding the channel number
}
