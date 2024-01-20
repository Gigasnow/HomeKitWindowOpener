# HomeKitWindowOpener
A HomeSpan project based on https://github.com/HomeSpan/HomeSpan, tested on ESP32 C3, compatible with those normal window opener driver with active high signal.
For pairing information please visit the original project website above.

Wiring
pin 7: open signal,
pin 10: close signal,
gnd: common

The accessory type is chosen to be window instead of switch to make it more secure. It won't be invoked by Siri without authentication.
It may show a permanently loading state when opened in HomeKit due to unknown opening angle of the window. 
Further work could be done to manually calibrate the motor and estimate the angle position w.r.t. time.

There is a better example on SomfyPlus, check out at https://github.com/HomeSpan/SomfyPlus
