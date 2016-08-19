#include <IRremote.h>

IRrecv irrecv(3); // пин, к которому подключен приемник
int ledPin = 4; // пин, к которому подключен диод
int pePin  = 9; // пин, к которому подключен пьезоэлемент
decode_results results;

void setup() {
  Serial.begin(9600); // Выставляем скорость COM порта
  irrecv.enableIRIn(); // Запускаем прием
  pinMode(pePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) // Если данные пришли
  {
    Serial.println(results.value, HEX); // Отправляем полученную данную в консоль

//    if (results.value == 0x5E25)
//    {
//      tone (pePin, 200);
//      delay(200);
//      tone (pePin, 200);
//      delay(200);
//    }

    if (results.value == 0x5D0)
      digitalWrite(ledPin, HIGH);

    if (results.value != 0x5D0)
      digitalWrite(ledPin, LOW);

    irrecv.resume(); // Принимаем следующую команду
  }
}


