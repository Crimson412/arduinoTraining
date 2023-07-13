//-----------DHT22-------------Particle pins TXD and RXD respectively (2, 3)
#include <SoftwareSerial.h>
#include <DHT.h>
SoftwareSerial pmsSerial(2, 3);

//-------Temp and Hum sensor-------
/*
#define DHTPIN 4     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT DHT22_SIG(DHTPIN, DHTTYPE); //// Initialize DHT sensor
int CHK;
float HUM;  //Stores humidity value
float TEMP; //Stores temperature value
int i = 0;

// -------IR Sensor---------------
const int IR1_SIG = A2;
const int IR2_SIG = A1;
int IR1_SIG_V,IR2_SIG_V;

//------Ultra Sonic Sensor--------
const int pingPin = 6 ;

//--------Gas Sensor--------------
int gas_sensor;

//------------Servo---------------
#include <Servo.h> 
Servo servo;

// ------------>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<-------------------------
*/
void setup() {
  Serial.begin(115200);   // our debugging output
  pmsSerial.begin(9600); // sensor baud rate is 9600
  //DHT22_SIG.begin();
  //pinMode(IR1_SIG, INPUT);
  //pinMode(IR2_SIG, INPUT);
  
  //servo.attach(A4); //sets up servo to pin right now it is on pin 7
}
 
struct pms5003data {
  uint16_t framelen;
  uint16_t pm10_standard, pm25_standard, pm100_standard;
  uint16_t pm10_env, pm25_env, pm100_env;
  uint16_t particles_03um, particles_05um, particles_10um, particles_25um, particles_50um, particles_100um;
  uint16_t unused;
  uint16_t checksum;
};
 
struct pms5003data data;
    
void loop() {
  if (readPMSdata(&pmsSerial)) {
    // reading data was successful!
    /*
    Serial.println();
    Serial.println("---------------------------------------");
    Serial.println("Concentration Units (standard)");
    Serial.print("PM 1.0: "); Serial.print(data.pm10_standard);
    Serial.print("\t\tPM 2.5: "); Serial.print(data.pm25_standard);
    Serial.print("\t\tPM 10: "); Serial.println(data.pm100_standard);
    Serial.println("---------------------------------------");
    Serial.println("Concentration Units (environmental)");
    Serial.print("PM 1.0: "); Serial.print(data.pm10_env);
    Serial.print("\t\tPM 2.5: "); Serial.print(data.pm25_env);
    Serial.print("\t\tPM 10: "); Serial.println(data.pm100_env);
    Serial.println("---------------------------------------");
    Serial.print("Particles > 0.3um / 0.1L air:"); Serial.println(data.particles_03um);
    Serial.print("Particles > 0.5um / 0.1L air:"); Serial.println(data.particles_05um);
    Serial.print("Particles > 1.0um / 0.1L air:"); Serial.println(data.particles_10um);
    Serial.print("Particles > 2.5um / 0.1L air:"); Serial.println(data.particles_25um);
    Serial.print("Particles > 5.0um / 0.1L air:"); Serial.println(data.particles_50um);
    Serial.print("Particles > 10.0 um / 0.1L air:"); Serial.println(data.particles_100um);
    Serial.println("---------------------------------------");
    */
    int three = data.particles_03um;
    int five= data.particles_05um;
    int ten = data.particles_10um;
    int tf = data.particles_25um;
    int fz = data.particles_50um;
    int one = data.particles_100um;
    Serial.print("\n");
    Serial.print(0);
    Serial.print("\t");
    Serial.print(0);
    Serial.print("\t");
    Serial.print(0);
    Serial.print("\t");
    Serial.print(0);
    Serial.print("\t");
    Serial.print(0);
    Serial.print("\t");
    Serial.print(three);
    Serial.print("\t");
    Serial.print(five);
    Serial.print("\t");
    Serial.print(ten);
    Serial.print("\t");
    Serial.print(tf);
    Serial.print("\t");
    Serial.print(fz);
    Serial.print("\t");
    Serial.print(one);


//    delay (1000);

//    delay(10000); //Delay 2 sec.
    /*
    IR1_SIG_V = analogRead(IR1_SIG);
    IR2_SIG_V = analogRead(IR2_SIG);
    Serial.print("First IR: ");
    Serial.println(IR1_SIG_V);
    Serial.print("Second IR: ");
    Serial.print(IR2_SIG_V);
    */
  }
      // -----------------------------
   //Read data and store it to variables hum and temp
   /*
    HUM = DHT22_SIG.readHumidity();
    TEMP = DHT22_SIG.readTemperature(); //Print temp and humidity values to serial monitor
    Serial.print(i);
    Serial.print(',');
    Serial.print(HUM);
    Serial.print(',');
    Serial.print(TEMP);
    Serial.print("\n");
    i += 1;
    */
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  //long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

  /*
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  */

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  //pinMode(pingPin, INPUT);
  //duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  //inches = microsecondsToInches(duration);
  //cm = microsecondsToCentimeters(duration);
  //if (cm < 5) {
  //  Serial.print("Halt!");
  //}
  
  /*
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  

  gas_sensor = analogRead(3);
  Serial.println(gas_sensor);
  */
  
  //servo.write(0); // move MG996R's shaft to angle 0°
  //delay(1000);
}
/*
long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2; //73.7 microseconds per inch, and halve the time since its a there AND back. 
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2; // 29 microseconds per centimeter, and halve the time since its a there AND back.
}
*/
 
boolean readPMSdata(Stream *s) {
  if (! s->available()) {
    return false;
  }
  
  // Read a byte at a time until we get to the special '0x42' start-byte
  if (s->peek() != 0x42) {
    s->read();
    return false;
  }
 
  // Now read all 32 bytes
  if (s->available() < 32) {
    return false;
  }
    
  uint8_t buffer[32];    
  uint16_t sum = 0;
  s->readBytes(buffer, 32);
 
  // get checksum ready
  for (uint8_t i=0; i<30; i++) {
    sum += buffer[i];
  }
 
  /* debugging
  for (uint8_t i=2; i<32; i++) {
    Serial.print("0x"); Serial.print(buffer[i], HEX); Serial.print(", ");
  }
  Serial.println();
  */
  
  // The data comes in endian'd, this solves it so it works on all platforms
  uint16_t buffer_u16[15];
  for (uint8_t i=0; i<15; i++) {
    buffer_u16[i] = buffer[2 + i*2 + 1];
    buffer_u16[i] += (buffer[2 + i*2] << 8);
  }
 
  // put it into a nice struct :)
  memcpy((void *)&data, (void *)buffer_u16, 30);
 
  if (sum != data.checksum) {
    Serial.println("Checksum failure");
    return false;
  }
  // success!
  return true;
}
