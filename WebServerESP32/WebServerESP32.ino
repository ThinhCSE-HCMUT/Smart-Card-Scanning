#include "wifi_config.h"
#include "web_server.h"

// Khởi tạo hệ thống
void setup() {
  Serial.begin(115200);
  setupWiFi();          // Kết nối WiFi
  setupTime();          // Cấu hình NTP
  setupRFID();          // Khởi động RFID
  setupWebServer();     // Khởi động WebServer

  Serial.println("Place RFID card near the reader:");
  init_ua(); //set up uart

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

// Vòng lặp chính
void loop() {
  handleWebServer();    // Xử lý WebServer
  handleRFID();         // Xử lý quét thẻ RFID
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

