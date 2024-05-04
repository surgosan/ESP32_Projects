#define R 15
#define G 2
#define B 4

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting LED");
  delay(1000);

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  analogWrite(R, 255);
  analogWrite(G, 255);
  analogWrite(B, 255);
}


int RGB[] = {R, G, B};
int colorMode = 0;

void loop() {

  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    String command = Serial.readStringUntil('\n'); // Read the command until newline character
    command.trim(); // Remove leading and trailing whitespaces

    if(command.equals("Red")) {
      Serial.println("Changing to Red");
      colorMode = 1;
    } else if(command.equals("Green")) {
      Serial.println("Changing to Green");
      colorMode = 2;
    } else if(command.equals("Blue")) {
      Serial.println("Changing to Blue");
      colorMode = 3;
    } else if(command.equals("White")) { 
      Serial.println("Changing to White");
      colorMode = 0;
    } else {
      Serial.println("Command Unknown, Starting Rainbow.");
      colorMode = 4;
    }
  }

  if(colorMode == 0) {
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 255);
  } else if(colorMode == 1) {
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 0);
  } else if(colorMode == 2) {
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 0);
  } else if(colorMode == 3) {
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 255);
  } else {
    for(int i = 0; i < 3; i++) {
      for(int brightness = 0; brightness <= 255; i++) {
        analogWrite(RGB[i], brightness);
        delay(50);
      }
    }

    for(int i = 0; i < 3; i++) {
      for(int brightness = 0; brightness <= 255; i++) {
        analogWrite(RGB[i], brightness);
        delay(50);
      }
    }
  }
  
  delay(5000);
}
