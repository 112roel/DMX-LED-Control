#pragma once

#include <FastLED.h>
#include <Arduino.h>
#include "dmxparameters.h"
#include "main.h"

void test();
void printTest(DMXPARAM &test);
void oneColor(DMXPARAM &p, CRGB *leds, int n);
void twoColor(DMXPARAM &p, CRGB *leds, int n);
void load(DMXPARAM &p, CRGB *leds, int n);
void clearEffects(DMXPARAM &p, CRGB *leds, int n);
void twinkle(DMXPARAM &p, CRGB *leds, int n);