#pragma once

#include <Arduino.h>
#include <FastLED.h>
#include "effects.h"
#include "input.h"
#include <Conceptinetics.h>
#include <TimerOne.h>

void OnFrameReceiveComplete (unsigned short channelsReceived);
void blinkLED(void);