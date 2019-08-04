#include <ESP8266.WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266mDNS.h>

ESP8266WiFimulti wifiMulti;

void setup() {
    Serial.begin(115200);
    delay(10);
    Serial.println('\n');
}