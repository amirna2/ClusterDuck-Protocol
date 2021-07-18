#pragma once


#if defined(ARDUINO_TTGO_LoRa32_V2)
#define CDPCFG_BOARD ARDUINO_TTGO_LoRa32_V2

#define CDPCFG_PIN_BAT 35
#define CDPCFG_BAT_MULDIV 200 / 100

#define CDPCFG_PIN_LED1 25

// Lora configurations
#define CDPCFG_PIN_LORA_CS 18
#define CDPCFG_PIN_LORA_DIO0 26
#define CDPCFG_PIN_LORA_RST 14

// Oled Display settings

#define CDPCFG_PIN_OLED_CLOCK 15
#define CDPCFG_PIN_OLED_DATA 4
#define CDPCFG_PIN_OLED_RESET 16
#define CDPCFG_PIN_OLED_ROTATION U8G2_R0

// actualy missing
#define CDPCFG_PIN_LORA_DIO1 -1

#endif