#include "effects.h"

void oneColor(DMXPARAM &p, CRGB *leds, int n)
{
    for (int i = 0; i < n; i++)
    {
        leds[i] = p.getColor(0);
    }
}

void twoColor(DMXPARAM &p, CRGB *leds, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % p.getSpacing() == 0)
        {
            leds[i] = p.getColor(0);
        }
        else
        {
            leds[i] = p.getColor(1);
        }
    }
}

void twoColorBlock(DMXPARAM &p, CRGB *leds, int n)
{
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % p.getSpacing() == 0)
        {
            if (flag == 1)
            {
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            leds[i] = p.getColor(flag);
        }
        else
        {
            leds[i] = p.getColor(flag);
        }
    }
}

void twinkle(DMXPARAM &p, CRGB *leds, int n)
{
    if (p.getStep() % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % p.getSpacing() == 0)
            {
                leds[i] = p.getColor(0);
            }
            else
            {
                leds[i] = p.getColor(1);
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i % p.getSpacing() == 0)
            {
                leds[i] = p.getColor(1);
            }
            else
            {
                leds[i] = p.getColor(0);
            }
        }
    }
}

void twinkleBlock(DMXPARAM &p, CRGB *leds, int n)
{
    int flag = 1;
    if (p.getStep() % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % p.getSpacing() == 0)
            {
                if (flag == 1)
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
                leds[i] = p.getColor(flag);
            }
            else
            {
                leds[i] = p.getColor(flag);
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i % p.getSpacing() == 0)
            {
                if (flag == 1)
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
                leds[i] = p.getColor(!flag);
            }
            else
            {
                leds[i] = p.getColor(!flag);
            }
        }
    }
}

void loadLoop(DMXPARAM &p, CRGB *leds, int n)
{
    if (p.getFull() == 0)
    {
        leds[p.getStep()] = p.getColor(0);
    }
    else
    {
        leds[n - p.getStep() - 1] = p.getColor(1);
    }
}

void loadFollow(DMXPARAM &p, CRGB *leds, int n)
{
    if (p.getFull() == 0)
    {
        leds[p.getStep()] = p.getColor(0);
    }
    else
    {
        leds[p.getStep()] = p.getColor(1);
    }
}

void loadChase(DMXPARAM &p, CRGB *leds, int n)
{
    int point = (p.getStep()+p.getSpacing()) % n;
        leds[p.getStep()] = p.getColor(0);
        leds[point] = p.getColor(1);
}

void walkingLight(DMXPARAM &p, CRGB *leds, int n)
{
    for (int i = 0; i < n; i++)
    {
        leds[i] = p.getColor(1);
    }
    leds[p.getStep()] = p.getColor(0);
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

void strobe(DMXPARAM &p, CRGB *leds, int n){
    for (int i = 0; i < n; i++)
    {
        leds[i] = p.getColor(0);
    }
    if (p.getStep() % 2 == 0){
        FastLED.setBrightness(255);
    }
    else{
        FastLED.setBrightness(0);
    }
    
}