#include <AFMotor.h>

// motors
AF_DCMotor left(2);
AF_DCMotor right(3);

// sensor pins
int leftSensorPin = A2;
int rightSensorPin = A1;
int middleSensorPin = A0;

int leftVal;    // 1 kapag walang nadetect, 0 kapag meron
int rightVal;   // 1 kapag walang nadetect, 0 kapag meron
int centerVal;  // 1 kapag walang nadetect, 0 kapag meron

// speed adjustments
int mainSpeed = 500;
int turnSpeed = 400;

void setup() {
  Serial.begin(9600);

  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  pinMode(middleSensorPin, INPUT);

  right.setSpeed(mainSpeed);
  left.setSpeed(mainSpeed);
}

void loop() {
  goEugene();
}

void goEugene() {
  leftVal = digitalRead(leftSensorPin);      // 1 kapag walang nadetect, 0 kapag meron
  rightVal = digitalRead(rightSensorPin);    // 1 kapag walang nadetect, 0 kapag meron
  centerVal = digitalRead(middleSensorPin);  // 1 kapag walang nadetect, 0 kapag meron

  // 000
  if (leftVal == 0 && centerVal == 0 && rightVal == 0) {
    Serial.println("LINE PLEASE!");

    left.run(FORWARD);
    left.setSpeed(turnSpeed);

    right.run(RELEASE);
    right.setSpeed(0);
  }
  // 010
  else if (leftVal == 0 && centerVal == 1 && rightVal == 0) {
    Serial.println("DERETSO LANG!");

    left.run(FORWARD);
    left.setSpeed(mainSpeed);

    right.run(FORWARD);
    right.setSpeed(mainSpeed);
  }

  // 100
  else if (leftVal == 1 && centerVal == 0 && rightVal == 0) {
    Serial.println("TURN LEFT!");

    left.run(BACKWARD);
    left.setSpeed(turnSpeed);

    right.run(FORWARD);
    right.setSpeed(turnSpeed);
  }

  // 001
  else if (leftVal == 0 && centerVal == 0 && rightVal == 1) {
    Serial.println("TURN RIGHT!");

    left.run(FORWARD);
    left.setSpeed(turnSpeed);

    right.run(BACKWARD);
    right.setSpeed(turnSpeed);
  }

  //011
  else if (leftVal == 0 && centerVal == 1 && rightVal == 1) {
    Serial.println("TURN RIGHT!");

    left.run(FORWARD);
    left.setSpeed(turnSpeed);

    right.run(BACKWARD);
    right.setSpeed(turnSpeed);
  }

  //110
  else if (leftVal == 1 && centerVal == 1 && rightVal == 0) {
    Serial.println("TURN LEFT!");

    left.run(BACKWARD);
    left.setSpeed(turnSpeed);

    right.run(FORWARD);
    right.setSpeed(turnSpeed);
  }

  //101
  else if (leftVal == 1 && centerVal == 0 && rightVal == 1) {
    Serial.println("DERETSO LANG!");

    left.run(FORWARD);
    left.setSpeed(mainSpeed);

    right.run(FORWARD);
    right.setSpeed(mainSpeed);
  }

  //111
  else if (leftVal == 1 && centerVal == 1 && rightVal == 1) {
    Serial.println("DERETSO LANG!");

    left.run(FORWARD);
    left.setSpeed(mainSpeed);

    right.run(FORWARD);
    right.setSpeed(mainSpeed);
  }
}

// // deretso lang
// if (leftVal == !Black && centerVal == !Black && rightVal == !Black) {
//   Serial.println("DERETSO LANG!");

//   left.run(FORWARD);
//   right.run(FORWARD);
// }

// // turn left
// if (leftVal == Black && centerVal == !Black && rightVal == !Black) {
//   Serial.println("TURN LEFT!");

//   left.run(BRAKE);
//   right.run(FORWARD);
// }

// // turn right
// if (leftVal == !Black && centerVal == !Black && rightVal == Black) {
//   Serial.println("TURN RIGHT!");

//   left.run(FORWARD);
//   right.run(BRAKE);
// }