# KWP2000_arduino

Nel file kwp2000.cpp e kwp2000.h si trovano le seguenti funzioni

<h2>void kwp2000_fastInit();</h2>
  
-   KWP2000 quick initialization.
   This function is used by other functions.
   So don't worry about it. :)

<hr>
 
<h2>float kwp2000_request(int mode, int pid);</h2>

-  Request the parameters of the car.
  It needs the mode and the PID.
  You can find them on wikipedia "https://en.wikipedia.org/wiki/OBD-II_PIDs"

<hr>

<h2>void initComm();</h2>

-  Always use it at the beginning of "void setup ()".
 Inside the serial called ms is initialized

 RX = pin 10
 TX = pin 11

<hr>

<h2>float formula(char pid);</h2>

-  Formulas for obtaining the requested data
 This function is used by other functions.
 So don't worry about it. :)


