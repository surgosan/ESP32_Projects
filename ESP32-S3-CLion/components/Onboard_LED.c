#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Define the GPIO pin connected to the onboard LED
#define LED_PIN 1 // Replace with the appropriate GPIO pin for your board

_Noreturn void app_main() {
    // Configure the GPIO pin as output
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        // Toggle the LED on and off every second
        gpio_set_level(LED_PIN, 1); // LED ON
        vTaskDelay(pdMS_TO_TICKS(250)); // Delay for 1000ms = 1 second
        gpio_set_level(LED_PIN, 0); // LED OFF
        vTaskDelay(pdMS_TO_TICKS(250)); // Delay for 1000ms = 1 second
    }
}
