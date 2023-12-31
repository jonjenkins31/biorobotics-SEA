
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
  if (LoadCell.update()) newDataReady = true;

  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell.getData();
      serialprintv("Load_cell : ",i);             // SERIAL INFORMATION FUNCTION
      straingage = i; // strain gage value
      newDataReady = 0;
      t = millis();
    }
  }

  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }



}

void poteniometer() {
  // read the input on analog pin A0:
  int analogValue = analogRead(potpin);
  // Rescale to potentiometer's voltage (from 0V to 5V):
  float voltage = floatMap(analogValue, 0, 1023, 0, 5);
  int angleraw = map(analogValue, 0, 1023, 0, ANGLE_MAX);
  angle = map (analogValue,333,1023,-30,160);
  serialprintv("Poteniometer Analog : ",analogValue);             // SERIAL INFORMATION FUNCTION
  serialprintv("Poteniometer Voltage : ",voltage);             // SERIAL INFORMATION FUNCTION
  serialprintv("Poteniometer Angle : ",angle);             // SERIAL INFORMATION FUNCTION

}
