
#include <Servo.h>

int servoPin = 10;
int servoAngle = 180;
int delayAmout = 1000;

Servo angler;

void setup() {
  // Attach the servo's pin number to the servo object
  angler.attach(servoPin);
}

void loop() {
  // Set the servo angle
  angler.write(servoAngle);
  delay(delayAmout);
  angler.write(0);
  delay(delayAmout);
  
}