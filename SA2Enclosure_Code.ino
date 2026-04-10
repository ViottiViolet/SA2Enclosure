#include <Servo.h>

Servo servo1;
const int babyMariaPin = 9;
const int servo1Pin = 13;

void setup() {
  pinMode(babyMariaPin, INPUT);
  servo1.attach(servo1Pin);
  servo1.write(0); // resets testing tube to closed state. place baby shadow in AFTER

  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(babyMariaPin));
  if (digitalRead(babyMariaPin) == HIGH)
  {
    servo1.write(180);
  }
}
