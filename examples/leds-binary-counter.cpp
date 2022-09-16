#include <Arduino.h>

int pins[] = {2, 3, 4, 5, 6};
int pinValues[] = {1, 2, 4, 8, 16};
int selectedValues[] = {0, 0, 0, 0, 0, 0};
int currentVal = 1;

void cleanSelectedValues()
{
  byte length = sizeof(selectedValues) / sizeof(selectedValues[0]);
  for (int i = 0; i < length; i++)
  {
    selectedValues[i] = 0;
  }
}

int findLowerOrSameBiggestValueIndex(int value)
{
  byte length = sizeof(pinValues) / sizeof(pinValues[0]);
  for (byte i = length - 1; i >= 0; i--)
  {
    if (value >= pinValues[i])
    {
      return i;
    }
  }
  return -1;
}

void setNumberInBinary(int value)
{
  cleanSelectedValues();
  int index = findLowerOrSameBiggestValueIndex(value);
  selectedValues[index] = HIGH;
  int tempSum = pinValues[index];
  for (int i = index - 1; i >= 0; i--)
  {
    bool condition = tempSum + pinValues[i] <= value;
    if (condition)
    {
      tempSum += pinValues[i];
      selectedValues[i] = HIGH;
    }
  }
}

void lightSelectedValues()
{
  byte length = sizeof(selectedValues) / sizeof(selectedValues[0]);
  for (int i = 0; i < length; i++)
  {
    digitalWrite(pins[i], selectedValues[i]);
  }
}

void setup()
{
  Serial.begin(9600);
  for (int i = 2; i <= 6; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  setNumberInBinary(currentVal);
  lightSelectedValues();
  currentVal < 32
      ? currentVal += 1
      : currentVal = 1;

  delay(200);
}
