#include <Servo.h>

// ==========================
// DC Motors - L293D
// ==========================

const int IN1 = 3;
const int IN2 = 2;
const int IN3 = 4;
const int IN4 = 5;


// ==========================
// Servo
// ==========================

const int SERVO_PIN = 10;

Servo myServo;


// ==========================
// Ultrasonic Sensor
// ==========================

const int TRIG_PIN = 11;
const int ECHO_PIN = 12;


// ==========================
// Setup
// ==========================

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  myServo.attach(SERVO_PIN);

  // Servo starts in center
  myServo.write(90);

  Serial.begin(9600);

  stopMotors();

  delay(1000);
}


// ==========================
// Motor Functions
// ==========================

void forward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void backward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void turnRight() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void turnLeft() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void stopMotors() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// ==========================
// Ultrasonic Distance
// ==========================

float getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // No reading
  if (duration == 0) {
    return 999;
  }

  float distance = duration * 0.0343 / 2.0;

  return distance;
}


// ==========================
// Obstacle Detection
// ==========================

bool obstacleDetected() {

  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10) {
    return true;
  }

  return false;
}


// ==========================
// Avoid Obstacle
// ==========================

void avoidObstacle() {

  // Stop immediately
  stopMotors();
  delay(300);


  // Servo looks left
  myServo.write(20);
  delay(700);


  // Servo looks right
  myServo.write(160);
  delay(700);


  // Return to center
  myServo.write(90);
  delay(500);


  // Move backward
  backward();
  delay(1000);


  // Turn right
  turnRight();
  delay(1200);


  // Stop
  stopMotors();
  delay(300);
}


// ==========================
// Timed Movement
// ==========================

void moveWithSensor(void (*movement)(), unsigned long timeRequired) {

  unsigned long startTime = millis();

  while (millis() - startTime < timeRequired) {

    if (obstacleDetected()) {

      avoidObstacle();

    } else {

      movement();
    }

    delay(50);
  }

  stopMotors();
}


// ==========================
// Main Program
// ==========================

void loop() {

  // ===================================
  // 1) Forward for 30 seconds
  // ===================================

  moveWithSensor(forward, 30000);

  stopMotors();
  delay(1000);


  // ===================================
  // 2) Backward for 60 seconds
  // ===================================

  moveWithSensor(backward, 60000);

  stopMotors();
  delay(1000);


  // ===================================
  // 3) Right / Left for 60 seconds
  // ===================================

  for (int i = 0; i < 30; i++) {

    // Right
    turnRight();
    myServo.write(30);

    delay(1000);


    // Check obstacle
    if (obstacleDetected()) {
      avoidObstacle();
    }


    // Left
    turnLeft();
    myServo.write(150);

    delay(1000);


    // Check obstacle
    if (obstacleDetected()) {
      avoidObstacle();
    }
  }


  // ===================================
  // Finish
// ===================================

  stopMotors();

  myServo.write(90);


  // Prevent program from repeating
  while (true) {
  }
}
