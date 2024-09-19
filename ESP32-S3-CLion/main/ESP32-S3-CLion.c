#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

_Noreturn void app_main(void) {
    printf("Starting ESP32\n");

    while (true) {
        printf("Hello from ESP32 S3\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}