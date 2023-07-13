void setup() {
  Serial.begin(9600);
}

void loop() {
  int main = 12;
  int divisor_1 = 3;
  int divisor_2 = 6;
  int divisor_3 = 5;
  float first;
  float second;
  float third;
  first = divide(main, divisor_1);
  second = divide(main, divisor_2);
  third = divide(main, divisor_3);
  Serial.println(first);
  Serial.println(second);
  Serial.println(third);
  delay(5000); // Waits 5 seconds between loops
}

float divide(float initial, float divisor) { //had to change the inputs to floats as well to get a float result from their division
  float result;
  //Serial.println(initial);
  //Serial.println(divisor);
  result = initial / divisor;
  //Serial.println(result);
  return result;
}