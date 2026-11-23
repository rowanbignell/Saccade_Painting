//From strandtest.ino in the <Adafruit_DotStar.h> source code.

// Simple strand test for Adafruit Dot Star RGB LED strip.
// This is a basic diagnostic tool, NOT a graphics demo...helps confirm
// correct wiring and tests each pixel's ability to display red, green
// and blue and to forward data down the line.  By limiting the number
// and color of LEDs, it's reasonably safe to power a couple meters off
// the Arduino's 5V pin.  DON'T try that with other code!

#include <Adafruit_DotStar.h>
#include <SPI.h>
#define NUMPIXELS 144 // Number of LEDs in strip
Adafruit_DotStar strip(NUMPIXELS, DOTSTAR_BRG);

void setup() {

  strip.begin(); // Initialize pins for output
  strip.clear();
  strip.show();  // Turn all LEDs off ASAP
}

void loop() {
}
