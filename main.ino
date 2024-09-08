#include <Servo.h>

int lightPin = 13;
int servoPin = 10;
int servoAngle = 180;
int delayAmount = 1000;
int br = 115200;
int trigPin = 11;
int echoPin = 9;

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
  
  // Calculate distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if object is close enough (you can adjust this threshold)
  if (distance < 20) {  // Object is within 20 cm
    digitalWrite(lightPin, HIGH);  // Turn on the LED
  } else {
    digitalWrite(lightPin, LOW);   // Turn off the LED
  }
  
  // Move the servo (if needed)
  angler.write(servoAngle);
  

}