
#include <SoftwareSerial.h>

// HC-05 Bluetooth communication
// Arduino D2 = RX, Arduino D3 = TX
SoftwareSerial bluetooth(2, 3);

// L293D Motor Driver Pins
const int ENA = 5;  // Left motor speed (PWM)
const int IN1 = 8;
const int IN2 = 9;

const int ENB = 6;  // Right motor speed (PWM)
const int IN3 = 10;
const int IN4 = 11;

// Motor speed: 0 to 255
int motorSpeed = 150;

void setup() {

  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();

  Serial.println("SMART WHEELCHAIR READY");
  Serial.println("Waiting for Bluetooth commands...");
}

void loop() {

  if (bluetooth.available()) {

    char command = bluetooth.read();

    // Convert lowercase to uppercase
    if (command >= 'a' && command <= 'z') {
      command = command - 32;
    }

    Serial.print("Received Command: ");
    Serial.println(command);

    switch (command) {

      case 'F':
        moveForward();
        break;

      case 'B':
        moveBackward();
        break;

      case 'L':
        turnLeft();
        break;

      case 'R':
        turnRight();
        break;

      case 'S':
        stopMotors();
        break;

      default:
        stopMotors();
        Serial.println("Invalid Command");
        break;
    }
  }
}

// Move Forward
void moveForward() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("MOVING FORWARD");
}

// Move Backward
void moveBackward() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("MOVING BACKWARD");
}

// Turn Left
void turnLeft() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("TURNING LEFT");
}

// Turn Right
void turnRight() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("TURNING RIGHT");
}

// Stop all motors
void stopMotors() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println("MOTORS STOPPED");
}
