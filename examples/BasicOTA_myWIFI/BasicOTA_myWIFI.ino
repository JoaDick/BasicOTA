/*******************************************************************************

Easy OTA update of ESP8266 or ESP32 for absolute beginners.
Prepare your sketch for future updates over-the-air by just adding two lines of
code.
Provide your WiFi's SSID and password below, and upload this sketch as usual
via USB. That's all; your device is now waiting for updates over-the-air!

*******************************************************************************/

// Create a file inside your Arduino's library folder and store your WIFI
// credentials there. That file has to be named "myWIFI.h" and will be used
// automatically by BasicOTA. So you won't have to store your WiFi credentials
// inside any arduino sketch.
// Example: Arduino/libraries/_credentials/myWIFI.h
// #define WIFI_SSID       "MyWifiSSID"
// #define WIFI_PASSWORD   "MyTopSecretPassword"

// Alternatively, uncomment these lines and insert your WiFi credentials here:
//#define WIFI_SSID       "..."
//#define WIFI_PASSWORD   "..."

#include <BasicOTA_myWIFI.h>

//------------------------------------------------------------------------------

void setup()
{
  Serial.begin(115200);

  BasicOTA.begin("BasicOTA");

  // your code here...

#ifdef LED_BUILTIN
  pinMode(LED_BUILTIN, OUTPUT);
#endif
}

//------------------------------------------------------------------------------

void loop()
{
  BasicOTA.handle();

  // your code here...

  delay(500);
#ifdef LED_BUILTIN
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
#endif
}

//------------------------------------------------------------------------------
