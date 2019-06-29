include <ESP8266WiFi.h>

const char* networkName = "MyLittleNetwork";
const char* passkey = "network123";
void setup()
{
      Serial.begin(115200);
        Serial.println();

          Serial.print("Setting soft-AP ... ");
            boolean result = WiFi.softAP(networkName, passkey);
              if(result == true)
                    {
                            Serial.println("Ready");
                              }
                                else
                                      {
                                              Serial.println("Failed!");
                                                }
}

void loop()
{
      Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
        delay(3000);
}
