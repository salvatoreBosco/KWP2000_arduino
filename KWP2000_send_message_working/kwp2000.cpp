#include "kwp2000.h"

void initComm(){
  SoftwareSerial mS(PIN_RX, PIN_TX); // RX, TX

  ms.begin(S_10k4);
}

void clearMS() {
  mS.end();
  mS.begin(10400);
}

void kwp2000_fastInit() {
  
  mS.end(); // to use pin tx as normal I / O pin it is necessary to disable the communication 
  
  /* --------------------wake up pattern-------------------- */ 
  
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  delay(25);
  digitalWrite(11, HIGH);
  delay(25);
  
  mS.begin(S_10k4); //re-enabled communication

  /* -----------------------------send byte for StartCommunication Service---------------- */
  for (i = 0; i < 5; i++) {
    mS.write(startComm[i]);
    delay(6);
  }
  delay(100);
  clearMS();
}

float formula(char pid){
  /* calculate */
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
        return (100 / 255) * bytePID[5];
        break;
      case 5:
        return bytePID[5] - 40;
        break;
      case 6:
        return ((100 / 128) * bytePID[5]) -100;
        break;
      case 7:
        return ((100 / 128) * bytePID[5]) -100;
        break;
      case 8:
        return ((100 / 128) * bytePID[5]) -100; 
        break;
      case 9:
        return ((100 / 128) * bytePID[5]) -100;
        break;
      case 10:
        return 3 * bytePID[5];
        break;
      case 11:
        return bytePID[5];
        break;
      case 12:
        return ((bytePID[5]*256)+bytePID[6])/4;
        break;
      case 13:
        return bytePID[5];
        break;
      case 14:
        break;
    }
}

float kwp2000_request(int mode, char pid) {

  int i;
  kwp2000_fastInit(); //inizializza la comunicazione

  /* Send byte */
  
  if(mode == 1){
    
    for (i = 0; i < 6; i++) {
      mS.write(PIDlist[(int)pid][i]);
      delay(6);
    }
  }

  clearMS();
  

  /* data collection */

  i = 0;
  while (mS.available() < 1 ) {;}
  while (mS.available() > 0) {
    bytePID[i] = mS.read();
    i++; 
  }
  return formula(pid);
}
