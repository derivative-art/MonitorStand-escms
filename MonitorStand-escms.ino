/*
 Much of the code was taken from example project credit to Majenko Technologies
 
*/

#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <StreamString.h>
#include <WiFiClient.h>

#include "secrets.h"  // see extras,h for format of wifi creds
#include "extras.h"  //  web page contents

ESP8266WebServer server(80);




//  +---------------------------------------------------------------+
//  |                  PING SENSOR
//  +---------------------------------------------------------------+

int debug = 0;
const int trigPin = 12;
const int echoPin = 5;
// define sound speed in cm/uS
#define SOUND_SPEED 0.034
long duration;
float distanceCm;
float distanceInch;

int get_distance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance
  distanceCm = duration * 10 * SOUND_SPEED / 2;
  Serial.print("Distance (mm): ");
  int distancemm = int(round(distanceCm));
  Serial.println(distancemm);
  return distancemm;
}
 





//  +---------------------------------------------------------------+
//  |                 HANDEL
//  +---------------------------------------------------------------+
void handleRoot() {
  digitalWrite(LED_BUILTIN, 1);
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  int distancemm = get_distance();
  int movement = analogRead(A0);
  Serial.println(movement);
  char color[] = "<span style='color:white'>";
  if (distancemm > 300) {
    strncpy(color, "<span style='color:red'>", 27);
  }
  
  char movement_color[] = "<span style='color:white'>";
  if (movement > 100) {
    strncpy(movement_color, "<span style='color:red'>", 27);
  }

  StreamString temp;
  temp.reserve(500);  // Preallocate a large chunk to avoid memory fragmentation
  temp.printf(html_page, hr, min % 60, sec % 60, color, distancemm, movement_color, movement);
  server.send(200, "text/html", temp.c_str());
  digitalWrite(LED_BUILTIN, 0);
}



//  +---------------------------------------------------------------+
//  |                 404
//  +---------------------------------------------------------------+
void handleNotFound() {
  digitalWrite(LED_BUILTIN, 1);
  String message = "<!DOCTYPE html>\n<html> <title> why you no think good? </title><body> \n<h1>File Not Found</h1><p>\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\n<br>Method: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\n<br>Arguments: ";
  message += server.args();
  message += "<br></body></html>\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
  digitalWrite(LED_BUILTIN, 0);
}




//  +---------------------------------------------------------------+
//  |                 SVG draw
//  +---------------------------------------------------------------+
void drawGraph() {
  String out;
  out.reserve(2600);
  char temp[70];
  out +=
      "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"400\" "
      "height=\"150\">\n";
  out +=
      "<rect width=\"400\" height=\"150\" fill=\"rgb(250, 230, 210)\" "
      "stroke-width=\"1\" stroke=\"rgb(0, 0, 0)\" />\n";
  out += "<g stroke=\"black\">\n";
  int y = map(get_distance(), 0, 1800, 5, 130);
  for (int x = 10; x < 390; x += 10) {
    //  sampling at 1000/second, but this should be 1/390th
    delay(10);
    int y2 = map(get_distance(), 0, 1800, 5, 130);
    if ( debug == 1 ) { Serial.println(y2); }
    sprintf(
        temp,
        "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"2\" />\n",
        x, 140 - y, x + 10, 140 - y2);
    out += temp;
    y = y2;
  }
  out += "</g>\n</svg>\n";

  server.send(200, "image/svg+xml", out);
}



//  +---------------------------------------------------------------+
//  |                 SETUP
//  +---------------------------------------------------------------+
void setup(void) {
  //  #################################  PING SENSOR
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  //  #################################  PING SENSOR
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  if ( debug == 1 ) {  server.on("/test.svg", drawGraph); }
  server.on("/inline",
            []() { server.send(200, "text/plain", "this works as well"); });
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
