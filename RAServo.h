#pragma once
#include <Servo.h>
#include <Arduino.h>
#include "RACoordinate.h"

class RAServo
{
private:
  Servo _servo;
  RACoordinate<double, 3> _position;
  int _delay;

public:
  RAServo();
  RAServo(int delay);
  RAServo(const RACoordinate<double, 3> &position);
  RAServo(int delay, const RACoordinate<double, 3> &position);
  ~RAServo();
  uint8_t attach(int pin);
  void detach();
  void write(int value);
  int read();
  bool attached();
  void setDelay(int d);
  int getDelay();
  void setPosition(const RACoordinate<double, 3> &position);
  const RACoordinate<double, 3> getPosition();
};
