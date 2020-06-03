# Easy OTA update of ESP8266 or ESP32 for absolute beginners.

Prepare your sketch for future updates over-the-air by just adding two lines of code.

This library is intended as starting point for getting familiar with OTA updates without a too steep learning curve.
It intentionally offers a minimalistic interface and isn't bloated with lots of features and options.
Just use it to bring up your device and start developing. Over time, when you're deeper into the topic,
you likely want to use a more specific OTA mechanism and therefore a "bigger" OTA library with more possibilities.
Search on GitHub for "ESP OTA" and you'll see what I mean...

Eventually, I'd highly recommend to have a look at the
[ESPP8266 documentation on OTA](https://arduino-esp8266.readthedocs.io/en/latest/ota_updates/readme.html#application-example)
to learn about how to prepare the Arduino IDE for OTA updates.


## Examples

### `BasicOTA`
Most minimalistic example. Can be uploaded via USB without modifications (except WiFi credentials),
so that it is prepared for future OTA updates.

### `BasicOTA_myWIFI`
Same as `BasicOTA`, except that it introduces a nice trick to store the WiFi credentials outside the sketch,
so that they cannot get published by accident. The other examples also use this technique.

### `BasicOTA_Timeout`
Adding a timeout to BasicOTA.begin() will automatically disable OTA after that time.
This can be used as a security feature to prevent the device from unintended or rogue updates.
OTA is enabled again after a reset.


# Credits

This library has been heavily inspired by a [Video](https://www.youtube.com/watch?v=1pwqS_NUG7Q)
from [Andreas Spiess](https://github.com/SensorsIot). \
His [YouTube Channel](https://www.youtube.com/channel/UCu7_D0o48KbfhpEohoP7YSQ) is definitely worth having a closer look!
