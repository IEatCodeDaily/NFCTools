#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "RFID_reader.h"



/**
 * Initialize.
 */
void setup() {

  Serial.begin(500000); // Initialize serial communications with the PC

  SPI.begin();// Init SPI bus
  rfid.PCD_Init();  // Init MFRC522 board.
  MFRC522Debug::PCD_DumpVersionToSerial(rfid, Serial);	// Show details of PCD - MFRC522 Card Reader details.
	Serial.println("Scan PICC to see UID, SAK, type, and data blocks...");
  
}

/**
 * Main loop.
 */
void loop() {
  memdump();
}


