int red = 13;
int green = 12;
int blue = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(blue,HIGH);
  
  delay(1000);
  digitalWrite(blue,LOW);

  delay(500);
  digitalWrite(red,HIGH);
  
  delay(500);
  digitalWrite(red,LOW);

  delay(1000);
  digitalWrite(green,HIGH);

  delay(5000);
  digitalWrite(green,LOW);
}
