#include "web_server.h"

WebServer server(80);

// Serve files from LittleFS
void serveFile(const char* path, const char* contentType) {
  if (LittleFS.exists(path)) {
    File file = LittleFS.open(path, "r");
    server.streamFile(file, contentType);
    file.close();
  } else {
    server.send(404, "text/plain", "File Not Found");
  }
}

void setupWebServer() {
  if (!LittleFS.begin()) {
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }

  // Route for serving the main page
  server.on("/", HTTP_GET, []() {
    serveFile("/index.html", "text/html");
  });

  // Route for serving the CSS file
  server.on("/styles.css", HTTP_GET, []() {
    serveFile("/styles.css", "text/css");
  });

  // Route for serving the JavaScript file
  server.on("/scripts.js", HTTP_GET, []() {
    serveFile("/scripts.js", "application/javascript");
  });

  server.on("/images/logo.png", HTTP_GET, []() {
    serveFile("/images/logo.png", "image/png");
});


  // Route for serving table data
  server.on("/table", HTTP_GET, []() {
    server.send(200, "text/plain", generateTable());
  });

  server.begin();
  Serial.println("Web server started");
}

void handleWebServer() {
  server.handleClient();
}

// Example table data generator
String generateTable() {
  String tableRows = "";
  for (int i = 0; i < scanCount; i++) {
    tableRows += "<tr>";
    tableRows += "<td>" + String(i + 1) + "</td>";
    tableRows += "<td>" + scanHistory[i].cardID + "</td>";
    tableRows += "<td>" + scanHistory[i].name + "</td>";
    tableRows += "<td>" + scanHistory[i].date + "</td>";
    tableRows += "<td>" + scanHistory[i].time + "</td>";
    tableRows += "<td>" + String(scanHistory[i].isMember ? "Yes" : "No") + "</td>";
    tableRows += "</tr>";
  }
  return tableRows;
}