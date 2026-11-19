#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_DotStar.h>
//#include "stimulus/headers/fry.h"
//#include "stimulus/headers/marge.h"
//#include "stimulus/headers/melinoe.h"
#include "stimulus/headers/perry.h"
//#include "stimulus/headers/slugcat.h"

#define Y 72  // The number of LEDs (pixels) on WS2812B
#define PROGRESS_DELAY 100 // delay between pixels in the load
#define FRAME_DELAY 250 //delay between "frames"/columns (25?)
#define LOOPS 10
#define ITR_DELAY 100
Adafruit_DotStar strip(Y, DOTSTAR_BRG); //Hardware SPI
uint8_t *buffer = strip.getPixels();

void setup() {
    strip.begin();
}

void loop(){
    strip.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

    // turn pixels to green one by one with delay between each pixel, as a progress bar between images
    for (int pixel = 0; pixel < Y; pixel++) {           // for each pixel
        strip.setPixelColor(pixel, strip.Color(0, 255, 0));  // it only takes effect if pixels.show() is called
        strip.show();

        delay(PROGRESS_DELAY);  // pause between each pixel
    }

    int x = PERRY_WIDTH; // get x value from image being shown, how many pixels
    strip.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called
    strip.show();

    for(int k = 0; k < LOOPS; k++){
        //Each frame (x)
        for(int i = 0; i < x; i++){ //column
            //put column in buffer
            memcpy(strip.getPixels(), perry[i], 3 * Y);
            strip.show();                                  
            delay(FRAME_DELAY);
        }
        delay(ITR_DELAY);
    }
}