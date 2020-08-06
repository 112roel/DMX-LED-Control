#include "main.h"

/* 
Initialize LEDS
*/

#define MAX_LEDS 150    // Max number of LEDS
#define DATA_PIN 5      // Data pin for leds
#define LED_TYPE WS2811 // Type of LEDS
#define COLOR_ORDER GRB // Color order (usually GRB)
int NUM_LEDS = 0;       // Number of LEDS
int led;
CRGB leds[MAX_LEDS]; // Define the array of leds

/*
Parameters
*/
const int ledPin = 13; // Onboard LED-Pin for testing

/*
DMX Settings
*/
#define DMX_SLAVE_CHANNELS 10
DMX_Slave dmx_slave(DMX_SLAVE_CHANNELS); // Configure a DMX slave controller
unsigned long lastFrameReceivedTime;
const unsigned long dmxTimeoutMillis = 10000UL;

DMXPARAM parameters; //parameter class

// Setup
void setup()
{

  delay(3000); // 3 second delay for boot recovery, and a moment of silence
  /*
  Start LEDS, first one green, last one RED, to check length of array.
  */
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, MAX_LEDS).setCorrection(TypicalLEDStrip); // Add LEDS
  led_count(NUM_LEDS);                                                                             // Set number of LEDS
  FastLED.setBrightness(100);                                                                      // Set brigthness
  leds[0] = CRGB(0, 255, 0);                                                                       // First led Green
  FastLED.show();
  delay(100);
  for (int i = 1; i < NUM_LEDS - 1; i++)
  {
    leds[i] = CRGB(255, 150, 0);
    FastLED.show();
    delay(100);
  }
  leds[NUM_LEDS - 1] = CRGB(255, 0, 0); // Last led red
  FastLED.show();

  delay(5000);
  FastLED.setBrightness(0);
  FastLED.show();
  delay(5000);
  Timer1.stop();
  Timer1.attachInterrupt(addEffectStep);
  // Start DMX stuff
  dmx_slave.enable();
  // Set start address to 1, this is also the default setting
  // You can change this address at any time during the program
  dmx_slave.setStartAddress(1);
  //
  // Register on frame complete event to determine signal timeout
  //
  dmx_slave.onReceiveComplete(OnFrameReceiveComplete);

  int *dmx_input;
  dmx_input = fake_dmx();

  parameters.setDMX(dmx_input);
  clearEffects(parameters, leds, NUM_LEDS);
  delay(5000);
}

void loop()
{
  FastLED.setBrightness(parameters.getBrightness());

  loadLoop(parameters, leds, NUM_LEDS);

  FastLED.show();
  readSpeed();

  // Get current time
  unsigned long now = millis();

  // If we didn't receive a DMX frame within the timeout period
  // clear all dmx channels
  if (now - lastFrameReceivedTime > dmxTimeoutMillis)
    dmx_slave.getBuffer().clear();
}

// Interrupt function for adding effect step
void addEffectStep(void)
{
  parameters.addEffectStep(NUM_LEDS);
}

// Converts speed from 10 to 255 to speed 0 to 20 Hz
void readSpeed(void)
{

  int buffer = 10;
  double max = 255;
  double minHz = log(0.1);
  double maxHz = log(20);
  double scale = (maxHz - minHz) / (max - buffer);
  unsigned long period = 0;

  if (parameters.getSpeed() < buffer + 1)
  {
    Timer1.stop();
  }
  else
  {
    double freq = exp(minHz + scale * ((parameters.getSpeed() - buffer)));
    period = (unsigned long)((1 / freq) * 1000000);
    Timer1.initialize(period);
  }
}

void OnFrameReceiveComplete(unsigned short channelsReceived)
{
  if (channelsReceived == DMX_SLAVE_CHANNELS)
  {
    // All slave channels have been received
  }
  else
  {
    digitalWrite(ledPin, HIGH);
  }

  // Update receive time to determine signal timeout
  lastFrameReceivedTime = millis();
}
