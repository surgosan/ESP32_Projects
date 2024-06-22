//
// Created by sergy on 6/21/2024.
//

#include "ESPNOW_Master.h"
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_now.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "nvs_flash.h"

#define ESPNOW_TAG "ESPNOW_MASTER"

uint8_t peer_mac[] = {0x34, 0x85, 0x18, 0xa1, 0x5b, 0x78};

static void espnow_send_cb(const uint8_t *mac_addr, esp_now_send_status_t status) {
    ESP_LOGI(ESPNOW_TAG, "Send Status: %d", status);
}

void app_main(void) {
    esp_err_t ret;

    //Init NVS
    ret = nvs_flash_init();
    if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Init Wi-Fi
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());

    // Init ESPNOW
    ESP_ERROR_CHECK(esp_now_init());
    ESP_ERROR_CHECK(esp_now_register_send_cb(espnow_send_cb));

    // Add ESPNOW Peer
    esp_now_peer_info_t peer_info = {
            .peer_addr = {0},
            .channel = 0,
            .ifidx = ESP_IF_WIFI_STA,
            .encrypt = false
    };
    memcpy(peer_info.peer_addr, peer_mac, ESP_NOW_ETH_ALEN);
    ESP_ERROR_CHECK(esp_now_add_peer(&peer_info));

    // Send data to peer
    const char *data = "Hello from Master S3";
    ESP_ERROR_CHECK(esp_now_send(peer_mac, (uint8_t *)data, strlen(data)));

    // Delay | 1s
    vTaskDelay(pdMS_TO_TICKS(1000));
}