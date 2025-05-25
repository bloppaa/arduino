#include <Servo.h>

Servo servo;

int pos = 0;

void setup() {
  servo.attach(9);
  Serial.begin(9600);
}

void loop() {
  for (pos = 0; pos <= 90; pos += 1) {
    servo.write(pos);
    delay(10);
}
  for (pos = 90; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(100);
  }
}