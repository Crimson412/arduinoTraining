
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define battPin A0

//https://arduinogetstarted.com/tutorials/arduino-lcd-i2c

void setup() {
  lcd.init();  //using init instead of begin got it to work
  lcd.backlight();
  pinMode(battPin, INPUT);
}

void loop() {
  int voltReading = analogRead(battPin);
  float volts = (voltReading/69.12); //1023 (max analog output) / 14.8 max voltage of our battery
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(volts);
  lcd.print("V");
  delay(1000);
}
