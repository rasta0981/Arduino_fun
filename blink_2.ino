
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(2, HIGH);   // turn red LED on
  delay(50);               // wait
  digitalWrite(2, LOW);    // turn LED off
  delay(90);               // wait
  
  digitalWrite(0, HIGH);   // turn yellow LED on
  delay(50);               // wait
  digitalWrite(0, LOW);    // turn LED off
  delay(90);               // wait
  
  digitalWrite(4, HIGH);   // turn green LED on
  delay(50);               // wait
  digitalWrite(4, LOW);    // turn LED off
  delay(90);               // wait
}       
