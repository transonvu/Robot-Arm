#ifndef RADENAVITHARTENBERG_H
#define RADENAVITHARTENBERG_H

#include <Arduino.h>
#include "RAMatrix.h"
#include "RAAngle.h"

class RADenavitHartenberg
{
public:
  static RAMatrix<double> calculateDH(const RAAngle &theta, double d, double a, const RAAngle &alpha);
};

#endif // RADENAVITHARTENBERG_H
