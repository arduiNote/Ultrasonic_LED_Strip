
#include <Adafruit_NeoPixel.h>
#include <HCSR04.h>

#define PIN        6 // Which pin on the Arduino is connected to the NeoPixels?

#define NUMPIXELS 29 // How many NeoPixels are attached to the Arduino?

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

UltraSonicDistanceSensor distanceSensor(9, 10);  // Initialize sensor that uses digital pins 13 and 12.


int current_Last_LED=0;

void setup() 
{  
  pixels.begin(); 
}

void loop() 
{
  
  pixels.clear();                               // Set all pixel colors to 'off'
  current_Last_LED=distanceSensor.measureDistanceCm()*0.8;
 
 
  for(int i=0; i<current_Last_LED; i++)                      // For each pixel in strip...
  { 
    pixels.setPixelColor(i, 0,0,255); 
  }
  
  pixels.show();                                  // Send the updated pixel colors to the hardware.
  
}


