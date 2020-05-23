# IoT-Framework-with-RPI
IoT framework with raspberry pi

### Prerequirements
- wiringPi
- g++

### Compile method (ex. stepMotor)
```bash
g++ stepMotor.cpp -lwiringPi -lrt -lpthread -lcrypt -o stepMotor
```

### TestLED
#### Description
Using GPIO25 pin to blinking the led 1sec intervally.

### StepMotor
#### Description
Using DFRobot step motor to increasing the RPM, and report current RPM by ```cpp std::cout```.
