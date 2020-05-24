// помогаем миллису сохранить свой счёт на время сна sleep
#include <GyverPower.h>

// На время сна в большинстве режимов millis() останавливается, скорректировать можно вручную.
// Функция sleep спит не ровно указанное время, так как WDT таймер имеет заводскую неточность.
// Данный пример показан чисто для примера, не рекомендуется его использовать.
// Для точных периодов сна используйте sleedDelay и калибровку WDT
// см. пример sleepDelayMillis

// "вытягиваем" переменную, отвечающую за счётчик миллис
extern volatile unsigned long timer0_millis;

void setup() {
  Serial.begin(9600);
  // по умолчанию стоит самый экономный режим сна POWER DOWN
}

void loop() {
  // опрашиваем датчики, мигаем светодиодами, etc
  // таймер на миллис на 3 секунды для теста
  static uint32_t tmr;
  if (millis() - tmr >= 3000) {
    tmr = millis();
    Serial.println("kek");
    delay(50);
  }

  // спим ~512 мс
  power.sleep(SLEEP_512MS);

  // скорректировали миллис: прибавили время сна к счётчику миллис
  timer0_millis += 512;
}
