#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Pin definitions
#define TFT_BL     15
#define TFT_CS     5
#define TFT_RST    4
#define TFT_DC     1
#define TFT_SCK    7
#define TFT_MOSI   6
#define TFT_MISO   2

// Create display object
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST, TFT_MISO);

// Array of strings to display
const char* messages[] = {
  "Hello, ESP32!",
  "Welcome to Adafruit!",
  "This is a TFT display.",
  "Displaying text...",
  "Graphics are fun!",
  "ESP32 + TFT = Cool",
  "Arduino programming",
  "Enjoy your project!",
  "Adafruit ILI9341",
  "Thank you!"
};
const int numMessages = sizeof(messages) / sizeof(messages[0]);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("TFT Display Test");

  // Set backlight pin mode
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH); // Turn on backlight

  // Initialize the TFT screen
  tft.begin();

  // Clear the screen with a black background
  tft.fillScreen(ILI9341_BLACK);
  
  // Set initial text properties
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
}

void loop() {
  for (int i = 0; i < numMessages; i++) {
    // Clear the screen before displaying new message
    tft.fillScreen(ILI9341_BLACK);
    
    // Calculate the position to start drawing the text
    int16_t x = 10;
    int16_t y = 10 + (i * 24) % (tft.height() - 24); // Ensure it stays within the screen height

    // Set cursor and print the message
    tft.setCursor(x, y);
    tft.println(messages[i]);

    // Delay before showing the next message
    delay(2000); // Display each message for 2 seconds
  }
}
