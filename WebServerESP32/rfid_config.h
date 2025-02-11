#ifndef RFID_CONFIG_H
#define RFID_CONFIG_H
#include <SPI.h>

#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>

#include "time_config.h"
#include "uart_to_STM32.h"


#define SS_PIN 5
#define RST_PIN 0

struct CardInfo {
  String cardID;
  String name;
  String date;
  String time;
  bool isMember;
};
extern CardInfo scanHistory[10];
extern int scanCount;

extern String memberDatabase[];
extern String memberNames[];

void setupRFID();
void handleRFID();
uint32_t processCard(String cardID, String date, String time);

#endif
