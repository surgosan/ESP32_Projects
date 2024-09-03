//
// Created by sergy on 9/3/2024.
//

//
// Created by sergy on 6/21/2024.
//

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "nvs_flash.h"

#define led_gpio GPIO_NUM_4

void app_main(void) {
    // Initialize NVS
    printf("Starting ESP\n");

    esp_rom_gpio_pad_select_gpio(led_gpio);
    gpio_set_direction(led_gpio, GPIO_MODE_OUTPUT);

    // Keep the task alive
    while (true) {
        printf("Turning LED On\n");
        gpio_set_level(led_gpio, 1);
        vTaskDelay(pdMS_TO_TICKS(1000));

        printf("Turning LED Off\n");
        gpio_set_level(led_gpio, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}