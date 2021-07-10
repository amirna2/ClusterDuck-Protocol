

#include "include/DuckRadio.h"

#if defined(CDPCFG_HELTEC_CUBE_CELL)
#include "include/DuckUtils.h"
#include <LoRaWan_APP.h>

/*
 * set LoraWan_RGB to 1,the RGB active in loraWan
 * RGB red means sending;
 * RGB green means received done;
 */
#ifndef LoraWan_RGB
#define LoraWan_RGB 0
#endif

#define RF_FREQUENCY CDPCFG_RF_LORA_FREQ_HZ

#define TX_OUTPUT_POWER CDPCFG_RF_LORA_TXPOW
#define RX_TIMEOUT_VALUE 3000
#define TX_TIMEOUT_VALUE 1000
// [0: 125 kHz, 1: 250 kHz, 2: 500 kHz, 3: Reserved]
#define LORA_BANDWIDTH 0

// [7: SF7, ... 12: SF12]
#define LORA_SPREADING_FACTOR 7

// [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8]
#define LORA_CODINGRATE 3
#define LORA_PREAMBLE_LENGTH 8 // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT 0  // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON false
#define LORA_IQ_INVERSION_ON false
#define LORA_CRC_ON true

DuckRadio* DuckRadio::instance = NULL;

DuckRadio::DuckRadio() {}

volatile bool DuckRadio::receivedFlag = false;
static RadioEvents_t radioEvents;

static void OnLoraTxDone(void) {
  loginfo("TX done. Switch to RX mode");
  Radio.Rx(3000);
  Radio.IrqProcess();
  // Not sleeping here because we want to listen for incoming packets
}

static void OnLoraTxTimeout(void) {
  loginfo("TX timeout");
  Radio.Sleep();
}

static void OnLoraRxDone(uint8_t* payload, uint16_t size, int16_t rssi,
                         int8_t snr) {
  loginfo("RX Done");
  Radio.Sleep();
  logdbg("Received Hex:");
  for (int i = 0; i < size; i++) {
    Serial.print(*payload++, HEX);
  }
  Serial.println();
  logdbg_f("\nRSSI:%d, SNR:%d, Size:%d\r\n", rssi, snr, size);
  DuckRadio::setLastRxPacket(payload, size);
  if (duckutils::isInterruptEnabled()) {
    DuckRadio::setReceiveFlag(true);
  }
  Radio.Sleep();
}

static void OnLoraRxTimeout(void) {
  loginfo("RX Timeout");
  Radio.Sleep();
}

static void OnLoraRxError(void) {
  Radio.Sleep();
  loginfo("RX error");
}

DuckRadio* DuckRadio::getInstance() {
  return (instance == NULL) ? new DuckRadio : instance;
}

int DuckRadio::setupRadio(LoraConfigParams config) {
  boardInitMcu();
  radioEvents.TxDone = OnLoraTxDone;
  radioEvents.TxTimeout = OnLoraTxTimeout;
  radioEvents.RxDone = OnLoraRxDone;
  radioEvents.RxTimeout = OnLoraRxTimeout;
  Radio.Init(&radioEvents);

  Radio.SetChannel(RF_FREQUENCY);
  Radio.SetTxConfig(MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
                    LORA_SPREADING_FACTOR, LORA_CODINGRATE,
                    LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON,
                    LORA_CRC_ON, 0, 0, LORA_IQ_INVERSION_ON, TX_TIMEOUT_VALUE);

  Radio.SetRxConfig(
      MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR, LORA_CODINGRATE, 0,
      LORA_PREAMBLE_LENGTH, LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON,
      0,LORA_CRC_ON, 0, 0, LORA_IQ_INVERSION_ON,true);

  Radio.SetSyncWord(LORA_MAC_PRIVATE_SYNCWORD);
  Radio.Sleep();
  return DUCK_ERR_NONE;
}

int DuckRadio::sendData(byte* data, int length) {
  loginfo("Sending packet: len: " + String(length));
  Radio.Send(data, length);
  return DUCK_ERR_NONE;
}

int DuckRadio::sendData(std::vector<byte> data) {
  loginfo("Sending packet: len: " + String(data.size()));
  Radio.Send(data.data(), data.size());
  return DUCK_ERR_NONE;
}

int DuckRadio::relayPacket(DuckPacket* packet) {
  loginfo("Relaying packet: len: " + packet->getBuffer().size());
  Radio.Send(packet->getBuffer().data(), packet->getBuffer().size());
  return DUCK_ERR_NONE;
}

int DuckRadio::startReceive() {
  return DUCK_ERR_NONE;
}

int DuckRadio::readReceivedData(std::vector<byte>* packetBytes) {
  loginfo("readReceivedData....");
  return DUCK_ERR_NOT_SUPPORTED;
}

int DuckRadio::getRSSI() { return Radio.Rssi(MODEM_LORA); }

// TODO: implement this
int DuckRadio::ping() { return DUCK_ERR_NOT_SUPPORTED; }

int DuckRadio::standBy() {
  Radio.Standby();
  return DUCK_ERR_NONE;
}

void DuckRadio::processRadioIrq() { Radio.IrqProcess(); }
#endif