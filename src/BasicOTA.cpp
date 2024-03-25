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

#include "BasicOTA.h"

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#elif defined(ESP32)
#include <WiFi.h>
#include <ESPmDNS.h>
#else
#error "This library only supports ESP8266 and ESP32."
#endif

#include <ArduinoOTA.h>

//------------------------------------------------------------------------------

void BasicOTA_Class::begin(const String &ssid,
                           const String &password,
                           const String &hostname,
                           uint16_t otaTimeout)
{
    ArduinoOTA.setHostname(hostname.c_str());

    Serial.println("");
    Serial.println("Connecting WIFI...");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("Connection Failed! Rebooting...");
        delay(3000);
        ESP.restart();
    }

    ArduinoOTA.onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
            type = "sketch";
        else // U_SPIFFS
            type = "filesystem";

        // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
        Serial.println("Start updating " + type);
    });

    ArduinoOTA.onEnd([]() {
        Serial.println("\nEnd");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });

    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR)
            Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR)
            Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR)
            Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR)
            Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR)
            Serial.println("End Failed");
        else
            Serial.println("(unknown)");
    });

    ArduinoOTA.begin();

    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    enable(otaTimeout);
}

//------------------------------------------------------------------------------

void BasicOTA_Class::enable(uint16_t timeout)
{
    if (timeout)
    {
        if (timeout == 1)
        {
            Serial.println("OTA enabled");
            _otaTimeout = timeout;
        }
        else
        {
            Serial.print("OTA enabled for ");
            Serial.print(timeout);
            Serial.println("s");
            _otaTimeout = timeout * 1000ul + millis();
        }
    }
    else
    {
        Serial.println("OTA disabled");
        _otaTimeout = 0;
    }
}

//------------------------------------------------------------------------------

void BasicOTA_Class::handle()
{
    if (_otaTimeout)
    {
        if (_otaTimeout == 1 ||
            _otaTimeout > millis())
        {
            ArduinoOTA.handle();
        }
        else
        {
            enable(0);
        }
    }
}

//------------------------------------------------------------------------------

BasicOTA_Class BasicOTA;

//------------------------------------------------------------------------------
