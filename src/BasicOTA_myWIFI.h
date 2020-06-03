#pragma once

//------------------------------------------------------------------------------

// Define your WiFi credentials in a file named "myWIFI.h" inside your
// Arduino's library folder, so you won't have to store them inside any Arduino
// sketch.
// Example: Arduino/libraries/_credentials/myWIFI.h
// #define WIFI_SSID       "MyWifiSSID"
// #define WIFI_PASSWORD   "MyTopSecretPassword"
// Alternatively, put these two #defines in your sketch, before #including
// this file.
#if !defined(WIFI_SSID) || !defined(WIFI_PASSWORD)
#undef WIFI_SSID
#undef WIFI_PASSWORD
#include <myWIFI.h>
#endif

//------------------------------------------------------------------------------

#include <BasicOTA.h>

//------------------------------------------------------------------------------
