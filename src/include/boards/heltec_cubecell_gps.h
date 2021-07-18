#pragma once

// BOARD "Heltec Cube Cell Board ASR6502+GPS+DISPLAY with SX1262"
#if defined(CubeCell_GPS)
#define CDPCFG_BOARD CubeCell_GPS

#define CDPCFG_HELTEC_CUBE_CELL

// Uncomment this to enable the OLED display
//#define ENABLE_DISPLAY

// TODO: These are not used by the Heltec LoRa library
// But they still need to be defined for now because the Duck::setupRadio() uses
// them. Update the setupRadio to use a RadioConfig data structure instead so we
// don't need to expose these to the apps
#define CDPCFG_PIN_LORA_CS 10
#define CDPCFG_PIN_LORA_DIO0 9 // BUSY PIN
#define CDPCFG_PIN_LORA_DIO1 8
#define CDPCFG_PIN_LORA_DIO2 -1
#define CDPCFG_PIN_LORA_RST 14

// Oled Display settings
#ifdef ENABLE_DISPLAY
#define CDPCFG_PIN_OLED_CLOCK 15
#define CDPCFG_PIN_OLED_DATA 4
#define CDPCFG_PIN_OLED_RESET 16
#else
#define CDPCFG_OLED_NONE
#endif

// Wifi module
#define CDPCFG_WIFI_NONE
#endif