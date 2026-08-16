# Arduino 4 DC Motors and Obstacle Avoidance System

## Project Overview

This project was developed using Arduino Uno and Tinkercad to control four DC motors using an L293D Motor Driver.

The system performs forward, backward, right, and left movements. It also uses an HC-SR04 Ultrasonic Sensor and a Servo Motor to detect and avoid obstacles.

---

## Live Simulation

[[Tinkercad Simulation](ADD-YOUR-TINKERCAD-LINK-HERE)](https://www.tinkercad.com/things/lLLXHdVucln-four-dc-motors-l293d)

---

## Task

### Part 1: DC Motor Control

The four DC motors perform the following sequence:

- Move forward for 30 seconds
- Move backward for 60 seconds
- Turn right and left alternately for 60 seconds
- Stop automatically after completing the sequence

### Part 2: Obstacle Detection

The HC-SR04 Ultrasonic Sensor measures the distance in front of the system.

If an obstacle is detected at a distance of 10 cm or less:

- The DC motors stop
- The servo motor rotates
- The system changes direction to avoid the obstacle

---

## Components Used

- Arduino Uno R3
- Breadboard
- 4 × DC Motors
- L293D Motor Driver
- HC-SR04 Ultrasonic Sensor
- Micro Servo Motor
- 9V Battery
- Jumper Wires

---

## Circuit Connections

### L293D Motor Driver

| L293D Input | Arduino Pin |
|---|---|
| IN1 | D3 |
| IN2 | D2 |
| IN3 | D4 |
| IN4 | D5 |

### Servo Motor

| Connection | Arduino Pin |
|---|---|
| Signal | D10 |
| VCC | 5V |
| GND | GND |

### HC-SR04 Ultrasonic Sensor

| Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D11 |
| ECHO | D12 |

---

## Movement Sequence

1. Forward for 30 seconds
2. Backward for 60 seconds
3. Right and left alternately for 60 seconds
4. Stop automatically

If an obstacle is detected within 10 cm, the motors stop and the servo motor moves to help avoid the obstacle.

---


## Screenshots

### Before Simulation

![Before Simulation](photo123.jpg)

### During Simulation

![During Simulation](after123.jpg)

---

## Arduino Code

The complete Arduino code is available in:

four_dc_motors_obstacle_avoidance.ino

---

## Project Result

- Four DC motors were successfully controlled
- Forward movement for 30 seconds
- Backward movement for 60 seconds
- Right and left movement for 60 seconds
- Successful distance measurement using HC-SR04
- Obstacle detection at 10 cm or less
- Servo motor control for obstacle avoidance
- Successfully tested using Tinkercad

---

## Files Included
four_dc_motors_obstacle_avoidance.ino
README.md
Simulation.mp4

screenshots/
├── Circuit.jpg
├── Simulation.jpg
└── Schematic.jpg

---

## Tools Used

- Arduino Uno
- Arduino C/C++
- Tinkercad
- GitHub
---

# Author

Turki Alkhelaiwi For Smart Methods Summer Training
