#define potPIN 4
#define speakerPin 5

void setup() {
    pinMode(speakerPin, OUTPUT);
}

int frequency = 100;
void loop() {
    int potValue = analogRead(potPIN);
    frequency = map(potValue, 0,4095, 100, 5000);

    tone(speakerPin, frequency); // Generate a tone of 1000 Hz
    delay(1000);            // Wait for 1 second
    noTone(speakerPin);     // Turn off the tone
    delay(1000);            // Wait for 1 second
}
