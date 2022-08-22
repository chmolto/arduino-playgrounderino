#include <Arduino.h>

const int MID_LED = 13;
const int TOPLEFT_LED = 12;
const int TOPRIGHT_LED = 8;
const int TOP_LED = 10;
const int BOTRIGHT_LED = 9;
const int BOTLEFT_LED = 11;
const int BOT_LED = 7;

const int LEFT_DISPLAY = 6;
const int RIGHT_DISPLAY = 5;

const int LED_NUMBERS[10][7] = {
    {0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

int CONTADOR = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LEFT_DISPLAY, OUTPUT);
  pinMode(RIGHT_DISPLAY, OUTPUT);
  pinMode(TOP_LED, OUTPUT);
  pinMode(TOPLEFT_LED, OUTPUT);
  pinMode(TOPRIGHT_LED, OUTPUT);
  pinMode(MID_LED, OUTPUT);
  pinMode(BOT_LED, OUTPUT);
  pinMode(BOTRIGHT_LED, OUTPUT);
  pinMode(BOTLEFT_LED, OUTPUT);
}

void loop()
{
  int first = CONTADOR % 10;
  int second;
  if (CONTADOR < 10)
  {
    second = 0;
  }
  else
  {
    second = (CONTADOR / 10) % 10;
  }
  writeNumbers(second, first);
  CONTADOR = CONTADOR + 1;
}

void writeNumbers(int firstNumber, int secondNumber)
{
  for (int i = 0; i < 20; i++)
  {
    const int LEDS_LENGTH = sizeof(LED_NUMBERS[1]) / 2;
    for (int i = 0; i < LEDS_LENGTH; i++)
    {
      int LED_PIN_NUMBER = i + 7;
      int LED_STATE = LED_NUMBERS[firstNumber][i];
      digitalWrite(LED_PIN_NUMBER, LED_STATE);
    }
    digitalWrite(LEFT_DISPLAY, 1);
    digitalWrite(RIGHT_DISPLAY, 0);
    delay(10);
    for (int i = 0; i < LEDS_LENGTH; i++)
    {
      int LED_PIN_NUMBER = i + 7;
      int LED_STATE = LED_NUMBERS[secondNumber][i];
      digitalWrite(LED_PIN_NUMBER, LED_STATE);
    }
    digitalWrite(LEFT_DISPLAY, 0);
    digitalWrite(RIGHT_DISPLAY, 1);
    delay(10);
  }
}
