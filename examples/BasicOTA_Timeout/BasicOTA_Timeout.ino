/*******************************************************************************

Easy OTA update of ESP8266 or ESP32 for beginners.
Adding a timeout to BasicOTA.begin() will automatically disable OTA after that
time. This can be used as a security feature to prevent the device from
unintended or rogue updates. OTA is enabled again after a reset.

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

  // enable OTA for 60 seconds
  BasicOTA.begin("BasicOTA", 60);

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
  if (!BasicOTA.isEnabled())
  {
    // stop blinking when OTA timeout expired
    digitalWrite(LED_BUILTIN, 1);
  }
#endif
}

//------------------------------------------------------------------------------
