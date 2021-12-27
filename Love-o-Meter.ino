const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
    // setup analog pin
    Serial.begin(9600);
    // setting up digital pins
    for (int pinNumber = 2; pinNumber < 5; pinNumber++ ){
      pinMode(pinNumber, OUTPUT);
      digitalWrite(pinNumber, LOW);
    }
}

void loop() {
    int sensorVal = analogRead(sensorPin);
    Serial.print("Sensor Value:");
    Serial.print(sensorVal);
    
    Serial.print(", Volts: ");
    float voltage = (sensorVal/1024.0)*5.0;
    Serial.print(voltage);
    
    Serial.print(", Degrees in C: ");
    float temperature = (voltage-0.5)*100;
    Serial.println(temperature);
    
    if (temperature < baselineTemp + 2) {
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
    } else if (temperature < baselineTemp+4) {
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
    } else if (temperature < baselineTemp+6) {
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
    } else {
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
    }
    
    delay(1);
}
