#include "effects.h"

/*

}*/

void test()
{
    Serial.print("test");
}

void printTest(DMXPARAM &test)
{
    Serial.print(test.getBrightness());
}

void oneColor(DMXPARAM &p, CRGB *leds, int n)
{
    for (int i = 0; i < n; i++)
    {
        leds[i] = p.getColor1();
    }
}

void twoColor(DMXPARAM &p, CRGB *leds, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            leds[i] = p.getColor1();
        }
        else
        {
            leds[i] = p.getColor2();
        }
    }
}

void twinkle(DMXPARAM &p, CRGB *leds, int n)
{
    if (p.getStep() % 2 == 0)
    {
        for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            leds[i] = p.getColor1();
        }
        else
        {
            leds[i] = p.getColor2();
        }
    }
    }
    else
    {
        for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            leds[i] = p.getColor2();
        }
        else
        {
            leds[i] = p.getColor1();
        }
    }
    }
}

void load(DMXPARAM &p, CRGB *leds, int n)
{
    leds[p.getStep()] = p.getColor1();
}

void clearEffects(DMXPARAM &p, CRGB *leds, int n)
{
    // Clear leds
    for (int i = 0; i < n; i++)
    {
        leds[i] = CRGB::Black;
    }
    // Clear effect step
    p.resetEffectStep();
}