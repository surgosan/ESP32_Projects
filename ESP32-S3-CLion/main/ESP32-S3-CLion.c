//
// Created by sergy on 6/21/2024.
//

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void app_main(void) {
    printf("Starting ESP\n");


    while (true) {
        printf("Hello from ESP32-C6!\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}