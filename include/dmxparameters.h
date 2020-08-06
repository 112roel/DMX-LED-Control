#pragma once

#include <FastLED.h>

class DMXPARAM
{
private:
    CRGB color1, color2;
    int brightness, speed, effectNumber, effectStep, effectFull, effectSpacing; // Speed parameter (0 to 255)

public:
    DMXPARAM();

    void resetEffectStep(void);

    void addEffectStep(int &NUM_LEDS);

    /* Function for setting values*/
    void setDMX(int *dmx_input);
    int getSpeed() { return speed; }
    CRGB getColor(int color);
    int getStep() { return effectStep; }
    int getFull() { return effectFull; }
    int getSpacing() {return effectSpacing;}
    int getBrightness() { return brightness; }
};