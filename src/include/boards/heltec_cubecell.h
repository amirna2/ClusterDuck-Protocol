#pragma once

/*
 * BOARD "Heltec Cube Cell Board ASR6501 with SX1262"
 * https://heltec.org/project/htcc-ab01/
 * pio: board = cubecell_board
 */
#if defined(CubeCell_Board)

#define CDPCFG_BOARD CubeCell_Board

#define CDPCFG_HELTEC_CUBE_CELL

// TODO: These are not used by the Heltec LoRa library
// But they still need to be defined for now because the Duck::setupRadio() uses them.
// Update the setupRadio to use a RadioConfig data structure instead so we don't need to expose these to the apps
#define CDPCFG_PIN_LORA_CS 10
#define CDPCFG_PIN_LORA_DIO0 9 // BUSY PIN
#define CDPCFG_PIN_LORA_DIO1 8
#define CDPCFG_PIN_LORA_DIO2 -1
#define CDPCFG_PIN_LORA_RST 14

// Oled Display settings
#define CDPCFG_OLED_NONE

// Wifi module
#define CDPCFG_WIFI_NONE
//===== BOARD "Heltec Cube Cell Board ASR6501 with SX1262" =====
#endif