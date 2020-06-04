/*******************************************************************************

Easy OTA update of ESP8266 or ESP32 for beginners.
When developing with your device OTA you usually don't have access to the serial
console anymore. As an alternative, you can use a telnet connection to send the
messages over network.
Use e.g. PuTTY (https://www.putty.org/) as replacement for the Serial Monitor.

This example depends on the TelnetStream library:
https://github.com/jandrassy/TelnetStream

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
#include <TelnetStream.h>

//------------------------------------------------------------------------------

void setup()
{
  Serial.begin(115200);

  BasicOTA.begin("BasicOTA");
  TelnetStream.begin();

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

  doSomething();
  delay(500);
#ifdef LED_BUILTIN
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
#endif
}

//------------------------------------------------------------------------------

void doSomething()
{
  static uint32_t trigger = 0;
  const uint32_t now = millis();

  if(now > trigger)
  {
    TelnetStream.print("Uptime: ");
    TelnetStream.println(now);
    trigger += 1000;
  }
}

//------------------------------------------------------------------------------
