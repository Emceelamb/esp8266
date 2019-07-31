#include <SPI.h>
#include <ESP8266WiFi.h>

const char* SSID = "<ssid>";
const char* PASS = "<pass>";

void setup(){
    Serial.begin(115200);
    WiFi.begin(SSID, PASS);

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(SSID);

    int i = 0;
    
    while(WiFi.status() != WL_CONNECTED){
        delay(1000);
        Serial.print(++i); Serial.print('.');
    }
    Serial.println('\n');
        Serial.println('\n');
    Serial.println("Connection established!");  
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());  
}
void loop(){
    Serial.println(WiFi.RSSI());
    delay(100);
}
