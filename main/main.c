/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"

#include "driver/hw_timer.h"

#include "BSP.h"

static const char *TAG = "POV";

const uint32_t GPIO_OUTPUT_PIN_SEL = (BIT(GPIO_AND0) | BIT(GPIO_AND1) | BIT(GPIO_AND2) | BIT(GPIO_AND3) | BIT(GPIO_DECODER_0) | BIT(GPIO_DECODER_1));

void hw_timer_callback(void *arg)
{

    ESP_LOGI(TAG, "hw_timer_callback");
    static int state = 0;
    static int color = 0;

    // push in colors
    for (int i = 0; i < 16; i++)
    {
        // set all channels
        gpio_set_level(GPIO_AND0, (state++) % 2);
        gpio_set_level(GPIO_AND1, (state++) % 2);
        gpio_set_level(GPIO_AND2, (state++) % 2);
        gpio_set_level(GPIO_AND3, (state++) % 2);

        gpio_set_level(GPIO_CLK, 0);
        gpio_set_level(GPIO_CLK, 1);
    }

    // sync latch
    gpio_set_level(GPIO_DECODER_0, 1);
    gpio_set_level(GPIO_DECODER_1, 1);

    // set next color
    gpio_set_level(GPIO_DECODER_0, color & 0x1);
    gpio_set_level(GPIO_DECODER_1, color & 0x2);
    color = (state++) % 3;
}

void app_main()
{
    ESP_LOGI(TAG, "POV started");

    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    gpio_set_level(GPIO_DECODER_0, 0);
    gpio_set_level(GPIO_DECODER_1, 0);

    ESP_LOGI(TAG, "Initialize hw_timer for callback1");
    hw_timer_init(hw_timer_callback, NULL);

    hw_timer_alarm_us(1000, true);


    ESP_LOGI(TAG, "in endless loop");
    while (true)
    {
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
