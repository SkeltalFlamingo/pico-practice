#include <stdio.h>
#include "pico/stdlib.h"

// Initialize chosen GPIO pins
#define LED_COUNT 4
const uint LED_PINS[LED_COUNT] = {7, 11, 13, 15};

void initLEDPin(int ledIndex) {
    gpio_init(LED_PINS[ledIndex]);
    gpio_set_dir(LED_PINS[ledIndex], GPIO_OUT);
}

int main()
{
    stdio_init_all();
    
    for (int index = 0 ; index < LED_COUNT ; index++) {
        initLEDPin(index);
    }

    while (true) {

        for (int index = 0 ; index < LED_COUNT ; index++) {
            gpio_put(LED_PINS[index], 1);  // LED ON
            sleep_ms(200);         // wait 500 ms
            gpio_put(LED_PINS[index], 0);  // LED OFF
            sleep_ms(200);
        }

        printf("Hello, world!\n");
    }
}
