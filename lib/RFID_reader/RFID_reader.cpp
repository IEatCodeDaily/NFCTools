#include "RFID_reader.h"

MFRC522DriverPinSimple ss_pin(21);

MFRC522DriverSPI driver{ss_pin}; // Create SPI driver.
//MFRC522DriverI2C driver{}; // Create I2C driver.
MFRC522 rfid{driver};  // Create MFRC522 instance.

void read_uid(){
  if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.print("RFID/NFC Tag Type: ");
      Serial.println(rfid.PICC_GetType(piccType));

      // print UID in Serial Monitor in the hex format
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
      }

    
      Serial.println();

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
}

void memdump(){
if ( !rfid.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards.
	if ( !rfid.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card; PICC_HaltA() is automatically called.
  MFRC522Debug::PICC_DumpToSerial(rfid, Serial, &(rfid.uid));
}