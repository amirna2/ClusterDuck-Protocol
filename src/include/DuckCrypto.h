#pragma once

/**
 * @file DuckCrypto.h
 * @brief This file is internal to CDP and provides the library access to
 * encryption functions.
 *
 * @version
 * @date 2021-02-10
 *
 * @copyright
 */
#include <Arduino.h>
#include "../DuckLogger.h"

class DuckCrypto {

   public:
      /**
       * @brief Construct a new DuckCrypto object.
       * 
       */
      DuckCrypto() {}

      /**
       * @brief Enable or Disable encryption
       * @param state encryption is enabled when set to true and disabled when set to false.
       */
      void setEncrypt(bool state);

      /**
       * @brief Get the State object
       * 
       * @return true if encryption is enabled
       * @return false  if encryption is disabled
       */
      bool getState();

      /**
       * @brief Encrypts a duck packet data section
       * 
       * @param clearData the data section to encrypt
       * @param encryptedData the encrypted data 
       * @param inc the size of the clear data
       */
      void encryptData(byte* clearData, byte* encryptedData, size_t inc);
      /**
       * @brief Decrypts enconded data
       * 
       * @param encryptedData the encrypted data to decode
       * @param clearData the decrypted data
       * @param inc size of the decrypted data
       */
      void decryptData(byte* encryptedData, byte* clearData, size_t inc);

      /**
       * @brief Set the AES key
       * 
       * @param newKEY AES key
       */
      void setAESKey(byte newKEY[32]);

      /**
       * @brief  set the AES IV key
       * 
       * @param newIV  IV key
       */
      void setAESIV(byte newIV[16]);
   
   private:
   
      bool encryptOn = false;
      byte KEY[32] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
                        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                        0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};

      byte IV[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
};
