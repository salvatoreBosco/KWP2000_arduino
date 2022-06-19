#ifndef KWP2000_H
#define KWP2000_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#define PIN_TX 11
#define PIN_RX 10
#define S_10k4 10400

const char PIDlist[][11] = {
  {0},
  {1},
  {2},
  {3},
  {4},
  {5},
  {6},
  {7},
  {8},
  {9},
  {10},
  {11},
  {0xc2, 0x33, 0xf1, 0x01, 0x0d, 0xf4},
  {0xc2, 0x33, 0xf1, 0x01, 0x0c, 0xf3}
  };

/**/
void kwp2000_fastInit(); 

/**/

float kwp2000_request(int mode, int pid);

/**/
void initComm();

/**/

float formula(char pid);

#endif
