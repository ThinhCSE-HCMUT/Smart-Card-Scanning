#include "rfid_config.h"

CardInfo scanHistory[10];
int scanCount = 0;
String memberDatabase[] = {"51293B2", "34211E74","849F2D74"};
String memberNames[] = {"Lê Nguyễn Phúc Thịnh", "Nguyễn Kim Thuận", "Phan Huy Trung"};
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setupRFID() {
  SPI.begin();
  mfrc522.PCD_Init();
}

void handleRFID() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String cardID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardID += String(mfrc522.uid.uidByte[i], HEX);
    }
    cardID.toUpperCase();

    String date = getCurrentDate();
    String time = getCurrentTime();

    uint32_t userIDSend = processCard(cardID, date, time);
    char message[4];
    mfrc522.PICC_HaltA();
    snprintf(message, sizeof(message), "%d", userIDSend);
    sendMessage(message);
  }
}

uint32_t processCard(String cardID, String date, String time) {
  String lastName = "Unknown";
  bool isMember = false;
  uint32_t userID = 5;

  for (int i = 0; i < sizeof(memberDatabase) / sizeof(memberDatabase[0]); i++) {
    if (memberDatabase[i] == cardID) {
      lastName = memberNames[i];
      isMember = true;
      userID = i;
      break;
    }
  }

  if (scanCount < 10) {
    scanHistory[scanCount++] = {cardID, lastName, date, time, isMember};
  }

  Serial.println("Card ID: " + cardID);
  Serial.println("Date: " + date + " Time: " + time);
  Serial.println("Member Status: " + String(isMember ? "Yes" : "No"));

  return userID;
}
