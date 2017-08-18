#ifndef RAPOINT_H
#define RAPOINT_H

#include "RACoordinate.h"

template<class T>
class RAPoint
{
private:
  RACoordinate<T> _coordinate;
public:
  RAPoint();
  RAPoint(int nDimensions);
  RAPoint(RAArray<T> &elements);
  RAPoint(RACoordinate<T> &coordinate);
  RAPoint(RAPoint<T> &point);
  ~RAPoint();
  RAPoint& operator = (RAArray<T> &elements);
  RAPoint& operator = (RACoordinate<T> &coordinate);
  RAPoint& operator = (RAPoint<T> &point);
  T& operator [] (int index);

  T distance(RAPoint<T> &point);
  void resize(int nDimensions);
  int size();
};

template<class T>
RAPoint<T>::RAPoint()
{
  _coordinate.resize(3);
}

template<class T>
RAPoint<T>::RAPoint(int nDimensions)
{
  _coordinate.resize(nDimensions);  
}

template<class T>
RAPoint<T>::RAPoint(RAArray<T> &elements)
{
  _coordinate = elements;
}

template<class T>
RAPoint<T>::RAPoint(RACoordinate<T> &coordinate)
{
  _coordinate = coordinate;
}

template<class T>
RAPoint<T>::RAPoint(RAPoint<T> &point)
{
  _coordinate = point._coordinate;
}

template<class T>
RAPoint<T>::~RAPoint()
{

}

template<class T>
RAPoint<T>& RAPoint<T>::operator = (RAArray<T> &elements)
{
  _coordinate = elements;
  return *this;  
}

template<class T>
RAPoint<T>& RAPoint<T>::operator = (RACoordinate<T> &coordinate)
{
    _coordinate = coordinate;
}

template<class T>
RAPoint<T>& RAPoint<T>::operator = (RAPoint<T> &point)
{
  _coordinate = point._coordinate;
  return *this;
}

template<class T>
T& RAPoint<T>::operator [] (int index)
{
  return _coordinate[index];
}

template<class T>
T RAPoint<T>::distance(RAPoint<T> &point)
{
  int nDimensions = size();
  if (nDimensions != point.size())
  {
    throw 0; 
  }
  T t = 0;
  for (int i = 0; i < nDimensions; ++i)
  {
    t += (_coordinate[i] - point._coordinate[i]) * (_coordinate[i] - point._coordinate[i]);
  }
  return sqrt(t);
}

template<class T>
void RAPoint<T>::resize(int nDimensions)
{
  _coordinate.resize(nDimensions);  
}

template<class T>
int RAPoint<T>::size()
{
  return _coordinate.size();    
}

#endif // RAPOINT_H
