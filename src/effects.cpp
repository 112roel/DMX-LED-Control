#include "effects.h"

void flicker(CRGB *leds)
{
    // Turn the LED on, then pause
    leds[0] = CRGB::Green;
    FastLED.show();
    delay(500);
    // Now turn the LED off, then pause
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(500);
}