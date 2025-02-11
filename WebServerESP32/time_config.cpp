#include "time_config.h"
#include <TimeLib.h> 

const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 7 * 3600; // Múi giờ GMT+7
const int daylightOffset_sec = 0;

void setupTime() {
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

String getCurrentDate() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    return "Unknown";
  }
  char dateBuffer[11];
  strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", &timeinfo);
  return String(dateBuffer);
}

String getCurrentTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    return "Unknown";
  }
  char timeBuffer[9];
  strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", &timeinfo);
  return String(timeBuffer);
}

