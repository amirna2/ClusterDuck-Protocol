#include "include/DuckCrypto.h"
#include "include/DuckUtils.h"

#if !defined (CDPCFG_HELTEC_CUBE_CELL)
#include <Crypto.h>
#include <AES.h>
#include <CTR.h>
// Initializing the cipher (CTR with AES256)
CTR<AES256> ctraes256;

void DuckCrypto::setEncrypt(bool state) { encryptOn = state; }

bool DuckCrypto::getState() { return encryptOn; }

void DuckCrypto::encryptData(byte *clearData, byte *encryptedData,
                             size_t inc) {
  size_t posn, len;

  ctraes256.clear();
  ctraes256.setKey(KEY, 32);
  ctraes256.setIV(IV, 16);
  ctraes256.setCounterSize(4);

  for (posn = 0; posn < inc; posn += inc) {
    len = inc - posn;
    if (len > inc) len = inc;
    ctraes256.encrypt(encryptedData + posn, clearData + posn, len);
  }
}

void DuckCrypto::decryptData(byte *encryptedData, byte *clearData,
                             size_t inc) {
  size_t posn, len;

  ctraes256.clear();
  ctraes256.setKey(KEY, 32);
  ctraes256.setIV(IV, 16);
  ctraes256.setCounterSize(4);

  for (posn = 0; posn < inc; posn += inc) {
    len = inc - posn;
    if (len > inc) len = inc;
    ctraes256.encrypt(clearData + posn, encryptedData + posn, len);
  }
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