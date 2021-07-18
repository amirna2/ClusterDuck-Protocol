#pragma once

/*
 * BOARD "pycom lopy"
 * https://docs.pycom.io/datasheets/development/lopy/
 * pio: board = lopy
 */
#if defined(ARDUINO_LoPy)
#define CDPCFG_BOARD ARDUINO_LoPy

#define CDPCFG_PIN_ANT 16

// Lora configurations
#define CDPCFG_PIN_LORA_CS 17
#define CDPCFG_PIN_LORA_DIO0 23
#define CDPCFG_PIN_LORA_RST 18

// special SPI
#define CDPCFG_PIN_LORA_SPI_SCK 5
#define CDPCFG_PIN_LORA_SPI_MISO 19
#define CDPCFG_PIN_LORA_SPI_MOSI 27
#define CDPCFG_LORA_CLASS SX1272

// Oled Display settings
#define CDPCFG_OLED_NONE

// actualy missing
#define CDPCFG_PIN_LORA_DIO1 -1

#endif