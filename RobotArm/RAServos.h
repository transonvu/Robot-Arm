#ifndef RASERVOS_H
#define RASERVOS_H

#include "RAServo.h"
#include "RAVector.h"
#include "RAPoint.h"
#include "RAAngle.h"

/*
class RAServos
{
private:
  RAServo *_servos;
  int *_servosDigital;
  int _nServos;
  RAPoint<double, 3> _start;

  bool isNearest(RAPoint<float, 3> &end, RAPoint<float, 3> &object);
  RAPoint<double, 3>* calculatePositionVertical(RAPoint<float, 3> &start, int iStart, int iEnd);
  RAPoint<double, 3>* calculatePositionHorizontal(RAPoint<float, 3> &start, int iStart, int iEnd);
  RAPoint<double, 3>* calculatePositionHand(RAPoint<float, 3> &start, int iStart, int iEnd);
  RAAngle *CCD();
  
public:
  RAServos();
  RAServos(int nServos, int *servosDigital);
  ~RAServos();
  uint8_t attach();
  void detach();
  RAServo& operator [] (int index);
  void move(RAPoint<double, 3> &point);
};
*/
#endif // RASERVOS_H
