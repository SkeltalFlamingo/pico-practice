#include <stdio.h>
#include "pico/stdlib.h"
#include "LEDs.h"
#include "patterns.h"
#include <stdbool.h>

int main()
{
    stdio_init_all();
    initLEDPins();

    while (true) {

        patternChase();

        printf("Hello, world!\n");
    }
}
