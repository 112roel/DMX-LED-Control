#pragma once

#include <FastLED.h>

class DMXPARAM
{
private:
    CRGB color1, color2;
    int brightness, speed, effectNumber, effectStep, effectChange; // Speed parameter (0 to 255)

public:
    DMXPARAM();

    void resetEffectStep(void);

    void addEffectStep(int &NUM_LEDS);

    /* Function for setting values*/
    void setDMX(int *dmx_input);
    int getSpeed() { return speed; }
    CRGB getColor1() { return color1; }
    CRGB getColor2() { return color2; }
    int getStep() { return effectStep; }
    int getBrightness() { return brightness; }
};