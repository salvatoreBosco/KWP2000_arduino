# KWP2000_arduino

This code tries to create a library for the kwp2000 protocol for arduino.<br>

Status PID that are running:<br>
 - PID_12.   ENGINE SPEED<br>
 - PID_13. 	VEHICLE SPEED<br>
<br>
Status SERVICE (MODE) that are running:<br>
 - MODE_1.   Show current data - I/M Monitors and Live Data<br>
<br>
For more information see the project wiki<br>
<h1></h1>
kwp2000 is a communication protocol used in some cars

Example of message exchange with KWP2000 protocol:<br>
<img src="img/FULL/100MS.BMP">
<img src="img/FULL/25MS.BMP">

the messages for SERVICE are composed as follows (Exemple: StartCommunicatioService, ReadByteByLocalIdentifier):

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
 - Checksome byte = 0x66<br>
 <img src="img/REQ_SCOM/66.BMP">
 
 <h1>RESPONSE</h1>
 - Format byte = 0x83<br>
 <img src="img/RES_SCOM/83.BMP">
 - Target byte = 0xf1<br>
 <img src="img/RES_SCOM/F1.BMP">
 - Source byte = 0x10<br>
 <img src="img/RES_SCOM/01_9.BMP">
 - SID byte = 0xc1<br>
 <img src="img/RES_SCOM/C1.BMP">
 - key byte 1 = 0xe9<br>
 <img src="img/RES_SCOM/E9.BMP">
 - key byte 2 = 0x8f<br>
 <img src="img/RES_SCOM/8F.BMP">
  - Checksome byte = 0xbd<br>
 <img src="img/RES_SCOM/BD.BMP">
 
 
 
 the messages for PID are composed as follows (Exemple: ENGINE SPEED, VEHICLE SPEED):
 
 <h3>REQUEST</h3>
 - Format byte
 - Target byte
 - Source byte
 - Mode byte 
 - Pid byte
 - Checksome byte
 
 <h3>RESPONSE</h3>
 - Format byte
 - Target byte
 - Source byte
 - SID Positive Response byte 
 - PID Code byte
 - Parameter value byte
 - Checksome byte
 <h1></h1>
 
 
 
 Exemple request and response of ENGINE SPEED

<h3>REQUEST</h3>
 - Format byte = 0xc2<br>
 <img src="img/REQ_PID/C2.BMP">
 - Target byte = 0x33<br>
 <img src="img/REQ_PID/33.BMP">
 - Source byte = 0xf1<br>
 <img src="img/REQ_PID/F1.BMP">
 - Mode byte= 0x01<br>
 <img src="img/REQ_PID/01.BMP">
 - Pid byte = 0x0d<br>
 <img src="img/REQ_PID/0D.BMP">
 - Checsome byte = 0xf4<br>
 <img src="img/REQ_PID/F4.BMP">
 
 <h3>RESPONSE</h3>
 - Format byte = 0x83<br>
 <img src="img/RES_PID/83.BMP">
 - Target byte = 0xf1<br>
 <img src="img/RES_PID/F1.BMP">
 - Source byte = 0x10<br>
 <img src="img/RES_PID/10.BMP">
 - SID Positive Response byte = 0x41<br> 
 <img src="img/RES_PID/41.BMP">
 - PID Code byte = 0x0d<br>
 <img src="img/RES_PID/0D.BMP">
 - Parameter value byte = 0x00<br>
 <img src="img/RES_PID/00.BMP">
 - Checksome byte = 0xd2<br>
 <img src="img/RES_PID/D2.BMP">

<h1></h1>

To interface Arduino with your car you need to create a circuit that can not burn the Arduino: transforming the 12V that supplies the K line into 5V compatible with Arduino and vice versa

Here you find an example:<br>
<img src="img/Schematic/schematic.png">
