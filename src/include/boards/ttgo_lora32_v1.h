#pragma once


/**
 * BOARD "ttgo lora" and "heltec lora" v1
 *
 * heltec pcb is white, ttgo pcb has heltec+ttgo markings
 * left top+middle in this picture
 * https://github.com/Xinyuan-LilyGO/TTGO-LoRa-Series
 * pio: board = ttgo-lora32-v1
 */
#if defined(ARDUINO_TTGO_LoRa32_V1)
#define CDPCFG_BOARD ARDUINO_TTGO_LoRa32_V1

#define CDPCFG_PIN_LED1 25

// Lora configurations
#define CDPCFG_PIN_LORA_CS 18
#define CDPCFG_PIN_LORA_DIO0 26
#define CDPCFG_PIN_LORA_RST 23

// Oled Display settings
// #define CDPCFG_PIN_OLED_ROTATION U8G2_R0
#define CDPCFG_PIN_OLED_CLOCK 15
#define CDPCFG_PIN_OLED_DATA 4
#define CDPCFG_PIN_OLED_RESET 16

// actualy missing
#define CDPCFG_PIN_LORA_DIO1 -1
#endif