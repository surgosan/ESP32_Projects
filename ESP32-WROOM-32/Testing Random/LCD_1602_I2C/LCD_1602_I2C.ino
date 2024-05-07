#include <Wire.h>                    // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h>       // Include the LiquidCrystal_I2C library

#define I2C_ADDR    0x27            // I2C address of the LCD module (adjust if necessary)
#define LCD_COLS    16              // Number of columns in the LCD
#define LCD_ROWS    2               // Number of rows in the LCD

// Create an instance of the LiquidCrystal_I2C class
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS);

void setup() {
  // Initialize the LCD
  lcd.init();

  // Turn on the backlight (optional)
  // lcd.backlight();

  // Print "Hello, World!" on the LCD
  lcd.setCursor(0, 0);            // Set cursor to first column, first row
  lcd.print("Hello, World!");
}

void loop() {
  // Empty loop as we're not doing anything else in this example
}
