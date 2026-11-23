#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_DotStar.h>
//#include "stimulus/headers/fry.h"
//#include "stimulus/headers/marge.h"
//#include "stimulus/headers/melinoe.h"
#include "perry.h"
//#include "stimulus/headers/slugcat.h"

#define PROGRESS_DELAY 20 // delay between pixels in the load
#define FRAME_DELAY 250 //delay between "frames"/columns (25?)
#define DISPLAY_DUR 250
#define LOOPS 1
#define ITR_DELAY 100

#define X PERRY_WIDTH
//#define X 10
#define Y PERRY_HEIGHT  // The number of LEDs (pixels) on WS2812B
#define IMG perry

Adafruit_DotStar strip(X); //Hardware SPI
uint8_t *buffer = strip.getPixels();

void setup() {
    strip.begin();
}

void loop(){
    strip.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called
    strip.show();
    // turn pixels to green one by one with delay between each pixel, as a progress bar between images
    for (int pixel = 0; pixel < Y; pixel++) {           // for each pixel
        strip.setPixelColor(pixel, strip.Color(0, 255, 0));  // it only takes effect if pixels.show() is called should be green
        strip.show();

        delay(PROGRESS_DELAY);  // pause between each pixel
    }

    strip.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called
    strip.show();

    for(int k = 0; k < LOOPS; k++){
        //Each frame (x)
        for(int i = 0; i < Y; i++){ //column
            for(int j = 0; j < X; j++){
                uint32_t color = pgm_read_dword(&IMG[i * X + j]);
                strip.setPixelColor(j, color);
            }
            strip.show();                                  
            delay(DISPLAY_DUR);
        }
        delay(ITR_DELAY);
    }
}