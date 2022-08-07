#include <SoftwareSerial.h>

#include "kwp2000.h"

//void kwp2000_fastInit(); 
//float kwp2000_request(int, char);
//void clearMS(); 
//void clearSerial(); // Pulisce il buffer della seriale
//float formula(char);



int i;

int mode = -1;
char pid = -1;
void setup() {
  /*Initialization of Serial monitor and KWP2000 communication*/
  Serial.begin(9600);
}

void loop() {
  kwp kwp;
  clearSerial(); 
  
  /*show options + memorize the choice*/
  Serial.println("choose mode");
  Serial.println("1: Show current data - I/M Monitors and Live Data \n2: Show Freeze Frame (FF) Data \n3: Show Stored Diagnostic Trouble Codes \n4: Clear/Erase Diagnostic Trouble Codes and stored values \n5: Test results, oxygen sensor monitoring (non CAN only) \n6: Test results, other component/system monitoring (Test results, oxygen sensor monitoring for CAN only) \n7: Show pending Diagnostic Trouble Codes (detected during current or last driving cycle) \n8: Control operation of on-board component/system (EVAP) \n9: Request Vehicle Information (VIN) \nA: Permanent Diagnostic Trouble Codes (DTCs) (Cleared DTCs)");
  while (Serial.available() < 1) {
    ;
  }
  if (Serial.available() > 0) {
    mode = Serial.read() - 0x30;
  } 
  Serial.println(mode, HEX);
  delay(500);
  clearSerial();
  Serial.println("choose pid");
  Serial.println("speed: c \n rmp: d \n");
  while (Serial.available() < 1) {
    ;
  }
  if (Serial.available() > 0) {
    pid = Serial.read() - 0x57;
  }
  
  int res = kwp.request(mode, pid); //request for pid in the chosen mode
  Serial.println(res);
  delay(1000);
}

//void clearMS() {
//  mS.end();
//  mS.begin(10400);
//}
//
//void kwp2000_fastInit() {
//  mS.end(); // to use pin tx as normal I / O pin it is necessary to disable the communication 
//  
//  /* --------------------wake up pattern-------------------- */ 
//  
//  pinMode(11, OUTPUT);
//  digitalWrite(11, LOW);
//  delay(25);
//  digitalWrite(11, HIGH);
//  delay(25);
//  
//  mS.begin(10400); //re-enabled communication
//
//  /* -----------------------------send byte for StartCommunication Service---------------- */
//  for (int i = 0; i < 5; i++) {
//    mS.write(startComm[i]);
//    delay(6);
//  }
//  delay(100);
//  
//  clearMS();
//}
//
//float formula(char pid){
//  /* calculate */
//  switch(pid){
//      case 0:
//        break;
//      case 1:
//        break;
//      case 2:
//        break;
//      case 3:
//        break;
//      case 4:
//        return (100 / 255) * bytePID[5];
//        break;
//      case 5:
//        return bytePID[5] - 40;
//        break;
//      case 6:
//        return ((100 / 128) * bytePID[5]) -100;
//        break;
//      case 7:
//        return ((100 / 128) * bytePID[5]) -100;
//        break;
//      case 8:
//        return ((100 / 128) * bytePID[5]) -100; 
//        break;
//      case 9:
//        return ((100 / 128) * bytePID[5]) -100;
//        break;
//      case 10:
//        return 3 * bytePID[5];
//        break;
//      case 11:
//        return bytePID[5];
//        break;
//      case 12:
//        return ((bytePID[5]*256)+bytePID[6])/4;
//        break;
//      case 13:
//        return bytePID[5];
//        break;
//      case 14:
//        break;
//    }
//}
//
//float kwp2000_request(int mode, char pid) {
//  int i;
//  kwp2000_fastInit(); //inizializza la comunicazione
//
//  /* Send byte */
//  
//  if(mode == 1){
//    
//    for (i = 0; i < 6; i++) {
//      mS.write(PIDlist[(int)pid][i]);
//      delay(6);
//    }
//  }
//
//  clearMS();
//  
//
//  /* data collection */
//
//  i = 0;
//  while (mS.available() < 1 ){Serial.print(" ");}
//  Serial.println(" ");
//  while (mS.available() > 0) {
//    bytePID[i] = mS.read();
//    i++; 
//  }
//
//  
//  return formula(pid);
//}
//
void clearSerial() {
  Serial.end();
  Serial.begin(9600);
}
