/*
  KWP2000 request pid 
*/

#include "..\kwp2000.h"

SoftwareSerial mS(10, 11); // RX, TX


void kwp2000_fastInit(); 
float kwp2000_request(int, char);
void clearMS(); 
void clearSerial(); // Pulisce il buffer della seriale
float formula(char);



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


void clearSerial() {
  Serial.end();
  Serial.begin(9600);
}
