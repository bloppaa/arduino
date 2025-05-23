## Motor Stepper

```c
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
```

## Motor Servo

```c
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
```

## Pantalla LED
```c
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Hello, World!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
  lcd.print(" segundos");

  delay(1000);
}
```

## Sensor ultrasónico
```c
const int trig = 10;
const int eco = 9;
float duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(eco, INPUT);
  pinMode(trig, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delay(4);

  digitalWrite(trig, HIGH);
  delay(10);

  digitalWrite(trig, LOW);
  duration = pulseIn(eco, HIGH);
  distance = duration / 58;

  Serial.println(distance);
  delay(1000);
}
```

## Keypad 3x4
```c
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
}
```
