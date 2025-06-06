#ifndef PATTERNS_H
#define PATTERNS_H


void patternBlinkOnOff();

void patternAlternate();

void patternChase();

#define PATTERN_COUNT 3
extern const void (*patterns[3])();
extern unsigned short activePatternIndex;

void changePattern();

#endif // PATTERNS_H