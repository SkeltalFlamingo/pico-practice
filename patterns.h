#ifndef PATTERNS_H
#define PATTERNS_H


typedef void (*pattern_step)();
struct Pattern {
  unsigned short stepCount;
  pattern_step *steps;
};

#define PATTERN_COUNT 3
extern const struct Pattern patterns[PATTERN_COUNT];
extern unsigned short activePatternIndex;

void changePattern();
void doPatternStep();

#endif // PATTERNS_H