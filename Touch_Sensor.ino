const int touchPort = 13;
const int ledPort = 11;
int touchValue;

void setup() {
  pinMode(touchPort, INPUT);
  pinMode(ledPort, OUTPUT);
}

void loop() { 
  touchValue = digitalRead(touchPort);
  if (touchValue == HIGH) {
    digitalWrite(ledPort, HIGH);
  } else {
    digitalWrite(ledPort, LOW);
  }
  delay(10);
}
