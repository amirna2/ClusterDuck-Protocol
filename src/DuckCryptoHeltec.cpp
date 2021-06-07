#include "include/DuckCrypto.h"
#include "include/DuckUtils.h"

#if defined(CDPCFG_HELTEC_CUBE_CELL)
// Initializing the cipher (CTR with AES256)

void DuckCrypto::setEncrypt(bool state) { encryptOn = state; }

bool DuckCrypto::getState() { return encryptOn; }

void DuckCrypto::encryptData(byte *clearData, byte *encryptedData,
                             size_t inc) {
  encryptedData = clearData;
}

void DuckCrypto::decryptData(byte *encryptedData, byte *clearData,
                             size_t inc) {
  clearData = encryptedData;
}

void DuckCrypto::setAESKey(byte newKEY[32]) {
  for (int i = 0; i < 32; i++) {
    KEY[i] = newKEY[i];
  }
}

void DuckCrypto::setAESIV(byte newIV[16]) {
  for (int i = 0; i < 16; i++) {
    IV[i] = newIV[i];
  }
}
#endif