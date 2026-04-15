#include <Servo.h>

Servo servo1;
Servo servo2;
const int babyMariaPin = 12;
const int servo1Pin = 13;

const int ejectButtonPin = 2;
const int servo2Pin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(babyMariaPin, INPUT_PULLUP);
  pinMode(ejectButtonPin, INPUT_PULLUP);
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo1.write(0); // resets testing tube to closed state. place baby shadow in AFTER
  servo2.write(0); // resets eject floor to closed state

  
}

void loop() {
  Serial.println(digitalRead(babyMariaPin));
  if (digitalRead(ejectButtonPin) == LOW)
  {
    servo2.write(70);
  }
  if (digitalRead(babyMariaPin) == LOW)
  {
    servo1.write(180);
  }
  //servo1.write(90);
}
