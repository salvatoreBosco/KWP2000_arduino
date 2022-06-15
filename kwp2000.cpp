#include "kwp2000.h"

void initComm(){
  SoftwareSerial mS(PIN_RX, PIN_TX); // RX, TX

  ms.begin(S_10k4);
}

void kwp2000_fastInit() {
  
  mS.end(); // to use pin tx as normal I / O pin it is necessary to disable the communication 
  
  /*--------------------wake up pattern-------------------- */ 
  
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  delay(25);
  digitalWrite(11, HIGH);
  delay(25);
  
  mS.begin(S_10k4); //re-enabled communication

  /* -----------------------------send byte for StartCommunication Service----------------*/
  for (i = 0; i < 5; i++) {
    mS.write(startComm[i]);
    delay(6);
  }
  delay(100);
  clearMS();
}

float formula(char pid){
  /*calculate and show result*/
  switch(pid){
      case 0:
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      case 10:
        break;
      case 11:
        break;
      case 12:
        Serial.print("speed = ");
        Serial.print(bytePID[5], DEC);
        Serial.println(" km/h");
        return bytePID[5];
        break;
      case 13:
        Serial.print("rpm = ");
        Serial.print( (((bytePID[5]*256)+bytePID[6])/4) , DEC);
        Serial.println(" giro/minuto");
        return ((bytePID[5]*256)+bytePID[6])/4;
        break;
      case 14:
        break;
    }
}

float kwp2000_request(int mode, char pid) {

  kwp2000_fastInit(); //inizializza la comunicazione

  /* Send byte */
  
  if(mode == 1){
    switch(pid){
      case 0:
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      case 10:
        break;
      case 11:
        break;
      case 12:
        /* Send byte for speed */
        for (i = 0; i < 6; i++) {
          mS.write(PIDlist[(int)pid][i]);
          delay(6);
        }
        break;
      case 13:
        /* Send byte for rpm */ 
        for (i = 0; i < 6; i++) {
          mS.write(PIDlist[(int)pid][i]);
          delay(6);
        }  
        break;
      default:
        return -1.1;
    }
  }
  clearMS();
  i = 0;
  
  /* data collection */
  
  while (mS.available() < 1 ) {Serial.print("a");}
  Serial.println("");
  while (mS.available() > 0) {
    bytePID[i] = mS.read();
    Serial.println(bytePID[i], HEX);
    i++; 
  }
  return formula(pid);
}
