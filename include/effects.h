#pragma once

#include <FastLED.h>
#include <Arduino.h>
#include "dmxparameters.h"
#include "main.h"

void oneColor(DMXPARAM &p, CRGB *leds, int n);
void twoColor(DMXPARAM &p, CRGB *leds, int n);
void loadLoop(DMXPARAM &p, CRGB *leds, int n);
void clearEffects(DMXPARAM &p, CRGB *leds, int n);
void twinkle(DMXPARAM &p, CRGB *leds, int n);
void walkingLight(DMXPARAM &p, CRGB *leds, int n);
void twoColorBlock(DMXPARAM &p, CRGB *leds, int n);
void twinkleBlock(DMXPARAM &p, CRGB *leds, int n);
void loadFollow(DMXPARAM &p, CRGB *leds, int n);
void loadChase(DMXPARAM &p, CRGB *leds, int n);
void strobe(DMXPARAM &p, CRGB *leds, int n);