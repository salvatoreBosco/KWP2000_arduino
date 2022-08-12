#include "kwp2000.h"

#include <SoftwareSerial.h>
SoftwareSerial kwpS(10, 11); // RX, TX

int bytePID[64];
char FORMAT = 0xc2;
char TARGET = 0x33;
char SOURCE = 0xf1;
char MODE = 0;
char PID = 0;
char CS = 0;
char pidMess[7] = {FORMAT, TARGET, SOURCE, MODE, PID, CS};
/*
const char PIDlist[15][7] = {
      {0xc2, 0x33, 0xf1, 0x01, 0x00, 0xe7},
      {0xc2, 0x33, 0xf1, 0x01, 0x01, 0xe8},
      {0xc2, 0x33, 0xf1, 0x01, 0x02, 0xe9},
      {0xc2, 0x33, 0xf1, 0x01, 0x03, 0xea},
      {0xc2, 0x33, 0xf1, 0x01, 0x04, 0xeb},
      {0x82, 0x0a, 0xf1, 0x01, 0x05, 0x83},
      {0xc2, 0x33, 0xf1, 0x01, 0x06, 0xed},
      {0xc2, 0x33, 0xf1, 0x01, 0x07, 0xee},
      {0xc2, 0x33, 0xf1, 0x01, 0x08, 0xef},
      {0xc2, 0x33, 0xf1, 0x01, 0x09, 0xf0},
      {0xc2, 0x33, 0xf1, 0x01, 0x0a, 0xf1},
      {0xc2, 0x33, 0xf1, 0x01, 0x0b, 0xf2},
      {0xc2, 0x33, 0xf1, 0x01, 0x0c, 0xf3},
      {0xc2, 0x33, 0xf1, 0x01, 0x0d, 0xf4},
      {0xc2, 0x33, 0xf1, 0x01, 0x0e, 0xf5},
    };
*/
void clearMS() {
  kwpS.end();
  kwpS.begin(10400);
}

int kwp::init(int baudRate){
  kwpS.begin(baudRate);
}

void kwp::fastInit() {
  kwp kwp;
  kwpS.end(); // to use pin tx as normal I / O pin it is necessary to disable the communication 
  
  /* --------------------wake up pattern-------------------- */ 
  
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  delay(25);
  digitalWrite(11, HIGH);
  delay(25);
  
  kwpS.begin(10400); //re-enabled communication

  /* -----------------------------send byte for StartCommunication Service---------------- */
  for (int i = 0; i < 5; i++) {
    kwpS.write(startComm[i]);
    delay(6);
  }
  kwpS.end();
  kwpS.begin(10400);
  delay(100);
  
  clearMS();
}


float kwp::formula(char pid){
  /* calculate */
  switch(int(pid)){
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
        return (bytePID[5]/2)-64;
        break;
    }
}

char calcCS(char pidMess[]){
  int res = int(pidMess[0] + pidMess[1] + pidMess[2] + pidMess[3] + pidMess[4]);
  while(res >= 0x100){
    res = res - 100;
  }
  return char(res);
  
}

int kwp::request(int mode, char pid){
  
  int i;
  kwp kwp;
  kwp.fastInit(); //inizializza la comunicazione

  /* Send byte */
  if(mode == 1){
    pidMess[3] = char(mode);
    pidMess[4] = pid;
    pidMess[5] = calcCS(pidMess);
    for (i = 0; i < 6; i++) {
      kwpS.write(pidMess[i]);
      delay(6);
    }
  }

  clearMS();
  

  /* data collection */
  
  i = 0;
 
  while (kwpS.available() < 1 ){Serial.print(" ");}
  Serial.println(" ");
  while (kwpS.available() > 0) {
    bytePID[i] = kwpS.read();
    i++; 
  }
    
  return kwp.formula(pid);
}
