#include <Servo.h>

Servo servo1;
Servo servo2;

Servo soldierLeft;
Servo soldierRight;

const int babyMariaPin = 12;
const int servo1Pin = 13;

const int benchPin = 8;
const int soldierRightPin = 6;
const int soldierLeftPin = 7;

int timerLength = 300;
int prevTime;
int currTime;
bool soldierStart = false;
bool soldierStop = false;

const int ejectButtonPin = 2;
const int servo2Pin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(babyMariaPin, INPUT_PULLUP);
  pinMode(ejectButtonPin, INPUT_PULLUP);
  pinMode(benchPin, INPUT_PULLUP);
  // pullup means the pin pulls up power and sends it, returning HIGH. when tape connection is made, power reaches ground and returns LOW

  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  soldierLeft.attach(soldierLeftPin);
  soldierRight.attach(soldierRightPin);

  servo1.write(0); // resets testing tube to closed state. place baby shadow in AFTER
  servo2.write(15); // resets eject floor to closed state

}

void loop() {
  //Serial.println(digitalRead(babyMariaPin));
  if (digitalRead(ejectButtonPin) == LOW)
  {
    servo2.write(70);
  }

  if (digitalRead(babyMariaPin) == LOW)
  {
    servo1.write(180);
  }

  if (soldierStart == false)
  {

    Serial.println(digitalRead(benchPin));
    
    if (digitalRead(benchPin) == HIGH)
    {
      //Serial.println(0);
    }
    else if (digitalRead(benchPin) == LOW)
    {
      //Serial.println(1);
      currTime = millis();
      prevTime = currTime;
      soldierStart = true;
      Serial.println("start servos");

      soldierLeft.write(110);
      soldierRight.write(70);
    }
  }
  else if (!soldierStop)
  {
    Serial.println("soldiers go");
    currTime = millis();
    if (currTime - prevTime >= timerLength)
    {
      Serial.println("stop servos");
      soldierStop = true;

      soldierLeft.write(90);
      soldierRight.write(90);
    }
  }
  else
  {
    //Serial.println("stop servos");
  }

}
