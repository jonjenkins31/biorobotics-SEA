
/***************************************************************************************
 * 
    Notes   : This code is for use with an Arduino Uno and LCD/button shield. The
              intent is for anyone to use this program to give them a starting
              program with a fully functional menu with minimal modifications
              required by the user.

 ***************************************************************************************/

//LEFT SIDE LED CONTROL
// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.

void colorWipe1(uint32_t color, int wait,int limit) {
  int pixelorder[] = {9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
  
//turn on pixels 
  if (pixelj<18) {
    if (millis() > pixel_t + wait) {
       int pixel =  pixelorder[pixelj];
           if (pixelj < limit) {
           strip.setPixelColor(pixel, color);         //  Set pixel's color (in RAM)
           strip.show();                               //  Update strip to match

         }
      pixelj=pixelj+1 ;
      pixel_t = millis();
    }
  }
  if(pixelj>18){                 // compleated updating led. restart from  pixl 0
      pixelj=0;
    }  
    
//turn off pixels 
  if (pixelji>1) {
    if (millis() > pixel_t + wait) {
      int pixel =  pixelorder[pixelji];
          if (pixelji > limit) {
          strip.setPixelColor(pixel, strip.Color(  0,   0,   0));         // / Black/off          
            strip.show();                          //  Update strip to match
            }
      pixelji=pixelji-1 ;
      pixel_t = millis();
    }
  }
  if(pixelji<1){                 // compleated updating led. restart from  pixl 0
      pixelji=18;
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




void bgcolorWipe(uint32_t color, int wait) {       // set color whole strip. Pass delay time (in ms) between frames.

  if (pixeli<strip.numPixels()) {
    if (millis() > pixel_t + wait) {
      strip.setPixelColor(pixeli, color);         //  Set pixel's color (in RAM)
      strip.show();                               //  Update strip to match
      pixeli=pixeli+1 ;
      pixel_t = millis();
    }
  }

  if(pixeli>strip.numPixels()){                 // compleated updating led. restart from  pixl 0
      pixeli=0;
    }  
}

  
void bgrainbow(int wait) {            // Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  
  if (pixeli<strip.numPixels()) {
    if (millis() > pixel_t + wait) {
     strip.rainbow(firstPixelHue);
         // Above line is equivalent to:
         // strip.rainbow(firstPixelHue, 1, 255, 255, true);
      strip.show();                          //  Update strip to match
      firstPixelHue += 256;
      pixel_t = millis();
    }
  }

  if(firstPixelHue > 5*65536){                 // BUTTON IS RELEASED INITIATE TASK
    firstPixelHue =0;
  }  
}
