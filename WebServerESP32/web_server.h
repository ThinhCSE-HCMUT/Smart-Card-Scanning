#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <HTTP_Method.h>
#include <Uri.h>
#include <WebServer.h>

#include "rfid_config.h"
#include "LittleFS.h"

String getContentType(String filename);
void setupWebServer();
void handleWebServer();
String generateTable();

#endif
