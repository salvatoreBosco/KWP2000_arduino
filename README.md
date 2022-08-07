# KWP2000_arduino

This code tries to create a library for the kwp2000 protocol for arduino.<br>

Status PID that are running:<br>
 - PID_12.   ENGINE SPEED<br>
 - PID_13. 	VEHICLE SPEED<br>
<br>
Status MODE that are running:<br>
 - MODE_1.   Show current data - I/M Monitors and Live Data<br>
<br>
For more information see the project wiki<br>

kwp2000 is a communication protocol used in some cars

Example of message exchange with KWP2000 protocol:<br>
<img src="img/FULL/100MS.BMP">
<img src="img/FULL/25MS.BMP">

the messages for SERVICE are composed as follows (Exemple: StartCommunicatioService):

<h3>REQUEST</h3>
 - Format byte
 - Target byte
 - Source byte
 - SID byte 
 - Parameters
 - Checksome byte
 
 <h3>RESPONSE</h3>
 - Format byte
 - Target byte
 - Source byte
 - SID Positive Response byte 
 - key byte 1
 - key byte 2
 - Checksome byte
 <h1></h1>
 
 
 
 Exemple request and response of StartCommunicatioService 
 
 <h1>REQUEST</h1>
 - Format byte = 0xc1<br>
 <img src="img/REQ_SCOM/C1.BMP">
 - Target byte = 0x33<br>
 <img src="img/REQ_SCOM/33.BMP">
 - Source byte = 0xf1<br>
 <img src="img/REQ_SCOM/F1.BMP">
 - SID byte = 0x81<br>
 <img src="img/REQ_SCOM/81.BMP">
 - Parameters = NULL<br>
 - Checkbyte = 0x66<br>
 <img src="img/REQ_SCOM/66.BMP">
 <h1>RESPONSE</h1>
 
 
 the messages for PID are composed as follows (Exemple: ENGINE SPEED, VEHICLE SPEED):

 - Format byte
 - Target byte
 - Source byte
 - Mode
 - Pid
 - Checsome kbyte
