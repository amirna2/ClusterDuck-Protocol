#include "include/DuckUtils.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace duckutils {

  namespace {
    std::string cdpVersion = "2.9.7";
  }

volatile bool interruptEnabled = true;
Timer<> duckTimer = timer_create_default();
bool detectState = false;

volatile bool isInterruptEnabled() { return interruptEnabled; }
void setInterrupt(bool enable) { interruptEnabled = enable; }

std::string getCDPVersion() {
  return cdpVersion;
}

Timer<> getTimer() { return duckTimer; }

bool getDetectState() { return detectState; }
bool flipDetectState() {
  detectState = !detectState;
  return detectState;

}

void getRandomBytes(int length, byte* bytes) {
  const char* digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i;
  for (i = 0; i < length; i++) {
    // TODO: Random generator here isn't seeded properly
    // We can use RSSI value to seed it or use a frame counter if available
#ifdef CDPCFG_HELTEC_CUBE_CELL   
    int pos = random(strlen(digits) - 1);
#else
    int pos = random(0, strlen(digits) - 1);
#endif    
    bytes[i] = digits[pos];
  }
}

String createUuid(int length) {
  String msg = "";
  int i;

  for (i = 0; i < length; i++) {
#ifdef CDPCFG_HELTEC_CUBE_CELL   
    byte randomValue = random (36);
#else
  byte randomValue = random(0, 36);
#endif
    if (randomValue < 26) {
      msg = msg + char(randomValue + 'a');
    } else {
      msg = msg + char((randomValue - 26) + '0');
    }
  }
  return msg;
}

String convertToHex(byte* data, int size) {
  String buf = "";
  buf.reserve(size * 2); // 2 digit hex
  const char* cs = "0123456789ABCDEF";
  for (int i = 0; i < size; i++) {
    byte val = data[i];
    buf += cs[(val >> 4) & 0x0F];
    buf += cs[val & 0x0F];
  }
  return buf;
}

uint32_t toUnit32(byte* data) {
    uint32_t value = 0;

    value |= data[0] << 24;
    value |= data[1] << 16;
    value |= data[2] << 8;
    value |= data[3];
    return value;
}

} // namespace duckutils