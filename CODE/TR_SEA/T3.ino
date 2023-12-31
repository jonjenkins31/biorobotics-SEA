
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


// INPUT RECEIVED
  if (activeButton == 1){
        activeButton = 0;
    switch (button) {
      case 1:  // This case will execute if the "LEFT" button is pressed
        break;
      case 2:  // This case will execute if the "UP" button is pressed
         task2 != task2;                                     // turn Armfunction high:  arm fuction will run once
        break;
     case 3:  // This case will execute if the "DOWN" button is pressed
        break;
      case 4:  // This case will execute if the "RIGHT" button is pressed
        break;
      case 5:  // This case will execute if the "back" button is pressed
        activepage=0;
        break;
      }
   }

 // TASKS
  if(task2 == HIGH){                 // BUTTON IS RELEASED INITIATE TASK
 
}
}
