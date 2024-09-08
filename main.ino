
#include <Servo.h>

int servoPin = 10;
int servoAngle = 0;
int delayAmout = 50;

Servo angler;

void setup() {
  // Attach the servo's pin number to the servo object
  angler.attach(servoPin);
}

void loop() {
  // Set the servo angle
  angler.write(servoAngle);
  delay(delayAmout);
  
}