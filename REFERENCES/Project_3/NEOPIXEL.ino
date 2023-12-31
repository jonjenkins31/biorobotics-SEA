
/***************************************************************************************
 * 
    Notes   : This code is for use with an Arduino Uno and LCD/button shield. The
              intent is for anyone to use this program to give them a starting
              program with a fully functional menu with minimal modifications
              required by the user.

 ***************************************************************************************/





// ****************  Main Loop *****************


void neopixel() {

 colorWipe(strip.Color(255,   0,   0), 50); // Red
  colorWipe(strip.Color(  0, 255,   0), 50); // Green
  colorWipe(strip.Color(  0,   0, 255), 50); // Blue

  // Do a theater marquee effect in various colors...
  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  theaterChase(strip.Color(127,   0,   0), 50); // Red, half brightness
  theaterChase(strip.Color(  0,   0, 127), 50); // Blue, half brightness

  rainbow(10);             // Flowing rainbow cycle along the whole strip
  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant

  
  pixelLT = map (sea_f1_measured,0,500,0,18);
  pixelRT = map (sea_f2_measured,0,160,0,18);


    /*
 if (tempmeasured < 80) {
      colorWipe1(strip.Color(  0,   0, 255), 5,pixelLT);    // Blue            
      colorWipe2(strip.Color(  0,   0, 255), 5,pixelRT);    // Blue
  // We can set some threshholds to display how much pressure is roughly applied:
 }else if (tempmeasured < 90) {
      //colorWipe(strip.Color(  0,   0,   0), 5);    // Black/off          
      colorWipe1(strip.Color(  0, 255,   0), 5,pixelLT);    // Green 
      colorWipe2(strip.Color(  0, 255,   0), 5,pixelRT);    // Green 

  } else if (tempmeasured < 150) {
      colorWipe1(strip.Color(255,   0,   0), 5,pixelLT);    // Red
      colorWipe2(strip.Color(255,   0,   0), 5,pixelRT);    // Red
  }
*/

}



// ****************  Main Loop *****************









//LEFT SIDE LED CONTROL
// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.

void colorWipe1(uint32_t color, int wait,int limit) {
  int pixelorder[] = {9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
  
    for(int i=1; i<18; i++) { // For each pixel in strip...
     int pixel =  pixelorder[i];
      if (i < limit) {
           strip.setPixelColor(pixel, color);         //  Set pixel's color (in RAM)
         }
     strip.show();                          //  Update strip to match
      delay(wait); //  Pause for a moment 
    }
  
    for(int i=18; i>1; i--) { // For each pixel in strip...
    int pixel =  pixelorder[i];
    if (i > limit) {
          strip.setPixelColor(pixel, strip.Color(  0,   0,   0));         // / Black/off          
            strip.show();                          //  Update strip to match
      delay(wait); //  Pause for a moment 
      }
    }
}


//RIGHT SIDE LED CONTROL
// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
// 0-9 &26-35

void colorWipe2(uint32_t color, int wait, int limit) {
  int pixelorder[] = {9,8,7,6,5,4,3,2,1,0,34,33,32,31,30,29,28,27};
    for(int i=1; i<18; i++) { // For each pixel in strip...
     int pixel =  pixelorder[i];
      if (i < limit) {
           strip.setPixelColor(pixel, color);         //  Set pixel's color (in RAM)
         }
     strip.show();                          //  Update strip to match
      delay(wait); //  Pause for a moment 
    }
  
    for(int i=18; i>1; i--) { // For each pixel in strip...
    int pixel =  pixelorder[i];
    if (i > limit) {
          strip.setPixelColor(pixel, strip.Color(  0,   0,   0));         // / Black/off          
            strip.show();                          //  Update strip to match
      delay(wait); //  Pause for a moment 
      }
    }
}



// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}
