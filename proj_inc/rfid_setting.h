#ifndef RFID_SETTING_H
#define RFID_SETTING_H



// RFID
#define GPIO_MOSI 12
#define GPIO_MISO 13
#define GPIO_SCLK 15
#define GPIO_CS 14

// RFID global var
char sendbuf[129]="";
char recvbuf[129]="";
spi_slave_transaction_t t;

// RFID prototypes
void rfidInit();
void rfidGetYoloSettings();
S
#endif
