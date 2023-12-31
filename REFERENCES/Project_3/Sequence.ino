
/***************************************************************************************
 * 
    Notes   : This code controls the animation of the servo. 
              Servo 1-4 connected to PWM Pins

 ***************************************************************************************/



/*
void arm(){

pushbutton1 = digitalRead(armpin); // UPDATE CURRENT STATE OF BUTTON 1  

  if(pushbutton1 == LOW && armlimit == LOW){                  // PRESS INITIATED
      armlimit = HIGH;                                        // Set button limit to high. function can only run once per press:
      armfunction = HIGH;                                     // turn Armfunction high:  arm fuction will run once
   } 
  if(pushbutton1 == HIGH && armlimit == HIGH){                // WAIT TILL BUTTON IS RELEASED
        armlimit = LOW;                                        // reset button limit. 
  } 

  if(armfunction == HIGH && armlimit == LOW){                 // BUTTON IS RELEASED INITIATE TASK
     armstate = !armstate; // toggle Arm State 0/1
     armfunction = LOW; // function complete set to low
  }

    
}


void test(){

   pushbutton2 = digitalRead(testpin); // UPDATE CURRENT STATE OF BUTTON 2  

  if(pushbutton2 == LOW && testlimit == LOW){                  // PRESS INITIATED
      testlimit = HIGH;                                        // Set button limit to high. function can only run once per press:
      testfunction = HIGH;                                     // turn Armfunction high:  arm fuction will run once
      now = millis(); 
      starttime = now; 
   } 
  if(pushbutton2 == HIGH && testlimit == HIGH){                // WAIT TILL BUTTON IS RELEASED
        testlimit = LOW;                                        // reset button limit. 
        now = millis(); 
        laptime = now-starttime;
  } 

  if(testfunction == HIGH && testlimit == LOW && armstate == 1){                 // BUTTON IS RELEASED INITIATE TASK
        now = millis();
        laptime= now-starttime;
     
        
        if((laptime >= 0) && (laptime <= 4000)){
          systemstate = 2;// START DELAY 
    
        }
        if((laptime >= 4000) && (laptime <= 8000)){ // IGNITION
          digitalWrite(mosfetpin,HIGH);
          systemstate = 3; // IGNITION
        }
         if((laptime >= 8000) && (laptime <= 25000)){   // COOLDOWN
          digitalWrite(mosfetpin,LOW); 
          systemstate = 4; //COOL DOWN
        }
         if((laptime >= 25000) && (laptime <= 30000)){ // COMPLETED
          systemstate = 5; // COMPLETED
        }
         if(laptime >= 30000){ // Back to standby
          testfunction = LOW; // function complete set to low
          systemstate = 1;  // Standby 
          now = 0;
          starttime = 0;
          laptime = now-starttime;
        }            
  }


  if(testfunction == HIGH && testlimit == LOW && armstate == 0){                 // BUTTON IS RELEASED INITIATE TASK    
   now = millis();
   laptime = now-starttime;
    systemstate = 6;//  Set system into Error ... Please ARM 
       if(laptime>=3000){ // Back to standby
              testfunction = LOW; // function complete set to low
              systemstate = 1;  // Standby 
              now = 0;
              starttime = 0;
              laptime = now-starttime;
          }
  }
}



void zero(){
  
    pushbutton3 = digitalRead(zeropin); // PUSH BUTTON 3 --- ZERO

   if(pushbutton3 == LOW && zerolimit == LOW){
      zerolimit = HIGH; // Set button limit to high. function can only run once per press:
      zerofunction = HIGH;   // test fuction will run once
   } 
  if(pushbutton3 == HIGH && zerolimit == HIGH){
      zerolimit = LOW;         // reset button limit. 
  } 

  if(zerofunction == HIGH && zerolimit == LOW){
    LoadCell1.tareNoDelay();
    zerofunction = LOW; // function complete set to low
  }






// receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell2.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell2.getTareStatus() == true) {
    Serial.println("Tare complete");
  }





  
}









/*
void servo() {
   servonewState = servotask;      // Get current button state.

if (servooldState != servonewState) {    // Check if state changed from high to low (button press).

    switch (servotask) {                    // The case that is selected here is dependent on which menu page you are on and where the cursor is.
          case 0:
            opengrip();
            break;
          case 1:
            grip1();
            break;
          case 2:
            grip2();
            break;
          case 3:
            grip3();
            break;
         
        }
        // Set the last-read button state to the old state.
  servooldState = servonewState;
     }

}

void opengrip(){
     
     myservo1.write(80);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
     myservo2.write(80);              // Servo 2 ( Base Close)    
     myservo3.write(70);              // Servo 3 ( Fingertip Open)
     myservo4.write(70);              // Servo 4 ( Base Open)
     delay(500);                       // waits 15 ms for the servo to reach the position
      
     myservo1.write(50);              // Servo 1 ( Fingertip Close) .   Closen <----90-----> Open 
     myservo2.write(70);              // Servo 2 ( Base Close)
     delay(500);                       // waits 15 ms for the servo to reach the position
     myservo3.write(100);              // Servo 3 ( Fingertip Open)
     myservo4.write(100);              // Servo 4 ( Base Open)
  }
*/
