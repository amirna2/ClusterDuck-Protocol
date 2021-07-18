#pragma once

/*
 * BOARD "pycom lopy4"
 * https://docs.pycom.io/datasheets/development/lopy4/
 * pio: board = lopy4
 */
#if defined(ARDUINO_LoPy4)
#define CDPCFG_BOARD ARDUINO_LoPy4

#define CDPCFG_PIN_ANT 16

// Lora configurations
#define CDPCFG_PIN_LORA_CS 18
#define CDPCFG_PIN_LORA_DIO0 23
#define CDPCFG_PIN_LORA_RST -1

// special SPI
#define CDPCFG_PIN_LORA_SPI_SCK 5
#define CDPCFG_PIN_LORA_SPI_MISO 19
#define CDPCFG_PIN_LORA_SPI_MOSI 27
#define CDPCFG_LORA_CLASS SX1276

// Oled Display settings
#define CDPCFG_OLED_NONE

// actualy missing
#define CDPCFG_PIN_LORA_DIO1 -1
#endif