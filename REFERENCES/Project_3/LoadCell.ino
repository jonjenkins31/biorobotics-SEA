
/***************************************************************************************
 * 
    Notes   : This code is for use with an Arduino Uno and LCD/button shield. The
              intent is for anyone to use this program to give them a starting
              program with a fully functional menu with minimal modifications
              required by the user.

 ***************************************************************************************/





void scale(){
  
  static boolean newDataReady = 0;
  const int serialPrintInterval = 0; //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell1.update()) newDataReady = true;

  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell1.getData();
      Serial.print("Load_cell 1:");
      Serial.println(i);
      straingage1 = i; // strain gage value
      newDataReady = 0;
      t = millis();
    }
  }

  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell1.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell1.getTareStatus() == true) {
    Serial.println("Tare complete");
  }


//////

  // check for new data/start next conversion:
  if (LoadCell2.update()) newDataReady = true;

  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell2.getData();
      Serial.print("Load_cell2:");
      Serial.println(i);
     straingage2 = i; // strain gage value

      newDataReady = 0;
      t = millis();
    }
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
