#pragma once

#include <Arduino.h>
#include <Conceptinetics.h>

void led_count(int& n);
int dmx_start(void);
void dmx_read(DMX_Slave *slave);
int * fake_dmx(void);