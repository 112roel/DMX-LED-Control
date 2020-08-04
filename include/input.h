#pragma once

#include <Arduino.h>
#include <Conceptinetics.h>

int led_count(void);
int dmx_start(void);
void dmx_read(DMX_Slave *slave);