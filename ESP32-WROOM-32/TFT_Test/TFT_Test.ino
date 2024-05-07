#include <Adafruit_GFX.h>     // Include the Adafruit GFX library
#include <Adafruit_ILI9341.h> // Include the Adafruit ILI9341 library (for the specific display driver)
#include <SPI.h>              // Include the SPI library

#define TFT_CS    23  // Define the chip select pin for the TFT display (LCD CS pin on the breakout board)
#define TFT_RST   -1  // Define the reset pin for the TFT display (not used in this example)
#define TFT_DC    19  // Define the data/command pin for the TFT display (D/C pin on the breakout board)

// Create an instance of the ILI9341 display driver
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  // Initialize the TFT display
  tft.begin();
  
  // Rotate the display if necessary (uncomment one of the following lines if needed)
  // tft.setRotation(1); // Landscape
  // tft.setRotation(3); // Portrait

  // Set the text color to white
  tft.setTextColor(ILI9341_WHITE);

  // Set the text size (optional)
  tft.setTextSize(2);
  
  // Clear the screen
  tft.fillScreen(ILI9341_BLACK);

  // Set the cursor position and display "Hello, World!"
  tft.setCursor(20, 20);
  tft.println("Hello, World!");
}

void loop() {
  // Nothing to do here for a simple static display
}
