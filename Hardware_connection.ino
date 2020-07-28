int ir = 3, detect = 2, pos;
#include <Servo.h>
Servo myservo;
void setup() {
  pinMode(detect, INPUT);
  pinMode(ir, INPUT);
  myservo.attach(4);
  myservo.write(-90);
  Serial.begin(9600);
}

void loop() {
  myservo.write(90);
  int a, b;
  a = digitalRead(detect);
  b = digitalRead(ir);
  if (a == 0)
  {
    delay(700);
    if (b == 0)
    {
      Serial.println("0");
      for (pos = 90; pos <= 180; pos++)
      {
        myservo.write(pos);
        delay(15);
      }
    }
  }
   myservo.write(90);

  if (a == 1)
  {
    delay(700);
    if (b == 0)
    {
      Serial.println("1");
      for (pos = 90; pos >= 0; pos -= 1)
      {
        myservo.write(pos);
        delay(15);
      }
    }
  }
}
