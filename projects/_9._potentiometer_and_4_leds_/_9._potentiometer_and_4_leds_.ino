// даём имена пинов со светодиодами
// и потенциометром
int lRed = 3;
int lYellow1 = 5;
int lYellow2 = 6;
int lGreen = 9;
int pot = A0;

int pot_value;

void setup() {

  pinMode(lRed, OUTPUT);
  pinMode(lYellow1, OUTPUT);
  pinMode(lYellow2, OUTPUT);
  pinMode(lGreen, OUTPUT);

  pinMode(pot, INPUT);

  pot_value = analogRead(pot);

}

void loop() {

  if (pot_value >  255 * 3)
  {
    analogWrite(lRed, 255);
    analogWrite(lYellow1, 255);
    analogWrite(lYellow2, 255);
    if (pot_value - 255 * 3 > 255)
    {
      pot_value = 255;
      analogWrite(lGreen, pot_value);
    }
    else
    {
      analogWrite(lGreen, pot_value - 255 * 3);
    }
    pot_value = analogRead(pot);
  }
  else if (pot_value >  255 * 2) {
    analogWrite(lRed, 255);
    analogWrite(lYellow1, 255);
    analogWrite(lYellow2, pot_value - 255 * 2);
    analogWrite(lGreen, 0);
    pot_value = analogRead(pot);
  } else if (pot_value >  255 * 1) {
    analogWrite(lRed, 255);
    analogWrite(lYellow1, pot_value - 255 * 1);
    analogWrite(lYellow2, 0);
    analogWrite(lGreen, 0);
    pot_value = analogRead(pot);
  } else if (pot_value >=  255 * 0) {
    analogWrite(lRed, pot_value);
    analogWrite(lYellow1, 0);
    analogWrite(lYellow2, 0);
    analogWrite(lGreen, 0);
    pot_value = analogRead(pot);
  }

}
