#pragma once

/*
 * BOARD "sparkfun lora gateway 1-channel"
 * https://www.sparkfun.com/products/15006
 * pio: board = sparkfun_lora_gateway_1-channel
 */

#if defined(SPARKFUN_LGW1C)
#define CDPCFG_BOARD SPARKFUN_LGW1C

// this is not an official ARDUINO_* define since this board doesnt have one

// Lora configurations
#define CDPCFG_PIN_LORA_CS 16
#define CDPCFG_PIN_LORA_DIO0 26
#define CDPCFG_PIN_LORA_DIO1 33
#define CDPCFG_PIN_LORA_DIO2 32
#define CDPCFG_PIN_LORA_RST 5

// Oled Display settings
#define CDPCFG_OLED_NONE
#endif