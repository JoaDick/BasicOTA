#pragma once
/*******************************************************************************

MIT License

Copyright (c) 2020 Joachim Dick

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*******************************************************************************/

#include <Arduino.h>

//------------------------------------------------------------------------------

/** Provide easy OTA support for beginners.
 * Call BasicOTA.begin() in your sketch's setup() and BasicOTA.handle() in its
 * loop() - and your device is ready for over-the-air updates!
 * Supports ESP8266 and ESP32.
 */
class BasicOTA_Class
{
public:
#if defined(WIFI_SSID) && defined(WIFI_PASSWORD)
  /** Prepare OTA.
   * Call this method from your sketch's setup()
   * Obtains WiFi SSID and Password from the macros WIFI_SSID and WIFI_PASSWORD.
   * @param hostname    This device's name
   * @param otaTimeout  Enable OTA for that number of seconds.
   * \a otaTimeout = 1 Means enable OTA without timeout (default).
   * \a otaTimeout = 0 Means disable OTA.
   */
  void begin(const String &hostname,
             uint16_t otaTimeout = 1)
  {
    begin(WIFI_SSID, WIFI_PASSWORD, hostname, otaTimeout);
  }
#endif

  /** Prepare OTA.
   * Call this method from your sketch's setup()
   * @param ssid        SSID of your WiFi
   * @param password    Password of your WiFi
   * @param hostname    This device's name
   * @param otaTimeout  Enable OTA for that number of seconds.
   * \a otaTimeout = 1 Means enable OTA without timeout (default).
   * \a otaTimeout = 0 Means disable OTA.
   */
  void begin(const String &ssid,
             const String &password,
             const String &hostname,
             uint16_t otaTimeout = 1);

  /// Disable OTA.
  void disable()
  {
    enable(0);
  }

  /** Enable OTA.
   * @param timeout Enable OTA for that number of seconds.
   * \a timeout = 1 Means enable OTA without timeout (default).
   * \a timeout = 0 Means disable OTA.
   */
  void enable(uint16_t timeout = 1);

  /// Check if OTA is enabled.
  bool isEnabled() const
  {
    return _otaTimeout > 0;
  }

  /** Process OTA.
   * Call this method periodically from your sketch's loop()
   */
  void handle();

private:
  uint32_t _otaTimeout = 0;
};

//------------------------------------------------------------------------------

extern BasicOTA_Class BasicOTA;

//------------------------------------------------------------------------------
