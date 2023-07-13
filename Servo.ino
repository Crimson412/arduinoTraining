#include <Servo.h> 
Servo servo;
const int time = 100;
//https://docs.arduino.cc/learn/electronics/servo-motors

void setup() {
  servo.attach(26); //analog, pwm, and normal digital pins all work for this
  Serial.begin(9600);
  servo.write(90);
}

void loop() {
  char byte = 0;
  Serial.readBytes(&byte, 1);
  Serial.print(byte);
  if (byte == 'R'){
    servo.write(360);
  }
  if (byte == 'L'){
    servo.write(0);
  }
  if (byte == 'O'){
    servo.write(90);
  }
  if (byte == 'P'){
    while (byte != 'R' || byte != 'L' || byte != 'O'){
      int increment = -5;
      for (int degrees = 180; degrees < 181;){
        servo.write(degrees);
        if (degrees == 0){
          increment = 5;
        }
        degrees += increment;
        //delay(time);
      }
      Serial.readBytes(&byte, 1);
    }   
  }
}
