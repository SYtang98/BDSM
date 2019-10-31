#include <Servo.h>
#include <Wire.h>
const int ledPin = 13; // the number of the LED pin
Servo myservo; // create servo object to control a servo
int val; // variable to read the value from the analog pin
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  Wire.begin(8); // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600); // start serial for output
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
}
void loop() {
  delay(1000);
}
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c); // print the character
  }
  int x = Wire.read(); // receive byte as an integer
  Serial.println(x); // print the integer

  if (x == 1) {
    digitalWrite(ledPin, HIGH);
    myservo.write(180); // sets the servo position
    delay(15); // waits for the servo to get there
  } else {
    digitalWrite(ledPin, LOW);
    myservo.write(0); // sets the servo position
    delay(15); // waits for the servo to get there
  }

}
