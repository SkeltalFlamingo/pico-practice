#ifndef BUTTON_H
#define BUTTON_H
#include <stdbool.h>

#define BUTTON_PIN 0

void initButtonInterupt();

void handleButtonEvent();

#endif