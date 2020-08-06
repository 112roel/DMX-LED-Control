#include "input.h"

void led_count(int& n)
{
    // Function for getting number of LED's
    n = 6;
}

int dmx_start(void){
    // Function for getting DMX channel
    int dmx = 1;
    return dmx;
}

int * fake_dmx(void){
    static int r[10];
    for (int i = 0; i < 7; i++)
    {
        r[i] = rand() % 256;

    }
    r[7] = 150; // effectspeed
    r[8] = 0; // effectselect
    r[9] = 3; // spacing

    return r;
}