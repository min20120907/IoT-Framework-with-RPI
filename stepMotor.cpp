#include <wiringPi.h>
#include <iostream>
#include <stdio.h>
using namespace std;


//The sample code for driving one way motor encoder
const int encoder0pinA = 2;//A pin -> the interrupt pin 0
const int encoder0pinB = 4;//B pin -> the digital pin 4
int encoder0PinALast;
int duration;//the number of the pulses
bool Direction;//the rotation direction

int main(){
	wiringPiSetup();
	pinMode(25, OUTPUT);
	EncoderInit();//Initialize the module

	while(1){
		cout<<"Pulse:"<<duration<<endl;
  		duration = 0;
  		delay(100);
		//Blinking LED
		digitalWrite(25, 1);
		delay(1000);
		digitalWrite(25, 0);
		delay(1000);	
	}

	return 0;
}

void wheelSpeed()
{
  int Lstate = digitalRead(encoder0pinA);
  if((encoder0PinALast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encoder0pinB);
    if(val == LOW && Direction)
    {
      Direction = false; //Reverse
    }
    else if(val == HIGH && !Direction)
    {
      Direction = true;  //Forward
    }
  }
  encoder0PinALast = Lstate;

  if(!Direction)  duration  ;
  else  duration--;
}

void EncoderInit()
{
  Direction = true;//default -> Forward
  pinMode(encoder0pinB,INPUT);
  wiringPiISR(0, INT_EDGE_BOTH, ::wheelSpeed);
}

