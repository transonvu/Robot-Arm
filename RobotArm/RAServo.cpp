#include "RAServo.h"

RAServo::RAServo()
{
}

RAServo::~RAServo()
{
}

uint8_t RAServo::attach(int pin)
{
  return _servo.attach(pin);
}

void RAServo::detach()
{
  _servo.detach();  
}

void RAServo::write(int value, int time = 20)
{
  int oldValue = _servo.read();
  int distance = value - oldValue;
  int sign = (value > oldValue) ? 1 : -1;
  distance *= sign;
  for (int i = 0; i < distance; ++i)
  {
    _servo.write(oldValue + sign * (i + 1));    
    delay(time);
  }
}

int RAServo::read()
{
  return _servo.read();
}

bool RAServo::attached()
{
  return _servo.attached();  
}
