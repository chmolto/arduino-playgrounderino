#include <Arduino.h>

const int LED = 13;
const int BUTTON = 2;
int buttonState = 0;
int previousButtonState = 0;
int ledState = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  buttonState = digitalRead(BUTTON);
  if (buttonState && !previousButtonState)
  {
    digitalWrite(LED, !ledState);
    ledState = !ledState;
  }
  previousButtonState = buttonState;
}
