//
// Created by sergy on 6/21/2024.
//

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void app_main(void) {
    printf("Starting ESP\n");


    while (true) {
        printf("Turning LED On\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}