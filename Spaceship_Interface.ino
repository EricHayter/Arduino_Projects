// very simple sketch that allows for a green light to constantly be on until
// a button is pressed which turns it off an alternates a two red LED's
void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // getting the input of the button
  int switchState = digitalRead(2);
  // if the button is not pressed
  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  // if the button is pressed
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    delay(250);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    
    delay(250);
  }
}
