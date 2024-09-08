#include <Servo.h>

int lightPin = 12;
int servoPin = 11;
int servoAngle = 180;
int delayAmount = 1000;
int br = 115200;
int trigPin = 9;
int echoPin =  10;

Servo angler;

void setup() {
  pinMode(lightPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  angler.attach(servoPin);
  Serial.begin(br);
}

void loop() {
  long duration, distance;
  
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in centimeters using the speed of sound
  distance = duration * 0.034 / 2;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if object is close enough
  if (distance < 20) {  // Object is within 20 cm
    digitalWrite(lightPin, HIGH);  // Turn on the LED
  } else {
    digitalWrite(lightPin, HIGH);  // Turn on the LED
    delay(200);
    digitalWrite(lightPin, LOW); 
    delay(200);  // Turn off the LED
    angler.write(servoAngle);
    delay(delayAmount);
    angler.write(0);
    delay(delayAmount);
  }
}