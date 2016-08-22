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
  if(digitalRead(buttonON)==HIGH && flag==0) //���� ������ ������ � ��������� flag ����� 0 , �� ...
  {
    flag=1;
    //��� ����� ��� ���� ��� �� � ������ �������� ������ ����������� ������ ���� ��������
  }

  if(digitalRead(buttonON)==LOW && flag==1) //���� ������ �� ������ � ���������� flag ����� - 1 ,�� ...
  {
    enableSemafors();
    flag=0;//�������� ���������� flag
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


