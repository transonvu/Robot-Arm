#pragma once
#include <Servo.h>
#include <Arduino.h>
#include "RAPoint.h"

class RAServo
{
private:
  Servo _servo;
  RAPoint<double, 3> _position;
  int _delay;

public:
  RAServo();
  RAServo(int delay);
  RAServo(const RAPoint<double, 3> &position);
  RAServo(int delay, const RAPoint<double, 3> &position);
  ~RAServo();
  uint8_t attach(int pin);
  void detach();
  void write(int value);
  int read();
  bool attached();
  void setDelay(int d);
  int getDelay();
  void setPosition(const RAPoint<double, 3> &p);
  const RAPoint<double, 3> getPosition();  
};
