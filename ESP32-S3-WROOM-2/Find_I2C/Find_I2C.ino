#include <Wire.h>
#include "driver/i2c.h"
/* 
Setup I2C Master Pins
*/

#define I2C_MASTER_SCL_IO           2                 // GPIO number for I2C SCL pin
#define I2C_MASTER_SDA_IO           3                 // GPIO number for I2C SDA pin
#define I2C_MASTER_NUM              I2C_NUM_0         // I2C port number
#define I2C_MASTER_FREQ_HZ          100000          // I2C master clock frequency

void i2c_master_init() {
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;

    i2c_param_config(I2C_MASTER_NUM, &conf);
    i2c_driver_install(I2C_MASTER_NUM, conf.mode, 0, 0, 0);
}


void setup() {
  i2c_master_init();
  Wire.begin();

  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int deviceCount = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Found device at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      deviceCount++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (deviceCount == 0) {
    Serial.println("No I2C devices found.");
  }

  delay(5000); // Wait 5 seconds before scanning again
}
