//#include <Servo.h>
//Servo servo;
int led1 = 8;
int led2 = 7;
int buttonON = 12;
boolean switcher = false;
//int flag = 0;

void setup() {
  //servo.attach(10);
  pinMode(buttonON,INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

checkSwitch();
enableSemafors();

}

/*
  if(digitalRead(buttonON)==HIGH && flag==0) //если кнопка нажата и перемення flag равна 0 , то ...
  {
    flag=1;
    //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие
  }

  if(digitalRead(buttonON)==LOW && flag==1) //если кнопка НЕ нажата и переменная flag равна - 1 ,то ...
  {
    enableSemafors();
    flag=0;//обнуляем переменную flag
  }
*/
//servo
//servo.write(45);
//delay(3000);
//servo.write(135);
//delay(3000);
}

void enableSemafors(){
  while (switcher) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    checkSwitch();
    delay(250);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    checkSwitch();
    delay(250);
  }
}

// need to keep button around 1 sec to disable everything
void checkSwitch(){
  if (digitalRead(buttonON) == HIGH){
    switcher = !switcher;
  }
}


