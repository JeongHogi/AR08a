#include <Stepper.h>

const int stepsPerRevolution = 1024; 

Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 25);
  
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution / 100);  // CW vs. CCW
  }

  Serial.print("A0 = ");
  Serial.println(sensorReading);
  delay(500);
}
