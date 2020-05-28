# IoT-Framework-with-RPI
IoT framework with raspberry pi

### Prerequirements
- wiringPi
- g++
- build-essential
### Raspberry Pi Server (Cluster)
- Flask Server
- Django Server
- Modbus Server
- FTP Server
- MQTT Server
- MariaDB Server
### Raspbery Pi Optional Requirements
- PHPMyadmin
- PHP
- Node Server
### Equipments
- Raspberry Pi 3B
- IP Cam * n
- Step Motor
- Infrared Sensor

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
### InfraredSensoring
#### Description
Using infrared sensor to check whether there are obstacles encountering, and using ```std::cout``` to show the status
> 0: blocked
> 1: clear
***
# Su-ao smart city live video monitoring system
## IPCam
#### Locations:
- Nanfangao Wharf
- Dongao Wharf
- Nanao Wharf
- Other touring places
- Safe guarding areas

#### Methods:
- Video Capturing
- Digital I/O
- Analog I/O (ADS1115)
***
