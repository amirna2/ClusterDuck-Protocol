#pragma once

/*
 * BOARD "heltec wireless stick lite"
 * ARDUIONO BOARD PACKAGE URL:
 * https://resource.heltec.cn/download/package_heltec_esp32_index.json
 * DOCS:
 * http://www.heltec.cn/project/wireless-stick-lite/
 * pio: board = WIRELESS_STICK_LITE
 */
#if defined(ARDUINO_WIRELESS_STICK_LITE)
#define CDPCFG_BOARD ARDUINO_WIRELESS_STICK_LITE

#define CDPCFG_PIN_BAT 37
#define CDPCFG_BAT_MULDIV 320 / 100

#define CDPCFG_PIN_VEXT 21

#define CDPCFG_PIN_LED1 25

// Lora configurations
#define CDPCFG_PIN_LORA_CS 18
#define CDPCFG_PIN_LORA_DIO0 26
#define CDPCFG_PIN_LORA_RST 14

// Oled Display settings
#define CDPCFG_OLED_NONE

// actualy missing
#define CDPCFG_PIN_LORA_DIO1 -1
#endif