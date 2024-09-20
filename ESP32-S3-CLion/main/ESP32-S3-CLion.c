#include "esp_adc/adc_oneshot.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_log.h"

// Peripherals
#define pot_sig ADC_CHANNEL_4
#define led_pin GPIO_NUM_5

// LEDC Configuration
#define LEDC_TIMER      LEDC_TIMER_0
#define LEDC_MODE       LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO  led_pin
#define LEDC_CHANNEL    LEDC_CHANNEL_0
#define LEDC_DUTY_RES   LEDC_TIMER_12_BIT
#define LEDC_FREQUENCY  5000

// ADC handle for oneshot mode
adc_oneshot_unit_handle_t adc1_handle;

void init_adc() {
    adc_oneshot_unit_init_cfg_t init_config1 = {
            .unit_id = ADC_UNIT_1
    };
    adc_oneshot_new_unit(&init_config1, &adc1_handle);

    // Configure adc channel
    adc_oneshot_chan_cfg_t config = {
            .bitwidth = ADC_BITWIDTH_12,
            .atten = ADC_ATTEN_DB_6
    };
    adc_oneshot_config_channel(adc1_handle, pot_sig, &config);
}

_Noreturn void app_main(void) {
    int pot_value = 0;

    init_adc();

// --------------------------------- LEDC ---------------------------------------
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

// ------------------------------ LEDC END -----------------------------------------

    while (true) {
        // Read and print analog signal
        adc_oneshot_read(adc1_handle, pot_sig, &pot_value);
//        double pot_percent = (pot_value/4095.0) * 100.0;

        // Commented out to reduce terminal writes
//        ESP_LOGI("ADC Read", "Potentiometer Reading: %d or %.0f%%", pot_value, pot_percent);

        // Control LED
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, pot_value);
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}