
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(0,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);               // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(90);               // wait for a second
  
  digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);               // wait for a second
  digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  delay(90);               // wait for a second
  
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);             // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(90);               // wait for a second
}       
