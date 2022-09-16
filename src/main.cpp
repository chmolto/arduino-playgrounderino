#include <Arduino.h>

const int ECHO = 10;
const int TRIGG = 9;
const float SOUND_SPEED = 0.034;

void setup()
{
    Serial.begin(9600);
    pinMode(ECHO, INPUT);
    pinMode(TRIGG, OUTPUT);
}

void loop()
{
    digitalWrite(TRIGG, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIGG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGG, LOW);

    long duration = pulseIn(ECHO, HIGH);
    long distance = duration * SOUND_SPEED / 2;

    Serial.print("Distance: ");
    Serial.println(distance);
}