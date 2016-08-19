//#include <Servo.h>
int led1 = 8;
int led2 = 7;
int buttonON = 12;
//Servo servo;
boolean switcher = false;


void setup() {
  //servo.attach(10);
  pinMode(buttonON,INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
//button
  checkSwitch();

  if (switcher){
    enableSemafor1();
    enableSemafor2();
  }
  
//servo
//servo.write(45);
//delay(3000);
//servo.write(135);
//delay(3000);
}

void enableSemafor1(){
    digitalWrite(led1, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    delay(250);
    checkSwitch();
}

void enableSemafor2(){
    digitalWrite(led2, HIGH);
    delay(250);
    digitalWrite(led2, LOW);
    delay(250);
    checkSwitch();
}

// need to keep button around 1 sec to disable everything
void checkSwitch(){
  if (digitalRead(buttonON)== HIGH){
    switcher = !switcher;
  }
}


