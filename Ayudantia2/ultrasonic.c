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