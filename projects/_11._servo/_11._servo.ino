#include <Servo.h>
Servo servo;


void setup() {
  // put your setup code here, to run once:
servo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
servo.write(45);
delay(3000);
servo.write(135);
delay(3000);
}
