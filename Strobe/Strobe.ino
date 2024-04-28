bool strobeRunning = true; // Variable to track whether strobe is running or stopped

void setup() {
  pinMode(2, OUTPUT); // Set the built-in LED pin as output
  Serial.begin(9600); // Start serial communication at 9600 baud
  Serial.println("Started Strobe");
}

void loop() {
  if (Serial.available()) { // Check if data is available to read from serial
    String command = Serial.readStringUntil('\n'); // Read the command until newline character
    command.trim(); // Remove leading and trailing whitespaces

    if (command == "STOP") {
      strobeRunning = false; // Stop the strobe
      Serial.println("Strobe stopped");
    } else if (command == "START") {
      strobeRunning = true; // Start the strobe
      Serial.println("Strobe started");
    } else {
      Serial.println("Silly ばか。　なにそれ");
    }
  }

  if (strobeRunning) {
    digitalWrite(2, HIGH);   // Turn the LED on
    delay(100);              // Wait for 100 milliseconds
    digitalWrite(2, LOW);    // Turn the LED off
    delay(100);              // Wait for 100 milliseconds
  }
}
