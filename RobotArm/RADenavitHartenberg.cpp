#include "RADenavitHartenberg.h"

static RAMatrix<double> RADenavitHartenberg::calculateDH(const RAAngle &theta, double d, double a, const RAAngle &alpha)
{
  RAMatrix<double> t(4, 4);
  double cTheta = cos(theta.radian());
  double sTheta = sin(theta.radian());
  double cAlpha = cos(alpha.radian());
  double sAlpha = sin(alpha.radian());

  t[0][0] = cTheta;
  t[0][1] = -sTheta * cAlpha;
  t[0][2] = sTheta * sAlpha;
  t[0][3] = a * cTheta;
  
  t[1][0] = sTheta;
  t[1][1] = cTheta * cAlpha;
  t[1][2] = -cTheta * sAlpha;
  t[1][3] = a * sTheta;
  
  t[2][0] = 0;
  t[2][1] = sAlpha;
  t[2][2] = cAlpha;
  t[2][3] = d;
  
  t[3][0] = 0;
  t[3][1] = 0;
  t[3][2] = 0;
  t[3][3] = 1;

  return t;
}

