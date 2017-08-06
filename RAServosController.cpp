#include "RAServosController.h"

const int defaultNServos = 6;
const int defaultServosDigital[defaultNServos] = {3, 5, 6, 9, 10, 11};

RAServosController::RAServosController()
{
  _nServos = defaultNServos;
  _servos = new RAServo[_nServos];
  _servosDigital = new int[_nServos];
  for (int i = 0; i < _nServos; ++i)
  {
    _servosDigital[i] = defaultServosDigital[i];
    _servos[i].attach(_servosDigital[i]);
  }
}

RAServosController::RAServosController(int nServos, int *servosDigital)
{
  _nServos = nServos;
  _servos = new RAServo[_nServos];
  _servosDigital = new int[_nServos];
  for (int i = 0; i < _nServos; ++i)
  {
    _servosDigital[i] = servosDigital[i];
    _servos[i].attach(_servosDigital[i]);
  }
}

RAServosController::~RAServosController()
{
  delete []_servos;
  delete []_servosDigital;
}

const RAServo& RAServosController::operator [] (int index)
{
  return _servos[index];
}

