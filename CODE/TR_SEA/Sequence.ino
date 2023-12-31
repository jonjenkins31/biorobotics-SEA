
/***************************************************************************************
 * 
    Notes   : This code controls the animation of the servo. 
              Servo 1-4 connected to PWM Pins

 ***************************************************************************************/


// ****************  SUBMENUS *****************




void menuItem1() { // Function executes when you select the 3rd item from main menu
  // using a float and the
    display.clearDisplay();
    
  // SUB MENU 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(4,2);
    display.println("HOLD");  

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
       
        if( task2limit == false){                  // TASK INITIATED
         task2limit = true;                         // Set button limit to high. function can only run once per press:
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
    display.setCursor(60,2);
    display.println("Running");  

           //  task_laps_time=  millis()-task_start_time;

 

            if ((straingage < -.5) && (angle <85)){
                    digitalWrite(motor_on_pin,HIGH); 
                    digitalWrite(motor_direction_pin,HIGH);
                    }
           else if ((straingage > resistance) && (angle > -30)){
                   digitalWrite(motor_on_pin,HIGH);
                   digitalWrite(motor_direction_pin,LOW);
                   }
           else {
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






/*



 /*  Set LED color
     pixelLT = map (straingage,0,500,0,18);
  pixelRT = map (angle,-30,130,0,18);
      colorWipe1(strip.Color(  0,   0, 255), 5,pixelLT);    // Blue            
      colorWipe2(strip.Color(  0,   0, 255), 5,pixelRT);    // Blu

 
 pixelLT = map (sea_f1_measured,0,500,0,18);
    pixelRT = map (sea_f2_measured,0,160,0,18);
    
if (straingage < resistance) {
      colorWipe1(strip.Color(  0,   0, 255), 5,pixelLT);    // Blue            
      colorWipe2(strip.Color(  0,   0, 255), 5,pixelRT);    // Blue
 }else if (straingage >= resistance) {
      //colorWipe(strip.Color(  0,   0,   0), 5);    // Black/off          
      colorWipe1(strip.Color(  0, 255,   0), 5,pixelLT);    // Green 
      colorWipe2(strip.Color(  0, 255,   0), 5,pixelRT);    // Green 
      
  
   

  void SeaSweep((int desired_position, int position_hold_tollerance,int position_hold_force){

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
                  }

    
      if (millis() > pixel_t + wait) {

      pixel_t = millis();
    }
    

      if( int task2limit == LOW){                  // TASK INITIATED
        int task2limit = HIGH;                         // Set button limit to high. function can only run once per press:
        int starttime = millis(); 
      } 
        int laptime=  millis()-starttime;
 
        if((laptime >= 0) && (laptime <= 4000)){
          colorWipe(strip.Color(  0,   0, 255), 50);    // move to position     
        }
        if((laptime >= 4000) && (laptime <= 8000)){ // IGNITION
          colorWipe(strip.Color(  255,   255, 51), 50);    // Move to position   
        }
         if(laptime >= 8000){ // Back to standby
          task2 = LOW; // function complete set to low
          task2limit = LOW;
          starttime = 0;
          laptime = 0;
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off 
        }   



          
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

  
  if (angle<desired_position) {
    if (millis() > task_t + wait) {
      Seamotor(pos);              // tell servo to go to position in variable 'pos'
      pos=pos+1 ;
      task_t = millis();
    }
  }

}



void Seamotor(int desired_position, int position_hold_tollerance,int force){

    

    
      
      if( task2limit == false){                  // TASK INITIATED
         task2limit = true;                         // Set button limit to high. function can only run once per press:
        int starttime = millis(); 
      } 
        int laptime=  millis()-starttime;
  
        if((laptime >= 0) && (laptime <= 4000)){
          bgcolorWipe(strip.Color(  0,   0, 255), 50);    // Blue    
             // SETTINGS;
            display.setTextSize(2);
            display.setTextColor(WHITE);
            display.setCursor(4,14);
            display.print("Starting"); 
            display.display();
        }
        if((laptime >= 4000) && (laptime <= 8000)){ // IGNITION
          bgcolorWipe(strip.Color(  255,   255, 51), 50);    // YELLOW   
        }
         if((laptime >= 8000) && (laptime <= 25000)){   // COOLDOWN
           bgcolorWipe(strip.Color(  0,   0, 127), 50);    // Blue
        }
         if((laptime >= 25000) && (laptime <= 30000)){ // COMPLETED
          bgcolorWipe(strip.Color(  0, 255,   0), 50);    // Green
        }
         if(laptime >= 30000){ // Back to standby
          task2 = false; // function complete set to low
          task2limit = false;
          starttime = 0;
          laptime = 0;
          bgcolorWipe(strip.Color(  0,   0,   0), 50);    // Black/off 

*/
