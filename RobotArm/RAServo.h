#ifndef RASERVO_H
#define RASERVO_H

#include <Servo.h>
#include <Arduino.h>

class RAServo
{
private:
  Servo _servo;

public:
  RAServo();
  ~RAServo();
  uint8_t attach(int pin);
  void detach();
  void write(int value, int delay);
  int read();
  bool attached();
};

#endif // RASERVO_H
