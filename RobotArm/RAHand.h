#pragma once
#include <Arduino.h>
#include "RACoordinate.h"

class RAHand
{
private:
  RACoordinate<double, 3> _positions[2];
  int _height;

public:
  RAHand();
  RAHand(const RACoordinate<double, 3> *positions, int height);
  ~RAHand();
  void setHeight(const int height);
  int getHeight();
  void setPositions(const RACoordinate<double, 3> *positions);
  const RACoordinate<double, 3>* getPositions();  
  const RAHand& operator = (const RAHand &hand);
};
