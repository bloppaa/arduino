const int micPin = A0;

int micVal  = 0;

void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);
}

void loop() {
  readMicrophone();
}

void readMicrophone( ) {
  micVal = analogRead(micPin);
  Serial.print("mic val ");
  Serial.println(micVal);
  
  if (micVal > 600) {
    Serial.println("mic detected");
  }
}
