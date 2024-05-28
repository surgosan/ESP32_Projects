#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
#define servoPin 2  // Define the GPIO pin connected to the servo

void setup() {
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  // Attach the servo on the servoPin to the servo object
  myservo.attach(servoPin);
}

void loop() {
  // Sweep the servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    myservo.write(angle); // Set the servo position
    delay(15); // Delay for smooth motion
  }

  // Sweep the servo from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    myservo.write(angle); // Set the servo position
    delay(15); // Delay for smooth motion
  }
}
