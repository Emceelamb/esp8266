#include <SPI.h>
#include <ESP8266WiFi.h>

#define LED D1

const char* SSID = "Just Another WiFi";
const char* PASS = "reallyeasy";

int frequency=2600;
//
//const int LED=4;
const int piezo=13;

int timeOn=1000;
int timeOff=1000;

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

    pinMode(LED, OUTPUT);
}

void loop(){
    Serial.print("RSSI: ");
    Serial.println(WiFi.RSSI());
    // delay(100);
    int geiger=map(WiFi.RSSI(),-90,-30,10,1500);
    // delay(100);
    
    tone(piezo, frequency);
    digitalWrite(LED, HIGH);
    
    delay(100);
    
    digitalWrite(LED, LOW);
    noTone(piezo);
    delay(geiger);;
    
}
