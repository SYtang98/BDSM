#include <CapacitiveSensor.h> //10M Resistor between pins 7 and 8, you may also connect an antenna on pin 8
#include <Wire.h>

CapacitiveSensor Sensor = CapacitiveSensor(7, 8);
long val;
int pos;
#define led 13

void setup()
{
Serial.begin(9600);
pinMode(led, OUTPUT);
Wire.begin(); // join i2c bus (address optional for master)
}

void loop()
{

val = Sensor.capacitiveSensor(30);
Serial.println(val);
if (val >= 1000 && pos == 0)
{
digitalWrite(led, HIGH);
Wire.beginTransmission(8); // transmit to device #8
Wire.write("x is "); // sends five bytes
Serial.println("X is 1");
Wire.write(1); // sends one byte
Wire.endTransmission(); // stop transmitting 
pos = 1;
delay(500);
}

else if (val >= 1000 && pos == 1)
{
digitalWrite(led, LOW);
Wire.beginTransmission(8); // transmit to device #8
Wire.write("x is "); // sends five bytes
Serial.println("X is 0");
Wire.write(0); // sends one byte
Wire.endTransmission(); // stop transmitting
pos = 0;
delay(500);
}
delay(10);
}
