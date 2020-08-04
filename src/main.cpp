#include "main.h"

// DMX SETUP
#define DMX_SLAVE_CHANNELS 10
// Configure a DMX slave controller
//DMX_Slave dmx_slave(DMX_SLAVE_CHANNELS);

const int ledPin = 13;

unsigned long lastFrameReceivedTime;
const unsigned long dmxTimeoutMillis = 10000;

// LED STRIP SETUP
// How many leds in your strip?
#define MAX_LEDS 150

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 5
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
int NUM_LEDS = led_count();
int led;
CRGB color1 = CRGB::Blue;
CRGB color2 = CRGB::Green;
// Define the array of leds
CRGB leds[MAX_LEDS];



void setup()
{
  delay(3000); // 3 second delay for boot recovery, and a moment of silence
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, MAX_LEDS).setCorrection(TypicalLEDStrip);
  int NUM_LEDS = led_count();
  leds[0] = CRGB::Green;
  FastLED.setBrightness(100);
  FastLED.show();
  delay(100);
  for (int i = 1; i < NUM_LEDS - 1; i++)
  {
    leds[i] = CRGB::Orange;
    FastLED.show();
    delay(100);
  }
  leds[NUM_LEDS - 1] = CRGB::Red;
  FastLED.show();

  int startAddress = dmx_start();
  delay(5000);
  // Enable DMX slave interface and start recording
  // DMX data
  //dmx_slave.enable();

  // Set start address to 1, this is also the default setting
  // You can change this address at any time during the program
  //dmx_slave.setStartAddress(startAddress);

  //
  // Register on frame complete event to determine signal timeout
  //
  //dmx_slave.onReceiveComplete(OnFrameReceiveComplete);

  // Set led pin as output pin
  pinMode(ledPin, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(blinkLED); // blinkLED to run every 0.15 seconds
  int led = 0;
  lastFrameReceivedTime = millis();
}

void loop()
{

  // Get current time
  unsigned long now = millis();

  // If we didn't receive a DMX frame within the timeout period
  // clear all dmx channels
  if ( now - lastFrameReceivedTime > dmxTimeoutMillis ){
    color2 = CRGB::Red;
    Timer1.initialize(100000);
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

// The interrupt will blink the LED, and keep
// track of how many times it has blinked.
int ledState = LOW;

void blinkLED(void)
{
  if (ledState == LOW)
  {
    Serial.print("state = low");
    Serial.print(NUM_LEDS);
    Serial.print("\n");
    for (int i = 0; i < NUM_LEDS; i++)
    {
      Serial.print("\n" + i);
      if (i % 2 == 0)
      {
        
        leds[i] = color1;
      }
      else
      {
        leds[i] = color2;
      }
    }
    ledState = HIGH;
  }
  else
  {

    for (int i = 0; i < NUM_LEDS; i++)
    {
      if (i % 2 == 0)
      {
        leds[i] = color2;
      }
      else
      {
        leds[i] = color1;
      }
    }
    ledState = LOW;
  }

  digitalWrite(ledPin, ledState);
  FastLED.show();
}