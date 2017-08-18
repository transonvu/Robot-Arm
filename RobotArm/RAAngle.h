#ifndef RAANGLE_H
#define RAANGLE_H

#include <Arduino.h>

class RAAngle
{
private:
  uint8_t _type;
  double _angle;
public:
  static const uint8_t RADIAN;
  static const uint8_t DEGREE;
  RAAngle();
  RAAngle(double angle, uint8_t type);
  RAAngle(uint8_t type);
  RAAngle& operator = (double angle);
  RAAngle& operator = (RAAngle &angle);
  RAAngle operator + (double angle);
  RAAngle operator - (double angle);
  RAAngle operator + (RAAngle &angle);
  RAAngle operator - (RAAngle &angle);
  RAAngle operator * (double factor);
  RAAngle operator / (double divisor);
  RAAngle& operator += (double angle);
  RAAngle& operator -= (double angle);
  RAAngle& operator += (RAAngle &angle);
  RAAngle& operator -= (RAAngle &angle);
  RAAngle& operator *= (double factor);
  RAAngle& operator /= (double divisor);
  
  void setType(uint8_t type);
  uint8_t getType();
  double radian();
  double degree();
};

#endif // RAANGLE_H
