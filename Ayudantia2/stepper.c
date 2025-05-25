#include <Stepper.h>

const int stepsPerRevolution = 2038;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {

}

void loop() {
  myStepper.setSpeed(5);
  myStepper.step(stepsPerRevolution);
  delay(1000);

  myStepper.setSpeed(10);
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}