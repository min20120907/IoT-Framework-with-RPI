#include <iostream>
#include <wiringPi.h>
#include <stdio.h>

using namespace std;

int main(){

	wiringPiSetup();
	pinMode(25, INPUT);
	
	while(1){
		cout<<"Infrared State: "<<digitalRead(25)<<endl;
		delay(1000);
	}

	return 0;
}
