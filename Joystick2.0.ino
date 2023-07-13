#define joyX A0
#define joyY A1
#define A 11
#define a 10
#define B 9
#define b 6
#define C 5
#define c 3

void setup() {
  Serial.begin(9600);
}

void loop() {
int xValue = analogRead(joyX);
int yValue = analogRead(joyY);
int writeX;
int writeY;
writeX = pwm(xValue);
writeY = pwm(yValue);

if (writeY != 0){
  if (writeY < 0){
    analogWrite(a, abs(writeY));
    analogWrite(A, 0);
    analogWrite(b, abs(writeY));
    analogWrite(B, 0);
    analogWrite(c, abs(writeY));
    analogWrite(C, 0);
  } else{
    analogWrite(A, writeY);
    analogWrite(a, 0);
    analogWrite(B, writeY);
    analogWrite(b, 0);
    analogWrite(C, writeY);
    analogWrite(c, 0);
  }
} else{
    if (writeX < 0){
      Serial.print("right");
      analogWrite(a, abs(writeX));
      analogWrite(A, 0);
      analogWrite(b, abs(writeX));
      analogWrite(B, 0);
      analogWrite(C, abs(writeX));
      analogWrite(c, 0);
    } else{
      Serial.print("left");
      analogWrite(A, 0);
      analogWrite(a, 0);
      analogWrite(B, 0);
      analogWrite(b, 0);
      analogWrite(C, 0);
      analogWrite(c, 0);
    }
}
Serial.print(writeX);
Serial.print("\t");
Serial.println(writeY);
}

int pwm(int value){
  while (value > 10)
    value /= 10;
int multiplier = (10 - value);
int subtract = (51*multiplier);
value = (255 - subtract);
return value;
}