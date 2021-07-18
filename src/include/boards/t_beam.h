#pragma once

// T-Beam -> LilyGO LoRa Series boards
// https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series


#if defined(ARDUINO_TBeam)
#define CDPCFG_BOARD ARDUINO_TBeam

//Uncomment this if you are using the T-Beam LoRa SX1262
#define CDPCFG_RADIO_SX126X

#if defined(CDPCFG_RADIO_SX126X)
#warning "===============> USING SX1262 <==================="

  // Board is available here: https://pt.aliexpress.com/item/4001287221970.html
#define GPS_RX_PIN                  34
#define GPS_TX_PIN                  12
#define BUTTON_PIN                  38
#define BUTTON_PIN_MASK             GPIO_SEL_38
#define I2C_SDA                     21
#define I2C_SCL                     22
#define PMU_IRQ                     35

#define RADIO_SCLK_PIN               5
#define RADIO_MISO_PIN              19
#define RADIO_MOSI_PIN              27
#define RADIO_CS_PIN                18
#define RADIO_DI0_PIN               26
#define RADIO_RST_PIN               23
#define RADIO_DIO1_PIN              33
#define RADIO_BUSY_PIN              32

#define BOARD_LED                   4
#define LED_ON                      LOW
#define LED_OFF                     HIGH
#define HAS_GPS 

// CDP 
#define CDPCFG_PIN_BAT 35 
#define CDPCFG_BAT_MULDIV 200 / 100 
#define CDPCFG_PIN_LED1 25 

// Lora configurations 
// Default is set to SX1262, but you may set another SX126x depeding the regional chipset
#define CDPCFG_LORA_CLASS SX1262             
#define CDPCFG_PIN_LORA_CS RADIO_CS_PIN
#define CDPCFG_PIN_LORA_DIO1 RADIO_DIO1_PIN
#define CDPCFG_PIN_LORA_RST RADIO_RST_PIN 
#define CDPCFG_PIN_LORA_BUSY RADIO_BUSY_PIN

// Oled Display settings
#define CDPCFG_OLED_NONE

#else
  #define CDPCFG_PIN_BAT 35 
  #define CDPCFG_BAT_MULDIV 200 / 100 
  #define CDPCFG_PIN_LED1 25 

  // Lora configurations 
  #define CDPCFG_PIN_LORA_CS 18 
  #define CDPCFG_PIN_LORA_DIO0 26 
  #define CDPCFG_PIN_LORA_RST 14 
  #define CDPCFG_PIN_LORA_DIO1 -1

  // Oled Display settings 
  #define CDPCFG_PIN_OLED_CLOCK 22 
  #define CDPCFG_PIN_OLED_DATA 21 
  #define CDPCFG_PIN_OLED_RESET 16 
  #define CDPCFG_PIN_OLED_ROTATION U8G2_R0 
#endif

#endif
