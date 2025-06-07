#include "patterns.h"
#include "pico/stdlib.h"
#include "LEDs.h"
#include "pico/time.h"
#include <stdbool.h>
#include "utils.h"
#include <stdio.h>

void blinkOnOffStep0(){LEDOn(0);}
void blinkOnOffStep1(){LEDOff(0);}
const pattern_step blinkOnOffSteps[2] = {blinkOnOffStep0, blinkOnOffStep1};

void alternateStep0(){
  LEDOff(1);
  LEDOn(0);
}
void alternateStep1(){
  LEDOff(0);
  LEDOn(1);
}
const pattern_step alternateSteps[2] = {alternateStep0, alternateStep1};

void chaseStep(unsigned short onLedIndex){
  const unsigned short PREV_ON_LED_INDEX = (onLedIndex - 1 >= 0) ? onLedIndex - 1 : LED_COUNT - 1;
  LEDOff(PREV_ON_LED_INDEX);
  LEDOn(onLedIndex);
}
void chaseStep0() {chaseStep(0);}
void chaseStep1() {chaseStep(1);}
void chaseStep2() {chaseStep(2);}
void chaseStep3() {chaseStep(3);}
const pattern_step chaseSteps[4] = {chaseStep0, chaseStep1, chaseStep2, chaseStep3};

const struct Pattern patterns[] = {
  {
    .stepCount = 2,
    .steps = blinkOnOffSteps,
  },
  {
    .stepCount = 2,
    .steps = alternateSteps,
  },
  {
    .stepCount = 4,
    .steps = chaseSteps,
  },
};
unsigned short activePatternIndex = 0;
unsigned short currentPatternStep = 0;

void doPatternStep() {
  struct Pattern activePattern = patterns[activePatternIndex];

  activePattern.steps[currentPatternStep]();

  currentPatternStep = getNextCycleIndex(currentPatternStep, activePattern.stepCount);
}

void changePattern() {
  LEDOffAll();
  activePatternIndex = getNextCycleIndex(activePatternIndex, PATTERN_COUNT);
  currentPatternStep = 0;
  return;
}
