#include <Arduino.h>

const int LEDPIN = 4;
int intensidadLed = 0;
boolean reversalMode = false;

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(intensidadLed);
  if (intensidadLed == 150)
  {
    reversalMode = true;
  }
  if (intensidadLed == 100)
  {
    reversalMode = false;
  }
  controlIntensidad();
}

void controlIntensidad()
{
  reversalMode ? intensidadLed-- : intensidadLed++;
  analogWrite(LEDPIN, intensidadLed);
  delay(50);
}
