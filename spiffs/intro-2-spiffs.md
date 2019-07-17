# Introduction to SPIFFS
The ESP8266 can serve files using the Seral Peripheral Interface Flash File System, or SPIFFS for short. SPIFFS is a light-weight file system for microcontrollers with an SPI flash chip. The onboard flash chip has enough space for webpages.

## Set up tools
* Download the tool: https://github.com/esp8266/arduino-esp8266fs-plugin/releases/download/0.4.0/ESP8266FS-0.4.0.zip
* In the Arduino sketchbook directory create `tools` directory if it does not exist.
* Unpack the tool into `tools` 
* Restart Arduino IDE

## Uploading Files to SPIFFS directory
* Open your sketch folder  
* Create a `data` folder
* Place files to upload in `data`
* Make sure Serial Monitor is closed
* Select `Tools > ESP8266 Sketch Data Upload`