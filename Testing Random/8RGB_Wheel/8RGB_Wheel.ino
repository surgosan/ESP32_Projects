#include "Freenove_WS2812_Lib_for_ESP32.h"
// https://github.com/Freenove/Freenove_WS2812B_RGBLED_Controller/tree/master
// https://freenove.com/tutorial

#define LEDS_PIN 2 // Change this to the pin you connected the S pin of the LED module to
#define LEDS_COUNT 8
#define CHANNEL 0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
  strip.begin();
  strip.setAllLedsColor(150);
  strip.show();
}

void loop() {
//   for (int j = 0; j < 255; j ++) {
//     for (int i = 0; i < LEDS_COUNT; i++) {
//       strip.setLedColorData(i, j);
//     }
//     strip.show(); // Send color data to LED, and display.
//     delay(50);
//  }
  // for(int l = 0; l < LEDS_COUNT; l++) {
  //   strip.setAllLedsColor(150);
  //   strip.show();
  // }
  int arr[][3] = {
    {0, 0, 0},
    {255, 0, 0},
    {0, 255, 0},
    {0, 0, 255},
    {255, 255, 0},
    {0, 255, 255},
    {255, 0, 255},
    {0, 0, 0},
    {255, 255, 255}
  };
  int arrLength = sizeof(arr) / sizeof(arr[0]);
  for(int i = 0; i < arrLength; i++) {
    strip.setAllLedsColor(arr[i][0], arr[i][1], arr[i][2]);
    strip.show();
    delay(1000);
  }
}

