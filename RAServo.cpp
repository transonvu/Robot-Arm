#include "RAServo.h"

const int defaultDelay = 20;
const double defaultElements[3] = {0.0, 0.0, 0.0};
const RAPoint<double, 3> defaultPosition(defaultElements);

RAServo::RAServo()
{
  _delay = defaultDelay;
  _position = defaultPosition;    
}

RAServo::RAServo(int delay)
{
  _delay = delay;
  _position = defaultPosition;  
}

RAServo::RAServo(const RAPoint<double, 3> &position)
{
  _delay = defaultDelay;
  _position = position;  
}

RAServo::RAServo(int delay, const RAPoint<double, 3> &position)
{
  _delay = delay;
  _position = position;  
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

void RAServo::write(int value)
{
  int oldValue = _servo.read();
  int distance = value - oldValue;
  int sign = (value > oldValue) ? 1 : -1;
  distance *= sign;
  for (int i = 0; i < distance; ++i)
  {
    _servo.write(oldValue + sign * (i + 1));    
    delay(_delay);
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

void RAServo::setDelay(int d)
{
  _delay = d;
}

int RAServo::getDelay()
{
 return _delay; 
}

void RAServo::setPosition(const RAPoint<double, 3> &p)
{
  _position = p;
}

const RAPoint<double, 3> RAServo::getPosition()
{
  return _position;
}

