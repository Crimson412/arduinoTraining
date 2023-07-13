const int ledPin = 9;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
 
}


void loop() {
  analogWrite(ledPin, brightness);
  brightness += fadeAmount;
  if (brightness <= 0 or brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}
