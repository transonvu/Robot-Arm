#include "RAArm.h"

const int defaultNServos = 6;
const int defaultServosDigital[defaultNServos] = {3, 5, 6, 9, 10, 11};

RAArm::RAArm()
{
  _nServos = defaultNServos;
  _servos = new RAServo[_nServos];
  _servosDigital = new int[_nServos];
  for (int i = 0; i < _nServos; ++i)
  {
    _servosDigital[i] = defaultServosDigital[i];
  }
}

RAArm::RAArm(int nServos, int *servosDigital)
{
  _nServos = nServos;
  _servos = new RAServo[_nServos];
  _servosDigital = new int[_nServos];
  for (int i = 0; i < _nServos; ++i)
  {
    _servosDigital[i] = servosDigital[i];
  }
}

RAArm::~RAArm()
{
  delete []_servos;
  delete []_servosDigital;
}

uint8_t RAArm::attach()
{
  for (int i = 0; i < _nServos; ++i)
  {
    _servos[i].attach(_servosDigital[i]);
  }  
}

void RAArm::detach()
{
  for (int i = 0; i < _nServos; ++i)
  {
    _servos[i].detach();
  }    
}

const RAServo& RAArm::operator [] (int index)
{
  return _servos[index];
}

void RAArm::calculatePositionMove()
{
  
}

