# IoT-Framework-with-RPI
IoT framework with raspberry pi

### Prerequirements
- wiringPi
- g++
- build-essential
### Compile method (ex. stepMotor)
```bash
g++ stepMotor.cpp -lwiringPi -lrt -lpthread -lcrypt -o stepMotor
```
***
### TestLED
#### Description
Using GPIO25 pin to blinking the led 1sec intervally.
***
### StepMotor
#### Description
Using DFRobot step motor to increasing the RPM, and report current RPM by ```std::cout```.
***
# Su-ao smart city live video monitoring system
## IPCam
#### Locations:
- Nanfangao Hwarf
- Dongao Hwarf
- Nanao Hwarf
- Other touring places
- Safe guarding areas

#### Methods:
- Video Capturing
- Digital I/O
- Analog I/O (ADS1115)
***
