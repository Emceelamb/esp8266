# How to set up VS Code as your esp IDE

1. Install Arduino extension
2. Install Esp8266fs extension
3. Add to ESP to board manager
   3a. Press `F1` or `Ctrl+Shift+P` to bring up command pallet
   3b. Select Arduino: Board Manager
   3c. Select Additional URLS 
   3d. Search for Arduino: Additonal Urls and select `Edit in settings.json`
   3e. Add `"arduino.additionalUrls": "http://arduino.esp8266.com/stable/package_esp8266com_index.json"`
4. Reload Arduino Board Manager and install esp8266 board
5. Select Programmer, Board, and port
6. Upload using Ctrl+Alt+U

**Make sure your Arduino sketch/folder is initialized**
