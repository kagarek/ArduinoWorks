#define pot A0

void ledDigitDisplay(float num, float time)
{
  unsigned long ltime = millis();

  // Настройки
  // 6, 8, 9, 12 - GND

  // Пины
  int pin[] = {6, 7, 8, 9, 10, 2, 11, 3, 4, 12, 13, 5};

  // Порядок сегментов
  int settingsSegments[] = {
    pin[10],
    pin[6],
    pin[3],
    pin[1],
    pin[0],
    pin[9],
    pin[4],
    pin[2]
  };

  int segments[] = {
    0b00111111, //1
    0b00000110, //2
    0b01011011, //3
    0b01001111, //4
    0b01100110, //5
    0b01101101, //6
    0b01111101, //7
    0b00000111, //8
    0b01111111, //9
    0b01101111, //.
    0b10000000, //enable -
    0b01000000  //disable -
  };

  // Определяем пины как выход
  for (int i = 0; i < 12; ++i)
  {
    pinMode(pin[i], OUTPUT);
  }

  int floatingPoint = 0, minus = 4;

  // Разбираемся с отрицательными числами
  if (num > -1000 && num < 0)
  {
    minus--;
    if (num > -100) minus--;
    if (num > -10) minus--;
    num = -num;
  }

  // Разбираемся с дробными числами
  for (int i = 0; num < 1000 && minus == 4; ++i)
  {
    if (int(num * 10) != int(num) * 10)
    {
      floatingPoint++;
      num *= 10;
    }
    else
      break;
  }

  for (int i = 0, temp; millis() - ltime <= time * 1000; i++)
  {
    if (i == 4) i = 0;

    // Цифра которую передадим индикатору
    temp = int(num / pow(10, i)) % 10;

    // Решаем нужно ли включать 4й разряд
    if (i == 3 && (num >= 1000)) pinMode(pin[11], OUTPUT);
    else pinMode(pin[11], INPUT);

    // Решаем нужно ли включать 3й разряд
    if (i == 2 && (num >= 100)) pinMode(pin[8], OUTPUT);
    else pinMode(pin[8], INPUT);

    // Решаем нужно ли включать 2й разряд
    if (i == 1 && (num >= 10 )) pinMode(pin[7], OUTPUT);
    else pinMode(pin[7], INPUT);

    // Решаем нужно ли включать 1й разряд
    if (i == 0) pinMode(pin[5], OUTPUT);
    else pinMode(pin[5], INPUT);

    // Передаем число
    for (int j = 0; j < 8; j++)
      if (segments[temp] & (1 << j))
        digitalWrite(settingsSegments[j], HIGH);

    // Передаем точку
    if (floatingPoint && floatingPoint == i)
      digitalWrite(settingsSegments[7], HIGH);

    // Небольшая пауза, чтобы светодиоды разгорелись
    delay(1);

    // Выключаем все светодиоды
    for (int j = 0; j < 8; j++) digitalWrite(settingsSegments[j], LOW);
  }

  /*
   for (int i = 0, temp; millis() - ltime <= time * 1000; i++)
  {
    if (i == 4) i = 0;

    // Цифра которую передадим индикатору
    temp = int(num / pow(10, i)) % 10;

    // Если минус или переполнение, передаем '-'
    if (num >= 10000 || num <= -1000 || minus == i) temp = 11;

    // Решаем нужно ли включать 4й разряд
    if (i == 3 && (num >= 1000 || floatingPoint == i || minus == i)) pinMode(pin[11], OUTPUT);
    else pinMode(pin[11], INPUT);

    // Решаем нужно ли включать 3й разряд
    if (i == 2 && (num >= 100 || floatingPoint == i || minus == i)) pinMode(pin[8], OUTPUT);
    else pinMode(pin[8], INPUT);

    // Решаем нужно ли включать 2й разряд
    if (i == 1 && (num >= 10 || floatingPoint == i || minus == i)) pinMode(pin[7], OUTPUT);
    else pinMode(pin[7], INPUT);

    // Решаем нужно ли включать 1й разряд
    if (i == 0) pinMode(pin[5], OUTPUT);
    else pinMode(pin[5], INPUT);

    // Передаем число
    for (int j = 0; j < 8; j++)
      if (segments[temp] & (1 << j))
        digitalWrite(settingsSegments[j], HIGH);

    // Передаем точку
    if (floatingPoint && floatingPoint == i)
      digitalWrite(settingsSegments[7], HIGH);

    // Небольшая пауза, чтобы светодиоды разгорелись
    delay(1);

    // Выключаем все светодиоды
    for (int j = 0; j < 8; j++) digitalWrite(settingsSegments[j], LOW);
  }
   */
}

void setup()
{
  // пин с потенциометром - вход
  pinMode(pot, INPUT);
}

void loop()
{
  // объявляем переменную x
  int x;

  // считываем напряжение с потенциометра:
  // будет получено число от 0 до 1023
  x = analogRead(pot);

  ledDigitDisplay(x, 0.1);
  //ledDigitDisplay(3.14, 2);
  //ledDigitDisplay(123, 2);
  //ledDigitDisplay(-5, 2);
}
