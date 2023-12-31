
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


// ****************  Main Loop *****************

 
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
 
