#include <Servo.h>

Servo myServo;

int const potPort = A0;
int potVal;
int angle;

int const servoPort = 9;

void setup() {
  myServo.attach(9);
  
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPort);
  Serial.print("Potentiometer Value: ");
  Serial.print(potVal);
  
  angle = map(potVal, 0, 1023, 0, 178);
  Serial.print(" ,Angle: ");
  Serial.print(angle);
  
  myServo.write(angle);
  delay(15);
    
}
