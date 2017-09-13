#include "SpeedyStepper.h"
#include "RCServo.h"
#include "states.h"

namespace MOTIONMACHINE {

SpeedyStepper stepper;
RCServo servo;

const byte homingPin = 25;
const byte microStepping = 4;
const byte stairPin = 3;
const float stepperSpeed = 110;
const float stepperAccel = 20;

void setup(){
  stepper.connectToPort(1); 
  servo.connectToPin(26);
  pinMode(stairPin, OUTPUT);
  servo.setServoPosition(-1.0);
  stepper.setStepsPerMillimeter(25*microStepping);
  stepper.setSpeedInMillimetersPerSecond(stepperSpeed);
  stepper.setAccelerationInMillimetersPerSecondPerSecond(stepperAccel);
  stepper.moveToHomeInMillimeters(-1, stepperSpeed, 254, homingPin);
}

void enter(){

}

void loop(){

}

void exit(){

}

void events::upRamp() {
  stepper.moveToPositionInMillimeters(225);
}

void events::upStairs() {
  digitalWrite(stairPin, HIGH);
  stepper.moveToHomeInMillimeters(-1, stepperSpeed, 254, homingPin);
  digitalWrite(stairPin, LOW);
}

void events::moveServo() {
  servo.setServoPosition(0);
  delay(1000);
  servo.setServoPosition(-1.0);
}

}
