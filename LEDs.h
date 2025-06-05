#ifndef LEDS_H
#define LEDS_H

#define LED_COUNT 4
extern const uint LED_PINS[LED_COUNT];

void initLEDPin(int ledIndex);

void initLEDPins();

void LEDOn(int LEDIndex);

void LEDOff(int LEDIndex);

#endif // LEDS_H