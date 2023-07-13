//-------Temp and Hum sensor-------
#include <DHT.h>
#define DHTPIN 4     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT DHT22_SIG(DHTPIN, DHTTYPE); //// Initialize DHT sensor
int CHK;
float HUM;  //Stores humidity value
float TEMP; //Stores temperature value

void setup() {
  DHT22_SIG.begin();
  Serial.begin(9600);
}

int i = 0;           //ith trial

void loop() {
  HUM = DHT22_SIG.readHumidity();
  TEMP = DHT22_SIG.readTemperature(); //Print temp and humidity values to serial monitor
  //Serial.print("Humidity: ");
  Serial.print(i);
  Serial.print(',');
  Serial.print(HUM);
  Serial.print(',');
  Serial.print(TEMP);
  Serial.print('\n');
  //Serial.println(" Celsius");
  ;i=i+1;                                 //update ith trial
   
  delay(1000);                           //define update rate

}