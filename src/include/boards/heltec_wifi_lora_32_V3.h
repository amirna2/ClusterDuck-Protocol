#pragma once

/*
 * BOARD "WIFI_LoRa_32_V3"
 * https://heltec.org/project/wifi-lora-32-v3/
 */
#if defined(ARDUINO_WIFI_LORA_32_V3) || defined(ARDUINO_heltec_wifi_lora_32_V3) 

#define CDP_BOARD_NAME "Heltec WiFi LoRa 32 V3"
#define CDPCFG_RADIO_SX1262

#pragma message("Compiling for Heltec WiFi LoRa 32 V3")
// Uncomment this to enable the OLED display
#define ENABLE_DISPLAY

// Lora configurations 
#define CDPCFG_PIN_LORA_CS      8
#define CDPCFG_PIN_LORA_RST     12
#define CDPCFG_PIN_LORA_DIO0    13
#define CDPCFG_PIN_LORA_BUSY    13 // SX1262 BUSY
#define CDPCFG_PIN_LORA_DIO1    14 // SX1262 IRQ

// Oled Display settings
#ifdef ENABLE_DISPLAY
#define CDPCFG_PIN_OLED_CLOCK SCL_OLED
#define CDPCFG_PIN_OLED_DATA SDA_OLED
#define CDPCFG_PIN_OLED_RESET RST_OLED
#define CDPCFG_PIN_OLED_ROTATION U8G2_R0
#endif

#endif