#ifndef LEDS_H
#define LEDS_H

#define LED_COUNT 4
extern const uint LED_PINS[LED_COUNT];

void initLEDPin(unsigned short ledIndex);

void initLEDPins();

void LEDOn(unsigned short LEDIndex);

void LEDOff(unsigned short LEDIndex);

void LEDOffAll();

#endif // LEDS_H