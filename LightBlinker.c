#include <stdio.h>
#include "pico/stdlib.h"
#include "LEDs.h"
#include "patterns.h"
#include "button.h"
#include <stdbool.h>

int main()
{
    stdio_init_all();
    initLEDPins();

    initButtonInterupt();

    while (true) {

        patterns[activePatternIndex]();

        printf("Hello, world!\n");

        handleButtonEvent();
    }
}
