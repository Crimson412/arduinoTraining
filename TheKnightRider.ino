int timer = 200;           // The higher the number, the slower the timing.

void setup() {
int thisPin = 2;

  while (thisPin < 8) {
    pinMode(thisPin, OUTPUT);
    thisPin++;
  }
}

void loop() {
  // loop from the lowest pin to the highest:

  for (int thisPin = 2; thisPin < 8; thisPin++) {

    // turn the pin on:

    digitalWrite(thisPin, HIGH);

    delay(timer);

    // turn the pin off:

    digitalWrite(thisPin, LOW);

  }

  // loop from the highest pin to the lowest:

  for (int thisPin = 7; thisPin >= 2; thisPin--) {

    // turn the pin on:

    digitalWrite(thisPin, HIGH);

    delay(timer);

    // turn the pin off:

    digitalWrite(thisPin, LOW);

  }
}
