const int pin = 2; // Select PIN
const bool analogTesting = true; // Set Mode (Analog | Digital)
const int analogDelay = 50; // Set Analog Delay During Fade
const int digitalDelay = 2000; // Set Digital Delay Between On/Off
void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  if(analogTesting) {
    // ANALOG TESTING ---------------------------------------
    for (int i = 0; i <= 255; i++) {
    analogWrite(pin, i); // Set brightness to i
    delay(analogDelay); // Adjust delay for fading speed
    }

    // Fade out
    for (int i = 255; i >= 0; i--) {
      analogWrite(pin, i); // Set brightness to i
      delay(analogDelay); // Adjust delay for fading speed
    }
  } else {
    // DIGITAL TESTING --------------------------------------
    digitalWrite(pin, HIGH); // Turn the LED on
    delay(digitalDelay); // Wait for 1 second
    digitalWrite(pin, LOW); // Turn the LED off
    delay(digitalDelay); // Wait for 1 second
  }
}

/*
Mulimeter set to 20 Direct Voltage | PIN 2 | Analog Mode
3V3: 3.31
GND: 0.00
D15: 3.30
D2: Alternates (0 to 3.32)
D4: 0.00
RX2: 0.46
TX2: 0.54
D5: 3.31
D18: 0.37
D19: 0.13
D21: 0.41
RX0: 3.31
TX0: 3.30
D22: 0.42
D23: 0.39
VIN: 4.94
GND: 0.00
D13: 0.00
D12: 0.00
D14: 3.31
D27: 0.06
D26: 0.08
D25: 0.08
D33: 0.06
D32: 0.06
D35: 0.07
D34: 0.07
VN: 0.07
VP: 0.08
EN: 3.31
*/