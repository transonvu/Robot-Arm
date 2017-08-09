#include "RAHand.h"

const int defaultHeight = 20;
const double defaultPositions[2][3] = {0.0, 0.0, 0.0};

RAHand::RAHand()
{
  _positions[0] = defaultPositions[0];
  _positions[1] = defaultPositions[1];
  _height = defaultHeight;
}

RAHand::RAHand(const RACoordinate<double, 3> *positions, int height)
{
  _positions[0] = positions[0];
  _positions[1] = positions[1];
  _height = height;
}

RAHand::~RAHand()
{
  
}

void RAHand::setHeight(const int height)
{
  _height = height;
}

int RAHand::getHeight()
{
  return _height;  
}

void RAHand::setPositions(const RACoordinate<double, 3> *positions)
{
  _positions[0] = positions[0];
  _positions[1] = positions[1];
}

const RACoordinate<double, 3>* RAHand::getPositions()
{
  return _positions;
}

const RAHand& RAHand::operator = (const RAHand &hand)
{
  _positions[0] = hand._positions[0];
  _positions[1] = hand._positions[1];
  _height = hand._height;
  return *this;
}

