#include "button.h"
#include <stdbool.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "patterns.h"
#include <LEDs.h>

static bool isButtonPressed = false;

static void onButton(uint gpio, uint32_t events) {
  isButtonPressed = true;
}

void handleButtonEvent() {
  if (isButtonPressed) {
    changePattern();

    isButtonPressed = false;
  }
}

void initButtonInterupt() {
  gpio_init(BUTTON_PIN);
  gpio_set_dir(BUTTON_PIN, GPIO_IN);
  gpio_pull_up(BUTTON_PIN);

  gpio_set_irq_enabled_with_callback(
    BUTTON_PIN,
    GPIO_IRQ_EDGE_FALL,
    true,
    &onButton
  );
}
