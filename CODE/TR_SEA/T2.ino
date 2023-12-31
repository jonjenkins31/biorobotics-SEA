
void menuItem2() { // Function executes when you select the 3rd item from main menu
// using a float and the
    display.clearDisplay();
    
  // SUB MENU 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,2);
    display.println("Oscillate");  

   // SETTINGS;
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,14);
    display.print("N:"); 
    display.print(straingage);  
    display.print(" / "); 
    display.print(resistance); 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,25);
    display.print("Angle:"); 
    display.println(angle); 

 //  Set LED color
   bgrainbow(.25);             // Flowing rainbow cycle along the whole strip





// INPUT RECEIVED
  if (activeButton == 1){
        activeButton = 0;
    switch (button) {
      case 1:  // This case will execute if the "LEFT" button is pressed
      resistance = resistance - 1;
        break;
      case 2:  // This case will execute if the "UP" button is pressed
         task = !task;                                     // turn Armfunction high:  arm fuction will run once
       
        if( task == true){                  // TASK INITIATED
        int starttime = millis(); 
          }
        
        break;
     case 3:  // This case will execute if the "DOWN" button is pressed
                 Serial.println("Tare attempted");
         LoadCell.tareNoDelay();
          // check if last tare operation is complete:
          if (LoadCell.getTareStatus() == true) {
            Serial.println("Tare complete");
          }
        break;
      case 4:  // This case will execute if the "RIGHT" button is pressed
         resistance = resistance +1;
        break;
      case 5:  // This case will execute if the "back" button is pressed
         task = false;  
         activepage=0;
        break;
     
   }
  }

 // TASKS
  if(task == true){                 // BUTTON IS RELEASED INITIATE TASK


    // SUB MENU 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(65,2);
    display.println("Running");  
         

        int laptime=  millis()-starttime;
       
        if((laptime >= 0) && (laptime <= 4000)){        ///  MOVE T0 75 

        int desired_position = 75;
           position_hold_tollerance =0;
         if (laptime < 1000) {
                          position_hold_tollerance =0;
                          }
                          
            if (straingage < 2){
       
                  if (angle < desired_position-position_hold_tollerance) {
                          digitalWrite(motor_on_pin,HIGH); 
                          digitalWrite(motor_direction_pin,HIGH);
                          }
                  else if (angle > desired_position+position_hold_tollerance) {
                         digitalWrite(motor_on_pin,HIGH);
                         digitalWrite(motor_direction_pin,LOW);
                         }
                  else {
                        digitalWrite(motor_on_pin,LOW); 
                        digitalWrite(motor_direction_pin,LOW);
                        position_hold_tollerance =5;

                        }       
            }
            if (straingage >2){
                        digitalWrite(motor_on_pin,LOW); 
                        digitalWrite(motor_direction_pin,LOW);
                        }       
             
            }
        
         if((laptime >= 4000) && (laptime <= 8000)){   // COOLDOWN //  Move to 40 (down)

           
            int desired_position = 50;
                if (laptime < 2000) {
                                      position_hold_tollerance =0;
                                      }

              if (straingage >-.5){
                   if (angle < desired_position-position_hold_tollerance) {
                          digitalWrite(motor_on_pin,HIGH); 
                          digitalWrite(motor_direction_pin,HIGH);
                          }
                  else if (angle > desired_position+position_hold_tollerance) {
                         digitalWrite(motor_on_pin,HIGH);
                         digitalWrite(motor_direction_pin,LOW);
                         }
                  else {
                        digitalWrite(motor_on_pin,LOW); 
                        digitalWrite(motor_direction_pin,LOW);
                              position_hold_tollerance =5;
                        }       
              }
           if (straingage <-.5){
                        digitalWrite(motor_on_pin,LOW); 
                        digitalWrite(motor_direction_pin,LOW);
                        }       
              }
            
         
         if(laptime >= 8000){ // Back to standby
          //task2 = LOW; // function complete set to low
          starttime = millis();
                  digitalWrite(motor_on_pin,LOW); 
                  digitalWrite(motor_direction_pin,LOW);
        }    



  
             

}



          
    

 if(task == false){                 // BUTTON IS RELEASED INITIATE TASK
  // SUB MENU 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(60,2);
    display.println("Stand By");  

    // Set outputs off
    digitalWrite(motor_on_pin,LOW); 
    digitalWrite(motor_direction_pin,LOW);
 }


//Update LCD Display once per loop
    display.display();


}
