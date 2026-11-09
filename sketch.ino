#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;
const int ledPin = 13;

Servo parkingGate;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  parkingGate.attach(servoPin);
  parkingGate.write(0);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < 20) {
    parkingGate.write(90);
    digitalWrite(ledPin, HIGH);
    Serial.println("Car Detected - Gate OPEN");
  } 
  else {
    parkingGate.write(0);
    digitalWrite(ledPin, LOW);
    Serial.println("No Car - Gate CLOSED");
  }

  delay(500);
}
