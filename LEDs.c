
#include "pico/stdlib.h"
#include "LEDs.h"

const uint LED_PINS[LED_COUNT] = {7, 11, 13, 15};

void initLEDPin(int ledIndex) {
    gpio_init(LED_PINS[ledIndex]);
    gpio_set_dir(LED_PINS[ledIndex], GPIO_OUT);
}

void initLEDPins() {
    for (int index = 0 ; index < LED_COUNT ; index++) {
        initLEDPin(index);
    }
}

void LEDOn(int LEDIndex) {
  gpio_put(LED_PINS[LEDIndex], 1);
}

void LEDOff(int LEDIndex) {
  gpio_put(LED_PINS[LEDIndex], 0);
}