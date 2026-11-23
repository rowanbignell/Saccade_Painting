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
#define DELAY 0

// Here's how to control the LEDs from any two pins:
#define DATAPIN    4
#define CLOCKPIN   5
//Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
Adafruit_DotStar strip(NUMPIXELS, DOTSTAR_BRG);

void setup() {

  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
}

void loop() {

  strip.fill(0xff0000);
  strip.show();
  delay(DELAY);
  strip.fill(0x00ff00);
  strip.show();
  delay(DELAY);
  strip.fill(0x0000ff);
  strip.show();
  delay(DELAY);



}
