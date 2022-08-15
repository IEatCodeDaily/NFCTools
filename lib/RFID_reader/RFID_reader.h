#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
//#include <MFRC522DriverI2C.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

extern MFRC522DriverPinSimple ss_pin;

extern MFRC522DriverSPI driver; // Create SPI driver.
//extern MFRC522DriverI2C driver{}; // Create I2C driver.
extern MFRC522 rfid;  // Create MFRC522 instance.

void read_uid();
void memdump();