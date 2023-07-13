//initialize variables, and make pins constants
const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;

void setup() {
  //Set the two pins to input and output respectively
pinMode(buttonPin, INPUT);
pinMode(ledPin, OUTPUT);
}

void loop() {
buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
digitalWrite(ledPin, HIGH);
} else {
digitalWrite(ledPin, LOW);
} 
}
