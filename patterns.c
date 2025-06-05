#include "patterns.h"
#include "pico/stdlib.h"
#include "LEDs.h"

void patternBlinkOnOff() {
    LEDOn(0);
    sleep_ms(200);

    LEDOff(0);
    sleep_ms(200);
}

void patternAlternate() {
  LEDOn(0);
  sleep_ms(200);

  LEDOff(0);
  LEDOn(1);
  sleep_ms(200);

  LEDOff(1);
}

void patternChase() {
  for (int index = 0 ; index < LED_COUNT ; index++) {

    gpio_put(LED_PINS[index], 1);
    sleep_ms(200);

    gpio_put(LED_PINS[index], 0);
    sleep_ms(200);
  }}
