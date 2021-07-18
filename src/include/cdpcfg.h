/**
 * @file cdpcfg.h
 * @brief CDP central compile-time configuration file.
 *
 * - `cdpcfg-pre.h` at the beginning
 * - `cdpcfg-post.h` at the end
 *
 * To customize your build, you could ...
 * - Edit this file or
 * - Copy it to `cdpcfg-pre.h` and edit _that_ or
 * - Create a from-scratch `cdpcfg-pre.h` that just overrides f.ex. the board
 * defines or
 * - Create a `cdpcfg-post.h` to undef/define just parts
 *
 * @version
 * @date 2020-09-16
 *
 * @copyright
 *
 */

// preload optional pre-cfg
#ifndef CRPCFG_PRE
#define CRPCFG_PRE
#if __has_include("cdpcfg-pre.h")
#include "cdpcfg-pre.h"
#endif
#endif

// this is the actual main configuration section
#ifndef CDPCFG
#define CDPCFG



#include "boards/ttgo_lora32_v1.h"
#include "boards/ttgo_lora32_v2.h"
#include "boards/t_beam.h"
#include "boards/heltec_wireless_stick.h"
#include "boards/heltec_wireless_stick_lite.h"
#include "boards/heltec_cubecell.h"
#include "boards/heltec_cubecell_gps.h"
#include "boards/rocketscream_mini_ultra_pro_v3.h"
#include "boards/sparkfun_lgw1c.h"
#include "boards/pycon_lopy.h"



#warning "===============> USING SX1262 <==================="


#if !defined(CDPCFG_BOARD)
#warning "NO BOARD DEFINED, DEFAULTING TO ARDUINO_HELTEC_WIFI_LORA_32_V2"
#define CDPCFG_BOARD ARDUINO_HELTEC_WIFI_LORA_32_V2
#include "boards/heltec_wifi_lora_v2.h"
#endif

/**
 * @brief Non board specific configuration
 *
 */

// Username and Password for OTA web page
#define CDPCFG_UPDATE_USERNAME "username"
#define CDPCFG_UPDATE_PASSWORD "password"

/// Serial Console Baud Rate
#define CDPCFG_SERIAL_BAUD 115200

// Access point IP adress

#define CDPCFG_AP_IP1 192
#define CDPCFG_AP_IP2 168
#define CDPCFG_AP_IP3 1
#define CDPCFG_AP_IP4 1

/** @brief Asyncwebserver Port */
#define CDPCFG_WEB_PORT 80

/// Frequency Range. Set for US Region 915.0Mhz
#define CDPCFG_RF_LORA_FREQ 915.0
#define CDPCFG_RF_LORA_FREQ_HZ 915000000
/// Bandwidth. Default is 125Mhz
#define CDPCFG_RF_LORA_BW 125.0
/// Spread Factor
#define CDPCFG_RF_LORA_SF 7
/// Transmit Power
#define CDPCFG_RF_LORA_TXPOW 20
/// Antenna Gain correction
#define CDPCFG_RF_LORA_GAIN 0

/// CDP message buffer max length
#define CDPCFG_CDP_BUFSIZE 256
/// CDP UUID generator max length
#define CDPCFG_UUID_LEN 8

/// CDP ALIVE timer duration in milliseconds
#define CDPCFG_MILLIS_ALIVE 1800000
/// CDP REBOOT timer duration in milliseconds
#define CDPCFG_MILLIS_REBOOT 43200000

/// CDP RGB Led RED Pin default value
#define CDPCFG_PIN_RGBLED_R 25
/// CDP RGB Led GREEN Pin default value
#define CDPCFG_PIN_RGBLED_G 4
/// CDP RGB Led BLUE Pin default value
#define CDPCFG_PIN_RGBLED_B 2

/// Default LoRa Module supported chipset when using the RadioLib library
#if !defined(CDPCFG_LORA_CLASS) && !defined(CDPCFG_HELTEC_CUBE_CELL)
#define CDPCFG_LORA_CLASS SX1276
#endif

#ifndef CDPCFG_OLED_CLASS
#if defined(CDPCFG_OLED_NONE)
// do nothing
#elif defined(CDPCFG_OLED_64x32)
// smaller displays
#define CDPCFG_OLED_CLASS U8G2_SSD1306_64X32_NONAME_F_SW_I2C
#else
// classic default
#define CDPCFG_OLED_CLASS U8G2_SSD1306_128X64_NONAME_F_SW_I2C

#endif
#endif

#endif // CDPCFG

// append optional post-cfg
#ifndef CRPCFG_POST
#define CRPCFG_POST
#if __has_include("cdpcfg-post.h")
#include "cdpcfg-post.h"
#endif
#endif
