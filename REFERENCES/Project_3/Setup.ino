// ****************   SETUP *****************


//Call in main setup void
void mainsetup() {


// ****************  OLED SETUP *****************
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();

// ****************  NEOPIXEL SETUP *****************
 // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
/*

// ****************  Scale 1 SETUP *****************
  float calibrationValue; // calibration value
  calibrationValue = 40771.77; // uncomment this if you want to set this value in the sketch
#if defined(ESP8266) || defined(ESP32)
  //EEPROM.begin(512); // uncomment this if you use ESP8266 and want to fetch this value from eeprom
#endif
  //EEPROM.get(calVal_eepromAdress, calibrationValue); // uncomment this if you want to fetch this value from eeprom
  LoadCell1.begin();
  unsigned long stabilizingtime = 2000; // tare preciscion can be improved by adding a few seconds of stabilizing time
  boolean _tare = true; //set this to false if you don't want tare to be performed in the next step
  LoadCell1.start(stabilizingtime, _tare);
  
   if (LoadCell1.getTareTimeoutFlag()) {
  }
  else {
    LoadCell1.setCalFactor(calibrationValue); // set calibration factor (float)
  }
  while (!LoadCell1.update());
 



// ****************  Scale 2 SETUP *****************
  calibrationValue = 40771.77; // uncomment this if you want to set this value in the sketch
#if defined(ESP8266) || defined(ESP32)
  //EEPROM.begin(512); // uncomment this if you use ESP8266 and want to fetch this value from eeprom
#endif
  //EEPROM.get(calVal_eepromAdress, calibrationValue); // uncomment this if you want to fetch this value from eeprom
  LoadCell2.begin();
  LoadCell2.start(stabilizingtime, _tare);
  
   if (LoadCell2.getTareTimeoutFlag()) {
  }
  else {
    LoadCell2.setCalFactor(calibrationValue); // set calibration factor (float)
  }
  while (!LoadCell2.update());

*/

// ****************  IO SETUP *****************
  
   
   // initialize Digital Input and Outputs

   //THRUST STAND 
   /* 
     pinMode(mosfetpin, OUTPUT);
     pinMode(armpin,INPUT_PULLUP); 
     pinMode(testpin,INPUT_PULLUP);
     pinMode(zeropin,INPUT_PULLUP);
     digitalWrite(mosfetpin,LOW);
     systemstate=1;
  */




}


// ****************  SETUP END *****************
