#include "RAServos.h"

bool RAServos::isNearest(const RAPoint<double> &end, const RAPoint<double> &object)
{
  if (end.distance(object) < 0.1)
  {
    return true;
  }
  return false;
}

RAArray<RAPoint<double>> RAServos::calculatepositions()
{
  RAArray<RAPoint<double>> positions(6);
  RAArray<int> t(4);
  RAArray<RAMatrix<double>> A(5);
  RAMatrix<double> matrix;

  for (int i = 0; i < 4; ++i)
  {
    t[i] = _servos[i].read();
  }

  for (int i = 0; i < 3; ++i)
  {
    positions[0][i] = 0;
  }

  A[0] = RADenavitHartenberg::calculateDH(RAAngle(-90, RAAngle::RADIAN), 6.5, 2.5, RAAngle(0, RAAngle::RADIAN));
  A[1] = RADenavitHartenberg::calculateDH(RAAngle(90 + t[0], RAAngle::RADIAN), 2, 3, RAAngle(-90, RAAngle::RADIAN));
  A[2] = RADenavitHartenberg::calculateDH(RAAngle(270 - t[1], RAAngle::RADIAN), 0, 10.5, RAAngle(0, RAAngle::RADIAN));
  A[3] = RADenavitHartenberg::calculateDH(RAAngle(t[2], RAAngle::RADIAN), 0, 9.7, RAAngle(0, RAAngle::RADIAN));
  A[4] = RADenavitHartenberg::calculateDH(RAAngle(10 + t[3], RAAngle::RADIAN), 0, 11, RAAngle(0, RAAngle::RADIAN));

  matrix = A[0];
  positions[1][0] = matrix[0][3];
  positions[1][1] = matrix[1][3];
  positions[1][2] = matrix[2][3];
  for (int i = 1; i < 5; ++i)
  {
    matrix = matrix * A[i];
    positions[i + 1][0] = matrix[0][3];
    positions[i + 1][1] = matrix[1][3];
    positions[i + 1][2] = matrix[2][3];    
  }

  for (int i = 0; i < 6; ++i)
  {
    Serial.print(positions[i][0]);
    Serial.print(", ");
    Serial.print(positions[i][1]);
    Serial.print(", ");
    Serial.println(positions[i][2]);
  }
  
  return positions;
}

RAArray<RAAngle> RAServos::CCD(const RAPoint<double> &object)
{
  RAArray<RAPoint<double>> positions = calculatepositions();
  RAArray<RAAngle> angleServos(4);

  while (isNearest(positions[5], object))
  {
    
  }
  return NULL;
}
  
RAServos::RAServos()
{
  _nServos = 6;
  _servos = new RAServo[_nServos];
  _servosDigital = new int[_nServos] {8, 9, 10, 11, 12, 13};
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

void RAServos::move(const RAPoint<double> &object)
{
  
}
