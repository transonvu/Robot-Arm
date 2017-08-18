#include "RAAngle.h"

const uint8_t RAAngle::RADIAN = 0;
const uint8_t RAAngle::DEGREE = 1;

RAAngle::RAAngle()
{
  _angle = 0.0;
  _type = RADIAN;
}

RAAngle::RAAngle(double angle, uint8_t type)
{
  _angle = angle;
  _type = type;
}

RAAngle::RAAngle(uint8_t type)
{
  _angle = 0.0;
  _type = type;
}

RAAngle& RAAngle::operator = (double angle)
{
  _angle = angle;
  return (*this);
}

RAAngle& RAAngle::operator = (RAAngle &angle)
{
  _angle = angle._angle;
  return (*this);
}

RAAngle RAAngle::operator + (double angle)
{
  RAAngle t;
  t._angle = _angle + angle;
  return t;
}

RAAngle RAAngle::operator - (double angle)
{
  RAAngle t;
  t._angle = _angle - angle;
  return t;  
}

RAAngle RAAngle::operator + (RAAngle &angle)
{
  RAAngle t;
  t._angle = _angle + angle._angle;
  return t;
}

RAAngle RAAngle::operator - (RAAngle &angle)
{
  RAAngle t;
  t._angle = _angle - angle._angle;
  return t;
}

RAAngle RAAngle::operator * (double factor)
{
  RAAngle t;
  t._angle = _angle * factor;
  return t;  
}

RAAngle RAAngle::operator / (double divisor)
{
  RAAngle t;
  t._angle = _angle / divisor;
  return t;  
}

RAAngle& RAAngle::operator += (double angle)
{
  _angle += angle;
  return (*this);  
}

RAAngle& RAAngle::operator -= (double angle)
{
  _angle -= angle;
  return (*this);    
}

RAAngle& RAAngle::operator += (RAAngle &angle)
{
  _angle += angle._angle;
  return (*this);    
}

RAAngle& RAAngle::operator -= (RAAngle &angle)
{
  _angle -= angle._angle;
  return (*this);   
}

RAAngle& RAAngle::operator *= (double factor)
{  
  _angle *= factor;
  return (*this);  
}

RAAngle& RAAngle::operator /= (double divisor)
{
  _angle /= divisor;
  return (*this); 
}

void RAAngle::setType(uint8_t type)
{
  _type = type;
}

uint8_t RAAngle::getType()
{
  return _type;
}

double RAAngle::radian()
{
  switch (_type)
  {
    case RADIAN:
      return _angle;
    case DEGREE:
      return _angle * PI / 180;
  }
  return 0.0;  
}

double RAAngle::degree()
{
  switch (_type)
  {
    case RADIAN:
      return _angle * 180 / PI;
    case DEGREE:
      return _angle;
  }
  return 0.0;    
}

