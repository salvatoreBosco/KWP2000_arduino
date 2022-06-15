#ifndef KWP2000_H
#define KWP2000_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#define PIN_TX 11
#define PIN_RX 10
#define S_10k4 10400

/**/
void kwp2000_fastInit(); 

/**/

float kwp2000_request(int mode, int pid);

/**/
void initComm();

/**/

float formula(char pid);

#endif
