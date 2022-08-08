#ifndef KWP2000_
#define KWP2000_

#include <Arduino.h>



class kwp{

  private:
    
    void fastInit();
    float formula(char pid);
    char startComm[6] = {0xc1, 0x33, 0xf1, 0x81, 0x66};
    int i;
  public:
    /*
      Initialize kwp protocol
    */
    int init(int baudRate);
    /*
      Send a message to OBD
    */
    int request(int mode, char pid);
};


#endif
