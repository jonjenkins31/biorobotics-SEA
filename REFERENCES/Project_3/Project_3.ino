
/********************************************************************* 
   
    Name    : LCD Button Shield Menu
    Author  : Jonathan Jenkins
    Created : June 14, 2016
    Last Modified: June 14, 2016
    Version : 1.0
    
Key Information:
  - Revision 1.0
  - Board : Arduino
  - Screen : Monochrome OLEDs based on SSD1306
  - Screen : 128x32 size display using I2C 

  Referenced Examples
    - button cycler/ Neopixel/ adafruit library
    - HX711_ADC

 Notes   : This code is for use with an Arduino Uno and LCD/button shield. The
              intent is for anyone to use this program to give them a starting
              program with a fully functional menu with minimal modifications
              required by the user.
*********************************************************************/



 // **************** INCLUDE NECESSARY LIBRARIES *****************
 
#include <SPI.h>
#include <Wire.h>

// **************** GLOBAL CONSTANT VARIABLES *****************       // variables will not change:

// PRIMARY PIN VARIABLES:
  const int led_ring_pin      = 3;    //  DIGITAL 3 
  // On an arduino UNO:                   A4(SDA), A5(SCL) 
  const int key_pad_pin       = 7;    // ANALOG A7

  //HX711_ADC LoadCell1(HX711_dout, HX711_sck);
    //const int strain1DTpin  = 4; // Strain gage DT
    //const int strain1SCKpin = 5; // Strain gage SCK
   // const int strain2DTpin  = 6; // Strain gage DT
    //const int strain2SCKpin = 7; // Strain gage SCK


// SECONDARY PIN VARIEABLES PER PEROJECT:
  
  //TEST ARM
  const int potPin        = A3; //  the FSR and 10K pulldown
  
  //THRUST STAND 
   /* 
    const int armpin        = 2;  // input pullup
    const int testpin       = 7; // input pullup
    const int zeropin       = 4; // input pullup
    const int mosfetpin     = 5; // output
  */


 // ****************  GLOBAL VARIABLES (GLOBAL)*****************        // variables will change:

// PRIMARY PIN VARIABLES:
  int SerialSensorMore = true; // PUSH BUTTON 1 --- ARM 
  int pixelLT = 0;
  int pixelRT = 0 ;
  int straingage = 445.77; // strain gage value
  int straingage1 = 445.77; // strain gage value
  int straingage2 = 445.77; // strain gage value
  int hallReading = 445.77; // strain gage value
  int newState = 0; // strain gage value
  int oldState = 0; // strain gage value 
   int  sea_f1_measured = 100; // strain gage value 
  int  sea_f2_measured = 100; // strain gage value 
 
 // SECONDARY PIN VARIEABLES PER PEROJECT:
    //THRUST STAND 
   /* 
  int forceMeasured = 100; // PUSH BUTTON 1 --- ARM 
  int tempmeasured = 100; // PUSH BUTTON 1 --- ARM 
  int force2measured= 100; // PUSH BUTTON 1 --- ARM 
  int force1measured = 100; // PUSH BUTTON 1 --- ARM 
  int pushbutton1 = digitalRead(armpin); // PUSH BUTTON 1 --- ARM 
  int pushbutton2 = digitalRead(testpin); // PUSH BUTTON 2 --- TEST
  int pushbutton3 = digitalRead(zeropin); // PUSH BUTTON 3 --- ZERO
  int armfunction = LOW; // initiate arm change
  int testfunction = LOW; // initiate Static Thrust Test
  int zerofunction = LOW; // initiate Zeroing of gage
  int armlimit = LOW; //  arm button limit
  int testlimit = LOW; // test button limit
  int zerolimit = LOW; // zero button limit

  int armstate = 0; // arm control 
  int systemstate = 0; // system control 
  int armtime = 0; // arm delay timer
  int testtime = 0; // test program delay timer
        unsigned long int now = 0; 
        unsigned long int starttime = now;
        unsigned long int laptime = now-starttime;
  */


// **************** OLED LIBRARY *****************
//Required Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED SCREEN  SETUP
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...

// this is the Width and Height of Display which is 128 xy 32 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define XPOS 0
#define YPOS 1
#define DELTAY 2
double count=0;

// **************** NEOPIXEL LIBRARY *****************


// Simple demonstration on using an input device to trigger changes on your
// NeoPixels. Wire a momentary push button to connect from ground to a
// digital IO pin. When the button is pressed it will change to a new pixel
// animation. Initial state has all pixels off -- press the button once to
// start the first animation. As written, the button does not interrupt an
// animation in-progress, it works only when idle.
//Required Library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Digital IO pin connected to the button. This will be driven with a
// pull-up resistor so the switch pulls the pin to ground momentarily.

#define PIXEL_PIN    led_ring_pin  // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 35  // Number of NeoPixels

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)







// **************** HX711 SCALE LIBRARY *****************
#include <HX711_ADC.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif

//pins:
//const int HX711_dout = 9; //mcu > HX711 dout pin
//const int HX711_sck = 8; //mcu > HX711 sck pin
//HX711_ADC LoadCell1(HX711_dout, HX711_sck);
  const int strain1DTpin  = 4; // Strain gage DT
  const int strain1SCKpin = 5; // Strain gage SCK
  const int strain2DTpin  = 6; // Strain gage DT
  const int strain2SCKpin = 7; // Strain gage SCK

//HX711 constructor:
HX711_ADC LoadCell1(strain1DTpin, strain1SCKpin);
HX711_ADC LoadCell2(strain2DTpin, strain2SCKpin);

const int calVal_calVal_eepromAdress = 0;
unsigned long t = 0;



// ****************Menu *****************


// You can have up to 10 menu items in the menuItems[] array below without having to change the base programming at all. Name them however you'd like. Beyond 10 items, you will have to add additional "cases" in the switch/case
// section of the operateMainMenu() function below. You will also have to add additional void functions (i.e. menuItem11, menuItem12, etc.) to the program.
String menuItems[] = {"JR", "Thrust Stand", "SEA", "ARM", "Leg", "Neck", "Hand"};
// Navigation button variables
int readKey;
// Menu control variables
int menuPage = 0;
int maxMenuPages = 7 ; // amount f menu items
int activepage=0;
int activeButton;
int button=0;
int buttonlimit;
int lcdbutton=1000;



  

// ****************SETUP *****************
void setup() {
  Serial.begin(9600); 
  Serial.println();
  Serial.println("Starting...");
 mainsetup();
 
  Serial.println("READY");          

  delay(100);
}
// ****************End SETUP ***********************




// ****************  Main Loop *****************

void loop() {
    menu();         // Function that controls Oled Screen
 //neopixel();   // function that controls Neopixel state 
  //scale();   // function that controls gage zeroing   
 
}

// **************** End Main Loop *****************
