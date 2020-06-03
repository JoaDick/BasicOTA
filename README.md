# Easy OTA update of ESP8266 or ESP32 for absolute beginners.

Prepare your sketch for future updates over-the-air by just adding two lines of code.

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
