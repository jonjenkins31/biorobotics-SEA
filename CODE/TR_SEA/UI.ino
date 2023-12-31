
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
     /*      case 3:
            menuItem3();
            break;
        case 4:
            menuItem4();
            break;
          case 5:
            menuItem5();
            break;
*/

    }
    
}


// ****************  Main Loop *****************







void MainMenu() {

  // using a float and the
    display.clearDisplay();
    
  // SUB MENU 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,2);
    display.println("Main Menu");  
     
   //  SYSTEM STATUS;
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(4,14);
    display.println(menuItems[menuPage]);  
    display.display();
   
   //  Set LED color
   bgrainbow(.25);             // Flowing rainbow cycle along the whole strip

    
  if (activeButton == 1){
        activeButton = 0;

    switch (button) {

      case 1:  // This case will execute if the "LEFT" button is pressed
              //task
        break;
      case 2:  // This case will execute if the "UP" button is pressed
         if (menuPage > 1 ) {
         menuPage = menuPage - 1;
         serialprintv("Scroll Up  on page : ",menuPage);             // SERIAL INFORMATION FUNCTION

          } 
        break;
     case 3:  // This case will execute if the "DOWN" button is pressed
        if (menuPage < maxMenuPages) {
         menuPage = menuPage + 1;
         serialprintv("Scroll Down  on page : ",menuPage);             // SERIAL INFORMATION FUNCTION

          }
        break;
      case 4:  // This case will execute if the "RIGHT" button is pressed
              //task
        break;
      
      case 5:  // This case will execute if the "select/back" button is pressed
         activepage=menuPage;
         serialprintv("Page Selected : ",activepage);             // SERIAL INFORMATION FUNCTION

        break;
      }
    
    }
}




/***************************************************************************************
 * 
    Notes   : This code is for use with an Arduino Uno and LCD/button shield. The
              intent is for anyone to use this program to give them a starting
              program with a fully functional menu with minimal modifications
              required by the user.
                
                BUTTON = 1 :   LEFT
                
                BUTTON = 2 :   UP 
                
                BUTTON = 3 :   DOWN
                
                BUTTON = 4 :   RIGHT 
                  
                BUTTON = 5 :   SELECT
 ***************************************************************************************/



 
void input(){

readKey = analogRead(key_pad_pin);                            // UPDATE CURRENT STATE OF BUTTON 1  

  if(readKey <= 800 && buttonlimit == LOW){                  // PRESS INITIATED
     lcdbutton = readKey;                                    // Store the value of the input detected
     buttonlimit = HIGH;                                     // logic bit that identify that the button has been recorded and to limit repeated commands
   }
    
   if (readKey >= 800 && buttonlimit == HIGH ){              // WAIT TILL BUTTON IS RELEASED
       buttonlimit = LOW;                                    // reset limit bit
        if (lcdbutton < 50) {                                // determain desired command pressed
          serialprint("UP BUTTON PRESSED : S1");             // SERIAL INFORMATION FUNCTION
          button = 2; // Up;
        } else if (lcdbutton < 200) {
          serialprint("LEFT BUTTON PRESSED : S2");             // SERIAL INFORMATION FUNCTION
          button = 1; // LEFT;
        } else if (lcdbutton < 400) {
          serialprint("DOWN BUTTON PRESSED : S3");             // SERIAL INFORMATION FUNCTION
          button = 3; // down;
        } else if (lcdbutton < 600) {
          serialprint("RIGHT BUTTON PRESSED : S4");             // SERIAL INFORMATION FUNCTION
          button = 4; // Right
        }else if (lcdbutton < 800) {
          serialprint("SELECT BUTTON PRESSED : S5");             // SERIAL INFORMATION FUNCTION
          button = 5; // select 
        }
       activeButton = 1;                          // button value has been updated and will be used to execude command
     } 


  if (readKey >= 800 ){              // WAIT TILL BUTTON IS RELEASED
     buttonA = 0; 
        
        
     } 
   if(readKey <= 800 ){                  // PRESS INITIATED
      if (lcdbutton < 50) {                                // determain desired command pressed
            serialprint("UP BUTTON PRESSED : S1");             // SERIAL INFORMATION FUNCTION
            buttonA = 2; // Up;
          } else if (lcdbutton < 200) {
            serialprint("LEFT BUTTON PRESSED : S2");             // SERIAL INFORMATION FUNCTION
            buttonA = 1; // LEFT;
          } else if (lcdbutton < 400) {
            serialprint("DOWN BUTTON PRESSED : S3");             // SERIAL INFORMATION FUNCTION
            buttonA = 3; // down;
          } else if (lcdbutton < 600) {
            serialprint("RIGHT BUTTON PRESSED : S4");             // SERIAL INFORMATION FUNCTION
            buttonA = 4; // Right
          }else if (lcdbutton < 800) {
            serialprint("SELECT BUTTON PRESSED : S5");             // SERIAL INFORMATION FUNCTION
            buttonA = 5; // select 
          }
   }
}


// Send serial information.
void serialprintv(char text[], int variable) {
  if (SerialSensorMore == true) {
    Serial.print(text);
    Serial.println(variable);
  } 
}
void serialprint(char text[]) {
  if (SerialSensorMore == true) {
    Serial.println(text);
  } 
}
 
