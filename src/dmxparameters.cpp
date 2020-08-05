#include "dmxparameters.h"

DMXPARAM::DMXPARAM()
{
    speed = 0;        // Speed parameter (0 to 255)
    effectNumber = 0; // Effect selector (0 to 255)
    effectStep = 0;   // Effect step selector (0 to MaxLed)
    effectChange = 0;
    color1 = CRGB::Black; // Color 1
    color2 = CRGB::Black; // Color 2
    Serial.print("Parameters Started");
}

void DMXPARAM::resetEffectStep(void)
{
    effectStep = 0;
}

void DMXPARAM::addEffectStep(int &NUM_LEDS)
{
    effectStep = (effectStep + 1) % NUM_LEDS;

    Serial.print("\nEffectstep: ");
    Serial.print(effectStep);
    Serial.print("\n");
}

/* Function for setting values*/
void DMXPARAM::setDMX(int *dmx_input)
{
    color1 = CRGB(dmx_input[1], dmx_input[2], dmx_input[3]);
    color2 = CRGB(dmx_input[4], dmx_input[5], dmx_input[6]);
    speed = dmx_input[7];
    effectNumber = dmx_input[8];
    brightness = dmx_input[0];
}
