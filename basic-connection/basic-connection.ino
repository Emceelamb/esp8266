#include <ESP8266WiFi.h>

const char* networkSSID = "Just another WiFi";
const char* networkPass = "reallyeasy";
    
void setup()
{
  Serial.begin(115200);
  delay(10);

  Serial.println('\n');

  WiFi.begin(networkSSID, networkPass);
  Serial.print(networkSSID); Serial.println('....');

  int i = 0;
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }
  Serial.println('\n');
    Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}

void loop()
{
}
