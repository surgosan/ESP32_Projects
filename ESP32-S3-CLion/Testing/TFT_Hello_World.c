#include <stdio.h>
#include <esp_lcd_panel_io.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_log.h"

#define TFT_BL     15
#define TFT_CS     5
#define TFT_RST    4
#define TFT_DC     1
#define TFT_SCK    7
#define TFT_MOSI   6
#define TFT_MISO   2

static const char *TAG = "LCD";

// SPI bus configuration
spi_bus_config_t buscfg = {
        .mosi_io_num = TFT_MOSI,
        .miso_io_num = TFT_MISO,
        .sclk_io_num = TFT_SCK,
        .max_transfer_sz = 240 * 320 * 2 + 8
};

// SPI device configuration for ILI9341
spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 40 * 1000 * 1000,  // 40 MHz
        .mode = 0,
        .spics_io_num = TFT_CS,
        .queue_size = 7
};

void init_backlight(void) {
    gpio_set_direction(TFT_BL, GPIO_MODE_OUTPUT);
    gpio_set_level(TFT_BL, 1);  // Turn on backlight
}

void app_main(void) {
    ESP_LOGI(TAG, "Initializing SPI Bus");

    // Initialize SPI bus
    ESP_ERROR_CHECK(spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO));

    // Attach ILI9341 to SPI bus
    esp_lcd_panel_io_spi_config_t io_config = {
            .dc_gpio_num = TFT_DC,
            .cs_gpio_num = TFT_CS,
            .pclk_hz = 40 * 1000 * 1000,  // 40 MHz
            .spi_mode = 0,
            .trans_queue_depth = 10,
            .spi_host = SPI2_HOST,
    };

    esp_lcd_panel_io_handle_t io_handle;
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((const esp_lcd_panel_io_spi_config_t *)&io_config, &io_handle));

    // Initialize the ILI9341 panel
    esp_lcd_panel_dev_config_t panel_config = {
            .reset_gpio_num = TFT_RST,
            .color_space = ESP_LCD_COLOR_SPACE_RGB,
            .bits_per_pixel = 16
    };

    esp_lcd_panel_handle_t panel_handle;
    ESP_ERROR_CHECK(esp_lcd_new_panel_ili9341(io_handle, &panel_config, &panel_handle));

    // Reset and initialize the panel
    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));

    // Fill screen with black (clearing)
    ESP_ERROR_CHECK(esp_lcd_panel_draw_bitmap(panel_handle, 0, 0, 240, 320, NULL)); // Clear screen

    // Manually draw "Hello World" (no text drawing support in this low-level driver)
    // Custom code to render "Hello World" could go here

    init_backlight();  // Turn on backlight

    ESP_LOGI(TAG, "LCD initialized, backlight enabled");

    while (true) {
        printf("Running...\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
