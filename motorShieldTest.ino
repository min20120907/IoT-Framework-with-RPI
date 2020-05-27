/*
Pay attention to the interrupt pin,please check which microcontroller you use.
http://arduino.cc/en/Reference/AttachInterrupt
*/

//The sample code for driving one way motor encoder
const byte encoder0pinA = 2;//A pin -> the interrupt pin 2
const byte encoder0pinB = 8;//B pin -> the digital pin 4
byte encoder0PinALast;

const byte encoder1pinA = 3;//A pin -> the interrupt pin 2
const byte encoder1pinB = 9;//B pin -> the digital pin 4
byte encoder1PinALast;

int duration;//the number of the pulses
boolean Direction;//the rotation direction
int duration2;//the number of the pulses
boolean Direction2;//the rotation direction
//This motor shield use Pin 6,5,7,4 to control the motor
// Simply connect your motors to M1+,M1-,M2+,M2-
// Upload the code to Arduino/Roboduino
// Through serial monitor, type 'a','s', 'w','d','x' to control the motor
// www.dfrobot.com
// Last modified on 24/12/2009

int EN1 = 6;
int EN2 = 5;  //Roboduino Motor shield uses Pin 9
int IN1 = 7;
int IN2 = 4; //Latest version use pin 4 instead of pin 8

void Motor1(int pwm, boolean reverse) {
  analogWrite(EN1, pwm); //set pwm control, 0 for stop, and 255 for maximum speed
  if (reverse)  {
    digitalWrite(IN1, HIGH);
  }
  else  {
    digitalWrite(IN1, LOW);
  }
}

void Motor2(int pwm, boolean reverse) {
  analogWrite(EN2, pwm);
  if (reverse)  {
    digitalWrite(IN2, HIGH);
  }
  else  {
    digitalWrite(IN2, LOW);
  }
}

void setup()
{
  int i;
  // for(i=6;i<=9;i++) //For Roboduino Motor Shield
  // pinMode(i, OUTPUT);  //set pin 6,7,8,9 to output mode

  for (i = 4; i <= 7; i++) //For Arduino Motor Shield
    pinMode(i, OUTPUT);  //set pin 4,5,6,7 to output mode
  Serial.begin(57600);//Initialize the serial port
  EncoderInit();//Initialize the module
  EncoderInit2();//Initialize the module
}
int j = 50;
void loop()
{
  Motor1(j, true); //You can change the speed, such as Motor(50,true)
  Motor2(j, true);
  j++;
  Serial.print("Motor1 Pulse:");
  Serial.println(duration);
  duration = 0;
  Serial.print("Motor2 Pulse:");
  Serial.println(duration2);
  duration2 = 0;
  delay(100);
  if(j>200)
    j=0;
}

void EncoderInit()
{
  Direction = true;//default -> Forward
  pinMode(encoder0pinB,INPUT);
  attachInterrupt(0, wheelSpeed, CHANGE);//int.0
}
void EncoderInit2()
{
  Direction2 = true;//default -> Forward
  pinMode(encoder1pinB,INPUT);
  attachInterrupt(1, wheelSpeed2, CHANGE);//int.0
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

  if(!Direction)  duration++;
  else  duration--;
}

void wheelSpeed2()
{
  int Lstate = digitalRead(encoder1pinA);
  if((encoder1PinALast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encoder1pinB);
    if(val == LOW && Direction2)
    {
      Direction2 = false; //Reverse
    }
    else if(val == HIGH && !Direction2)
    {
      Direction2 = true;  //Forward
    }
  }
  encoder1PinALast = Lstate;

  if(!Direction2)  duration2++;
  else  duration2--;
}
