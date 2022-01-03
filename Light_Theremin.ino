const int sensorPort = A0;
int sensorValue;
int sensorHigh = 0;
int sensorLow = 1023;
const int piezoPort = 13;
int pitch;

void setup() {
  pinMode(piezoPort, OUTPUT);
  
  // callibrate the sensor for 5 seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPort);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    } else if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
    
  }
}

void loop() {
  sensorValue = analogRead(sensorPort);
  pitch = map(sensorValue, sensorLow, sensorHigh, 50,4000);
  tone(piezoPort, pitch, 20);
  delay(10);
}
