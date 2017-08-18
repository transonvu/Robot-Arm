#ifndef RASERVOS_H
#define RASERVOS_H

#include "RAServo.h"
#include "RAVector.h"
#include "RAPoint.h"
#include "RAAngle.h"
#include "RAMatrix.h"
#include "RADenavitHartenberg.h"

class RAServos
{
private:
  RAServo *_servos;
  int *_servosDigital;
  int _nServos;
  RAPoint<double> _start;

  bool isNearest(const RAPoint<double> &end, const RAPoint<double> &object);
  RAArray<RAPoint<double>> calculatePosition();
  RAArray<RAAngle> CCD(const RAPoint<double> &object);
  
public:
  RAServos();
  RAServos(int nServos, int *servosDigital);
  ~RAServos();
  uint8_t attach();
  void detach();
  RAServo& operator [] (int index);
  void move(const RAPoint<double> &object);
};

#endif // RASERVOS_H
