# ESP8266

Experiments using MicroPython

## Installing MicroPython on NodeMCU ESP (Windows)

First make a directory on your computer
    mkdir esp
    cd esp

Download MicroPython and place in folder
[Micropython](http://micropython.org/download#esp8266)

Make a virtual environment
`myvenv venv -m python3`

Activate virtual environment
`myvenv\Scripts\activate`

Pip install Esptool
`pip install esptool`

Erase flash on your Esp8266
`esptool.py --port <port connected port> erase_flash`

Deploy firmware
`esptool.py --port <port conneccted to> --baud 460800 write_flash --flash_size=detect 0 <downloaded Micropython bin>

Get MicroPython REPL
* Connect using PuTTY 
* Use Serial Connection
* Connect with port you are connected to 
* Speed 115200

Check Connection
`print("Hello my esp friend")`

## GPIO Pins
![GPIO Pints](https://raw.githubusercontent.com/Emceelamb/esp8266/master/nodemcu_pins.png)