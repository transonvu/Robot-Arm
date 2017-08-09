#pragma once
#include "RAServo.h"
#include "RAHand.h"

class RAArm
{
private:
  int _nServos;
  RAServo *_servos;
  int *_servosDigital;
  RAHand _hand;
  void calculatePositionMove();
public:
  RAArm();
  RAArm(int nServos, int *servosDigital);
  ~RAArm();
  uint8_t attach();
  void detach();
  const RAServo& operator [] (int index);
  void write(RAHand &hand);
  RAHand read();
};

