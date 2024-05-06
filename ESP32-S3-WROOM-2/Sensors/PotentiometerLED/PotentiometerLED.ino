#include <Adafruit_NeoPixel.h>

#define LED_PIN 38
#define potPIN 4

Adafruit_NeoPixel pixels(1, LED_PIN, NEO_RGB);

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixels.show();
  pixels.setBrightness(50);
}

int color = 0;
int brightness = 0;
void loop() {
  int potValue = analogRead(potPIN);
  brightness = map(potValue, 0,4095, 0, 255);

  if(color == 0) { //red
    pixels.setPixelColor(0, brightness, 0, 0);
    color++;
  } else if(color == 1) {//green
    pixels.setPixelColor(0, 0, brightness, 0);
    color++;
  } else if(color == 2) { //blue
    pixels.setPixelColor(0, 0, 0, brightness);
    color++;
  } else { //white
    pixels.setPixelColor(0, brightness, brightness, brightness);
    color = 0;
  }
  pixels.show();

  delay(1000);
}
