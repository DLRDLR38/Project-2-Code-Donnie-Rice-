
#include <stdarg.h>
#include <Arduino.h>
//declaring pin 5 of the Arduino as the analog voltage pin which will be used for the load sensor input
int analogPin = A5;
//declaring valueRead variable to hold analog voltage readings from the load sensor
int valueRead = 0;
//declaring averaging and counting variables
int average = 0;
int count = 5;
//declaring pin 7 of the Arduino which will be used as a digital output (5V) to turn the alarm on/off
int digitalPin7 = 7;
//declaring the value of the critical weight limit that will set of the alarm if exceeded
int criticalWeightLimit = 475;

void setup() 
{
//setting up pin 7 of the Arduino as an output
pinMode (digitalPin7, OUTPUT);
//initializing serial
Serial.begin(9600);

}

void loop()
{
//while loop used for taking 5 readings from the load sensor input... an average of these 5 readings will be taken and later tested for the critical limit that sets off the alarm   
while(count > 0)
{
//read the incoming analog voltage values and store them in valueRead
valueRead = analogRead(analogPin);
//sum the values of valueRead into average
average += valueRead;
//decrement count variable
count -= 1;
//wait 25ms
delay(25);
}//end of while loop
//re initialize count variable
count = 5;
//calculate an average of the 5 readings from the analog voltage input of the load sensor
average = average/count;
//the input value from the load sensor was still in a small range so the value of average is being scaled by a factor of 10
average = 10*average;
//if statement to check if the average reading taken from the load sensor exceeds the critical weight limit set
if(average > criticalWeightLimit)
{
//set digital pin 7 to high (5V) and turn on the alarm
digitalWrite(digitalPin7, HIGH);
//wait 2.5s
delay(2500);
}
//set digital pin 7 to low (0V) and turn off the alarm
digitalWrite(digitalPin7, LOW);
//Serial.println(average);
//re initialize the average variable to 0
average = 0;
//Go back to top of loop and repeat

}
