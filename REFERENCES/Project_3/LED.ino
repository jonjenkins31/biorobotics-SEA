
/***************************************************************************************
 * 
    Notes   : This code is for use with an Arduino Uno and LCD/button shield. The
              intent is for anyone to use this program to give them a starting
              program with a fully functional menu with minimal modifications
              required by the user.

 ***************************************************************************************/


// ****************  Main Loop *****************

 void menu() {

   input();     // function that obtains input value from keypad/buttons
   switch (activepage) { // The case that is selected here is dependent on which menu page you are on and where the cursor is.
          case 0:
            MainMenu();
            break;
          case 1:
            menuItem1();
            break;
          case 2:
            menuItem2();
            break;
          case 3:
            menuItem3();
            break;
          case 4:
            menuItem4();
            break;
          case 5:
            menuItem5();
            break;
    }
    
    delay(10);
}


// ****************  Main Loop *****************










// ****************  VOIDS *****************




void MainMenu() {

  // using a float and the
    display.clearDisplay();
    
  // SUB MENU 
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(4,2);
    display.println(menuItems[menuPage]);  
    display.display();


  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "LEFT" button is pressed
        Serial.println("+");
        delay(15);
        break;
      case 2:  // This case will execute if the "UP" button is pressed
         if (menuPage > 0 ) {
         menuPage = menuPage - 1;
          } 
         Serial.println("-");
        delay(15);
        break;
     case 3:  // This case will execute if the "DOWN" button is pressed
        if (menuPage < 10) {
         menuPage = menuPage + 1;
          }         Serial.println("+");
           Serial.println(menuPage);
        delay(15);
        break;
      case 4:  // This case will execute if the "RIGHT" button is pressed
        Serial.println("-");
        delay(15);
        break;
      
      case 5:  // This case will execute if the "select/back" button is pressed
       Serial.println("back");
        activepage=menuPage;
        break;
      }
    
    }
}




// ****************  SUBMENUS *****************



void menuItem1() { // Function executes when you select the 1st item from main menu
  // using a float and the
    display.clearDisplay();
    
  // SUB MENU 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,2);
    display.println("SUB MENU:");  
    
   // SETTINGS;
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(4,14);
    display.print('600');  
    display.print(' '); 
    display.print('N'); 
     

  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
        Serial.println("-");
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
      }
    
    }

  }






void menuItem2() { // Function executes when you select the 2nd item from main menu
 // UPDATE UI
 /*
    String gage =  String(straingage);// using a float and the
    display.clearDisplay();
    
   //  ARM STATUS;
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,2);
    switch (armstate) {
        case 0 :
                  display.println("DISARM"); //do something when var equals 1
                  break;
        case 1 :
                 display.println("ARM"); //do something when var equals 2
                  break;
        default :
                   display.println("ERROR");   // if nothing else matches, do the default
                  break;
    }
    
   //  GAGE STATUS;
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(70,2);
    display.print(gage);  
    display.print(' '); 
    display.print('N'); 
     
   //  SYSTEM STATUS;
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(4,14);
    switch (systemstate) {
      case 0 :
                display.println("BOOTING"); //do something when var equals 1
                break;
      case 1 :
                 display.println("STANDBY"); //do something when var equals 2
                break;
      case 2 :
                display.println("TEST FIRE"); 
                break;
      case 3 :
                display.println("IGNIITION"); 
                break;
      case 4 :
                display.println("COOLDOWN"); 
                break;
      case 5 :
                display.println("COMPLETED"); 
                break;
      case 6 :
                display.println("ARM ERROR"); 
                break;
    }
    display.display();
    
*/
  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
         Serial.println("-");
        delay(15);
        break;
      
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
    }

    
  }
  }

     


void menuItem3() { // Function executes when you select the 3rd item from main menu
  // using a float and the
    display.clearDisplay();
    
  // SUB MENU 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,2);
    display.println("SUB MENU:");  
    
   // SETTINGS;
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(4,14);
    display.print('600');  
    display.print(' '); 
    display.print('N'); 

  if (activeButton == 1){
        activeButton = 0;
    switch (button) {
      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
        Serial.println("-");
        delay(15);
        break;
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
      }
    }
}

void menuItem4() { // Function executes when you select the 4th item from main menu
  // using a float and the
    display.clearDisplay();
    
  // SUB MENU 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,2);
    display.println("SUB MENU:");  
    
   // SETTINGS;
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(4,14);
    display.print('600');  
    display.print(' '); 
    display.print('N'); 

  if (activeButton == 1){
        activeButton = 0;
    switch (button) {
      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
        Serial.println("-");
        delay(15);
        break;
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
      }
    }
}

void menuItem5() { // Function executes when you select the 5th item from main menu
  // using a float and the
    display.clearDisplay();
    
  // SUB MENU 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,2);
    display.println("SUB MENU:");  
    
   // SETTINGS;
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(4,14);
    display.print('600');  
    display.print(' '); 
    display.print('N'); 

  if (activeButton == 1){
        activeButton = 0;
    switch (button) {
      case 1:  // This case will execute if the "right" button is pressed
        Serial.println("+");
        delay(15);
        break;
      case 4:  // This case will execute if the "left" button is pressed
        Serial.println("-");
        delay(15);
        break;
      case 5:  // This case will execute if the "back" button is pressed
       Serial.println("back");
        activepage=0;
        break;
      }
    }
}
