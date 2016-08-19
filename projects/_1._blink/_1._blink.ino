// first try

int ledPin= 13;

void setup()
{
  // initialize pins as outputs
  // 2 args - pin; IN/OUT
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin,HIGH);
  delay(200);
  digitalWrite(ledPin,LOW);
  delay(100);

  digitalWrite(ledPin,HIGH);
  delay(200);
  digitalWrite(ledPin,LOW);
  delay(100);

  digitalWrite(ledPin,HIGH);
  delay(200);
  digitalWrite(ledPin,LOW);
  delay(1000);
}

