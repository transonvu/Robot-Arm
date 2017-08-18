#include "RAServos.h"

/*
bool RAServos::isNearest(RAPoint<float, 3> &end, RAPoint<float, 3> &object)
{
  if (end.distance(object) < 0.1)
  {
    return true;
  }
  return false;
}

RAPoint<double, 3>* RAServos::calculatePositionVertical(RAPoint<float, 3> &start, int iStart, int iEnd)
{
  RAPoint<double, 3> *point = new RAPoint<double, 3>[iEnd - iStart + 2];
  RAAngle *totalAngle = new RAAngle[iEnd - iStart + 1](RAAngle::DEGREE);
  totalAngle[0] = _servos[iStart].read();
  for (int i = iStart + 1; i <= iEnd; ++i)
  {
    totalAngle[i - iStart] = totalAngle[i - iStart - 1] + _servos[i].read();
  }

  
  return NULL;  
}

RAPoint<double, 3>* RAServos::calculatePositionHorizontal(RAPoint<float, 3> &start, int iStart, int iEnd)
{
  
}

RAPoint<double, 3>* RAServos::calculatePositionHand(RAPoint<float, 3> &start, int iStart, int iEnd)
{
  
}

RAAngle* RAServos::CCD()
{
  return NULL;
}
  
RAServos::RAServos()
{
  _nServos = 6;
  _servos = new RAServo[_nServos];
  _servosDigital = new int[_nServos] {3, 5, 6, 9, 10, 11};
}


RAServos::RAServos(RAPoint<double, 3>& start)
{
  _nServos = 6;
  _servos = new RAServo[_nServos];
  _servosDigital = new int[_nServos] {3, 5, 6, 9, 10, 11};

  _start = start;
}

RAServos::RAServos(int nServos, int *servosDigital)
{
  _nServos = nServos;
  _servos = new RAServo[_nServos];
  _servosDigital = new int[_nServos];
  for (int i = 0; i < _nServos; ++i)
  {
    _servosDigital[i] = servosDigital[i];
  }
}

RAServos::RAServos(int nServos, int *servosDigital, RAPoint<double, 3>& start)
{
  _nServos = nServos;
  _servos = new RAServo[_nServos];
  _servosDigital = new int[_nServos];
  for (int i = 0; i < _nServos; ++i)
  {
    _servosDigital[i] = servosDigital[i];
  }

  _start = start;  
}

RAServos::~RAServos()
{
  delete []_servos;
  delete []_servosDigital;
}

uint8_t RAServos::attach()
{
  for (int i = 0; i < _nServos; ++i)
  {
    _servos[i].attach(_servosDigital[i]);
  }  
}

void RAServos::detach()
{
  for (int i = 0; i < _nServos; ++i)
  {
    _servos[i].detach();
  }
}

RAServo& RAServos::operator [] (int index)
{
  return _servos[index];
}

void RAServos::move(RAPoint<double, 3> &point)
{
  
}
*/
