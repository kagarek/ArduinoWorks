int button = 2;
int pe = 8;


void setup() //процедура setup
{
  pinMode(button, INPUT);
  pinMode(pe, OUTPUT);
}

void loop() //процедура loop
{

  int val = digitalRead(button);

  while (val == HIGH)
  {
    tone (pe, 1000);
    delay(500);
    tone (pe, 500);
    delay(500);
    val = digitalRead(button);
  }

  noTone (pe);
}
