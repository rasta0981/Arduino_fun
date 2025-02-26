int ledPin = 4;
int ledPin1 = 0;
int ledPin2 = 2;
int microphonePin = 36;
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(microphonePin, INPUT);
}

void loop() {
  state = digitalRead(microphonePin);

  if (state == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(90);
    digitalWrite(ledPin, LOW);
    delay(90);
    digitalWrite(ledPin1, HIGH);
    delay(90);
    digitalWrite(ledPin1, LOW);
    delay(90);
    digitalWrite(ledPin2, HIGH);
    delay(90);
    digitalWrite(ledPin2, LOW);
    delay(90);
  }

  //else {
    //digitalWrite(ledPin, LOW);
    //delay(70);
  //}
}
