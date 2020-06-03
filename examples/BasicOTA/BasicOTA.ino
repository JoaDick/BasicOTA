/*******************************************************************************

Easy OTA update of ESP8266 or ESP32 for absolute beginners.
Prepare your sketch for future updates over-the-air by just adding two lines of
code.
Provide your WiFi's SSID and password below, and upload this sketch as usual
via USB. That's all; your device is now waiting for updates over-the-air!

*******************************************************************************/

// Insert your WiFi credentials here.
#define WIFI_SSID       "..."
#define WIFI_PASSWORD   "..."
// Or have a look at BasicOTA_myWIFI.ino for a way that you don't have to store
// your WiFi credentials inside any arduino sketch.

#include <BasicOTA.h>

//------------------------------------------------------------------------------

void setup()
{
  Serial.begin(115200);

  BasicOTA.begin(WIFI_SSID, WIFI_PASSWORD, "BasicOTA");

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
