#include "xArmServoController.h"
#include <stdarg.h>
#include <Arduino.h>
//#include <Wire.h>
#define txPin 1
#define rxPin 2
//delay time in milliseconds
unsigned int delayTime = 1000;
//time passed in milliseconds to robotic arm position function to complete movement
unsigned int timer = 3000;
//declaration of class instance for xArm
xArmServoController myArm = xArmServoController(xArm, Serial);
//declaring digital pin 6 for the electromagnet
int magnetPin = 6;


void setup() 
{

 //setting up digital pin for 5V output to energize the electromagnet 
 pinMode(magnetPin, OUTPUT);
 //setting up serial communication
 Serial.begin(9600);

}

void loop()
{
 
//defining parameters for robotic arm default position
xArmServo defaultPosition[] ={                  
                     {2,345},
                     {3,500},
                     {4,500},
                     {5,500},
                     {6,500}
                     };
//passing parameters for robotic arm default position
myArm.setPosition(defaultPosition, 4, timer, true);
//delay 1s
delay(delayTime);


//defining parameters for robotic arm position
xArmServo position1[] ={
                        {2,360},
                        {3,196},
                        {4,95},
                        {5,766},
                        {6,395}
                        };
//set robotic arm to parameters in position1 over 3s                        
myArm.setPosition(position1, 4, timer, true);
//delay 1s
delay(delayTime);
//set magnetPin to 5V to turn on the electromagnet
digitalWrite(magnetPin,HIGH);
//delay 1s
delay(delayTime);
//passing parameters for robotic arm default position
myArm.setPosition(defaultPosition, 4, timer, true);
//delay 1s
delay(delayTime);
//set robotic arm to parameters in position1 over 3s  
myArm.setPosition(position1, 4, timer, true);
//set magnetPin to 0V to turn off the electromagnet
digitalWrite(magnetPin,LOW);
//delay 1s
delay(delayTime);
//Go back to top of loop and repeat
                     

}
