Arduino 4 DC Motors and Obstacle Avoidance System
Project Overview
This project was developed using Arduino Uno and Tinkercad to control four DC motors using an L293D Motor Driver.
The system performs a programmed movement sequence and uses an HC-SR04 Ultrasonic Sensor and a Servo Motor to detect and avoid obstacles.


---


Live Simulation



---


Task
The project consists of two main parts:
Part 1: DC Motor Control
The four DC motors perform the following sequence:
Move forward for 30 seconds.
Move backward for 60 seconds.
Turn right and left alternately for 60 seconds.
Stop automatically after completing the sequence.
Part 2: Obstacle Detection and Servo Control
The HC-SR04 Ultrasonic Sensor continuously measures the distance in front of the system.
If an obstacle is detected at a distance of 10 cm or less:
The four DC motors stop.
The servo motor rotates to scan the surrounding area.
The system moves backward briefly.
The motors change direction to avoid the obstacle.


---


Components Used
Arduino Uno R3
Breadboard
4 × DC Motors
L293D Motor Driver
HC-SR04 Ultrasonic Sensor
Micro Servo Motor
9V Battery
Jumper Wires


---


Circuit Connections
L293D Motor Driver
Connection
Arduino Pin
IN1
D3
IN2
D2
IN3
D4
IN4
D5
The four DC motors are connected as two motor pairs to the L293D outputs.
Servo Motor
Servo Connection
Connection
Signal
D10
VCC
5V
GND
GND
HC-SR04 Ultrasonic Sensor
Sensor Pin
Arduino Connection
VCC
5V
GND
GND
TRIG
D11
ECHO
D12


---


System Operation
The system starts with the servo motor positioned at 90°.
The four DC motors move forward for 30 seconds and then reverse direction for 60 seconds.
After that, the motors alternate between right and left turns for a total of 60 seconds.
During operation, the ultrasonic sensor measures the distance in front of the system.
When an obstacle is detected at 10 cm or less, the motors stop immediately. The servo motor scans the surrounding area, and the system performs an avoidance movement before continuing.


---


Screenshots
Circuit Design
Simulation Running
Schematic View


---


Arduino Code
The complete Arduino source code is available in:
four_dc_motors_obstacle_avoidance.ino


---


Project Result
The project was successfully implemented and tested using Tinkercad.
The final system successfully:
Controlled four DC motors.
Moved forward for 30 seconds.
Moved backward for 60 seconds.
Alternated between right and left movements for 60 seconds.
Measured distance using the HC-SR04 sensor.
Detected obstacles at 10 cm or less.
Stopped the DC motors when an obstacle was detected.
Controlled the servo motor to assist with obstacle avoidance.
Completed the programmed movement sequence successfully.


---


Files Included
Arduino-4-DC-Motors
│
├── four_dc_motors_obstacle_avoidance.ino
├── README.md
├── Simulation.mp4
│
└── screenshots
    ├── Circuit.jpg
    ├── Simulation.jpg
    └── Schematic.jpg


---


Tools Used
Arduino Uno
Arduino C/C++
Autodesk Tinkercad

---

# Author

Turki Alkhelaiwi For Smart Methods Summer Training
