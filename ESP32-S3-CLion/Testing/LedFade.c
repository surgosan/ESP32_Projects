//
// Created by sergy on 9/3/2024.
//

//
// Created by sergy on 6/21/2024.
//

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"

#define led_gpio GPIO_NUM_4

// LEDC Configuration
#define LEDC_TIMER      LEDC_TIMER_0
#define LEDC_MODE       LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO  led_gpio
#define LEDC_CHANNEL    LEDC_CHANNEL_0
#define LEDC_DUTY_RES   LEDC_TIMER_13_BIT
#define LEDC_FREQUENCY  5000

void app_main(void) {
    printf("Starting ESP\n");

    ledc_timer_config_t ledc_timer = {
            .duty_resolution = LEDC_DUTY_RES,
            .freq_hz = LEDC_FREQUENCY,
            .speed_mode = LEDC_MODE,
            .timer_num = LEDC_TIMER,
            .clk_cfg = LEDC_AUTO_CLK
    };

    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
            .channel = LEDC_CHANNEL,
            .duty = 0,
            .gpio_num = LEDC_OUTPUT_IO,
            .speed_mode = LEDC_MODE,
            .hpoint = 0,
            .timer_sel = LEDC_TIMER
    };
    ledc_channel_config(&ledc_channel);

    ledc_fade_func_install(0);

    // Keep the task alive
    while (true) {
        printf("Turning LED On\n");
        ledc_set_fade_time_and_start(LEDC_MODE, LEDC_CHANNEL, 8191, 1000, LEDC_FADE_NO_WAIT);
        vTaskDelay(pdMS_TO_TICKS(1000));

        printf("Turning LED OFF\n");
        ledc_set_fade_time_and_start(LEDC_MODE, LEDC_CHANNEL, 0, 1000, LEDC_FADE_NO_WAIT);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}