#include <Arduino.h>

int POTENCIOMETRO = A0;
int MOTOR1 = 5;
int MOTOR2 = 6;

void setup()
{
    Serial.begin(9600);
    pinMode(POTENCIOMETRO, INPUT);
    pinMode(MOTOR1, OUTPUT);
    pinMode(MOTOR2, OUTPUT);
}

void loop()
{
    int value = analogRead(POTENCIOMETRO) / (1023 / 510);

    int M1VALUE = 0;
    int M2VALUE = 0;

    if (value > 255)
    {
        M2VALUE = 0;
        M1VALUE = value - 256;
    }
    else
    {
        M2VALUE = 255 - value;
        M1VALUE = 0;
    }

    analogWrite(MOTOR1, M1VALUE);
    analogWrite(MOTOR2, M2VALUE);

    Serial.print("M1: ");
    Serial.println(M1VALUE);
    Serial.print("M2: ");
    Serial.println(M2VALUE);

    delay(100);
}