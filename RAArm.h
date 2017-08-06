#pragma once
#include "RAServo.h"

class RAArm
{
private:
  int _nServos;
  RAServo *_servos;
  int *_servosDigital;
public:
  RAArm();
  RAArm(int nServos, int *servosDigital);
  ~RAArm();
  const RAServo& operator [] (int index);
};

