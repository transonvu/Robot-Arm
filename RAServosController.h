#pragma once
#include "RAServo.h"

class RAServosController
{
private:
  int _nServos;
  RAServo *_servos;
  int *_servosDigital;
public:
  RAServosController();
  RAServosController(int nServos, int *servosDigital);
  ~RAServosController();
  const RAServo& operator [] (int index);
};

