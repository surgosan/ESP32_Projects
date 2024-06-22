//
// Created by sergy on 6/21/2024.
//

#include "ESPNOW_Slave.h"
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_now.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "nvs_flash.h"

#define TAG "SLAVE"

// Define ESPNOW peer MAC address
uint8_t espnow_peer_mac[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC}; // Replace with your master's MAC address

void espnow_recv_cb(const uint8_t *mac_addr, const uint8_t *data, int data_len, void *arg) {
    ESP_LOGI(TAG, "Received data from: " MACSTR ", len: %d", MAC2STR(mac_addr), data_len);
    ESP_LOGI(TAG, "Data: %.*s", data_len, data);
}

void app_main(void) {
    // Initialize NVS
    ESP_ERROR_CHECK(nvs_flash_init());

    // Initialize WiFi
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());

    // Initialize ESPNOW
    ESP_ERROR_CHECK(esp_now_init());

    // Register ESPNOW receive callback
    esp_now_register_recv_cb(espnow_recv_cb, NULL); // NULL is passed as the fourth argument

    // Keep the task alive
    while (true) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}