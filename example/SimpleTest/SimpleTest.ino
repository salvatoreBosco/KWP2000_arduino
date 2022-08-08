#include <SoftwareSerial.h>

#include <kwp2000.h>

void setup() {
  /*Initialization of Serial monitor and KWP2000 communication*/
  Serial.begin(9600);
}

void loop() {
  kwp kwp;
  int res = kwp.request(1, 13); //request for pid in the chosen mode
  Serial.println(res);
  delay(1000);
}
