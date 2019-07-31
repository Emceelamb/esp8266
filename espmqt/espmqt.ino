#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid="Just Another WiFi";
const char* pass="reallyeasy";

const char* mqttServer="192.168.8.1";
const int mqttPort=1883;
const char* mqttUser="tumbleweed";
const char* mqttPass="mosquitto";

WiFiClient espClient;
PubSubClient client(espClient);

void setup(){

    Serial.begin(115200);
    WiFi.begin(ssid, pass);
    Serial.println();
    Serial.println("Connecting to WiFi.");
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print('.');
    }

    Serial.println("Connected to the WiFi network.");

    client.setServer(mqttServer, mqttPort);
    // client.setCallback(callback);
    client.setCallback(callback);
    while(!client.connected()){

        Serial.println("Connecting to mosquitto...");
        if(client.connect("ESP8266Client", mqttUser, mqttPass)){
            Serial.println("Connected to mosquitto.");
        } else {
            Serial.print("Failed with State ");
            Serial.print(client.state());
            delay(1000);
        }
    }

    client.publish("esp/test", "Hello from a little device");
    client.subscribe("esp/test");
}

void callback(char* topic, byte* payload, unsigned int length){
    Serial.println("##########");
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);

    Serial.print("Message: ");
    for(int i = 0; i< length; i++){
        Serial.print((char)payload[i]);     
    }

    Serial.println();
    Serial.println("##########");
}

void loop(){
    client.loop();
}
