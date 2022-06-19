/*
  KWP2000 request pid 
*/

#include <SoftwareSerial.h>

SoftwareSerial mS(10, 11); // RX, TX


void kwp2000_fastInit(); 
float kwp2000_request(int, char);
void clearMS(); 
void clearSerial(); // Pulisce il buffer della seriale
float formula(char);

int mode = -1;
char pid = -1;
char startComm[] = {0xc1, 0x33, 0xf1, 0x81, 0x66};


char bytePID[64];

int i;

void setup() {
  /*Initialization of Serial monitor and KWP2000 communication*/
  Serial.begin(9600);
  mS.begin(10400); //10400 is specific for kwp2000
}

void loop() {

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
  
  int res = kwp2000_request(mode, pid); //request for pid in the chosen mode

  delay(1000);
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
  
  /* raccolta dati */
  
  while (mS.available() < 1 ) {Serial.print(" ");}
  Serial.println("");
  while (mS.available() > 0) {
    bytePID[i] = mS.read();
    i++; 
  }
  return formula(pid);
}

void clearMS() {
  mS.end();
  mS.begin(10400);
}

void clearSerial() {
  Serial.end();
  Serial.begin(9600);
}

float formula(char pid){
  /*calcola e mostra risultato*/
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
