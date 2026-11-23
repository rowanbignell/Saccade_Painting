#include <Arduino.h>
#include <SPI.h>
#include <FastLED.h>
#include <avr/pgmspace.h>
//#include "fry.h"
//#include "marge.h"
//#include "melinoe.h"
#include "perry.h"
//#include "slugcat.h"

#define DATA_PIN 11
#define CLOCK_PIN 13

#define LOOPS 10
#define DELAY 0

#define X PERRY_WIDTH
#define Y PERRY_HEIGHT
CRGB leds[X];

void setup() {
    FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, X);
    //FastLED.setBrightness(100);
    FastLED.clear(true);
}

void loop(){
        for(int i = 0; i < Y; i++){ //column
            memcpy_P((void*)leds, (const void*)&perry[i * X], X * sizeof(CRGB)); 
            FastLED.show();
            //FastLED.delay(DELAY);
        }
}