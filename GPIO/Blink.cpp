#include <wiringPi.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

  wiringPiSetup();
  pinMode(25, OUTPUT);  //set GPIO 26 as output pin
  
  while(1){
    //Blinking LED
    digitalWrite(25, 1);
    delay(1000);
    digitalWrite(25, 0);
    delay(1000);
  }
  return 0;
}
