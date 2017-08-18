#ifndef RASERVOS_H
#define RASERVOS_H

#include "RAPoint.h"
#include "RAAngle.h"

template<class T>
class RAVector
{
private:
  RACoordinate<T> _coordinate;
public:
  RAVector();
  RAVector(int nDimensions);
  RAVector(RAArray<T> &elements);
  RAVector(RACoordinate<T> &coordinate);
  RAVector(RAVector<T> &point);
  RAVector(RAPoint<T> &start, RAPoint<T> &end);
  ~RAVector();
  RAVector& operator = (RAArray<T> &elements);
  RAVector& operator = (RACoordinate<T> &coordinate);
  RAVector& operator = (RAVector<T> &vector);
  RAVector operator + (RAVector<T> &vector);
  RAVector operator - (RAVector<T> &vector);
  RAVector operator * (T factor);
  T operator * (RAVector<T> &vector);
  RAVector operator / (T divisor);
  RAVector& operator += (RAVector<T> &vector);
  RAVector& operator -= (RAVector<T> &vector);
  RAVector& operator *= (T factor);
  RAVector& operator /= (T divisor);
  T& operator [] (int index);

  T length();
  RAAngle angle(RAVector<T> &vector);

  void resize(int nDimensions);
  int size();
};

template<class T>
RAVector<T> operator - (RAPoint<T> &start, RAPoint<T> &end)
{
  int nDimension = start.size();
  if (nDimension != end.size())
  {
    throw 0;
  }
  RAVector<T> t(nDimension);
  for (int i = 0; i < nDimensions; ++i)
  {
    t[i] = start[i] - end[i];
  }
  return t;
}


template<class T>
RAVector<T>::RAVector()
{
  _coordinate.resize(3);
}

template<class T>
RAVector<T>::RAVector(int nDimensions)
{
  _coordinate.resize(nDimensions);
}

template<class T>
RAVector<T>::RAVector(RAArray<T> &elements)
{
  _coordinate = elements;
}

template<class T>
RAVector<T>::RAVector(RACoordinate<T> &coordinate)
{
  _coordinate = coordinate;
}

template<class T>
RAVector<T>::RAVector(RAVector<T> &vector)
{
  _coordinate = vector._coordinate;
}

template<class T>
RAVector<T>::RAVector(RAPoint<T> &start, RAPoint<T> &end)
{
  int nDimension = start.size();
  if (nDimension != end.size())
  {
    throw 0;
  }
  resize(nDimension);
  for (int i = 0; i < nDimensions; ++i)
  {
    _coordinate[i] = start[i] - end[i];
  }
}

template<class T>
RAVector<T>::~RAVector()
{

}

template<class T>
RAVector<T>& RAVector<T>::operator = (RAArray<T> &elements)
{
  _coordinate = elements;
  return *this;  
}

template<class T>
RAVector<T>& RAVector<T>::operator = (RACoordinate<T> &coordinate)
{
    _coordinate = coordinate;
}

template<class T>
RAVector<T>& RAVector<T>::operator = (RAVector<T> &vector)
{
  _coordinate = vector._coordinate;
  return *this;
}

template<class T>
RAVector<T> RAVector<T>::operator + (RAVector<T> &vector)
{
  int nDimension = size();
  if (nDimension != vector.size())
  {
    throw 0;
  }
  RAVector<T> t(nDimension);
  t._coordinate = _coordinate + vector._coordinate;
  return t;
}

template<class T>
RAVector<T> RAVector<T>::operator - (RAVector<T> &vector)
{
  int nDimension = size();
  if (nDimension != vector.size())
  {
    throw 0;
  }
  RAVector<T> t(nDimension);
  t._coordinate = _coordinate - vector._coordinate;
  return t;
}

template<class T>
RAVector<T> RAVector<T>::operator * (T factor)
{
  RAVector<T> t(size());
  t._coordinate = _coordinate * factor;
  return t;
}

template<class T>
T RAVector<T>::operator * (RAVector<T> &vector)
{
  int nDimension = size();
  if (nDimension != vector.size())
  {
    throw 0;
  }
  T t = 0;
  for (int i = 0; i < nDimensions; ++i)
  {
    t += _coordinate[i] * vector._coordinate[i];
  }
  return t;  
}

template<class T>
RAVector<T> RAVector<T>::operator / (T divisor)
{
  RAVector<T> t(size());
  t._coordinate = _coordinate / divisor;
  return t;
}

template<class T>
RAVector<T>& RAVector<T>::operator += (RAVector<T> &vector)
{
  if (size() != vector.size())
  {
    throw 0;
  }
  _coordinate += vector._coordinate;
  return (*this);
}

template<class T>
RAVector<T>& RAVector<T>::operator -= (RAVector<T> &vector)
{
  if (size() != vector.size())
  {
    throw 0;
  }
  _coordinate -= vector._coordinate;
  return (*this);
}

template<class T>
RAVector<T>& RAVector<T>::operator *= (T factor)
{
  _coordinate *= factor;
  return (*this);
}

template<class T>
RAVector<T>&  RAVector<T>::operator /= (T divisor)
{
  _coordinate /= divisor;
  return (*this);
}

template<class T>
T& RAVector<T>::operator [] (int index)
{
  return _coordinate[index];
}

template<class T>
T RAVector<T>::length()
{
  T t = 0;
  for (int i = 0; i < nDimensions; ++i)
  {
    t += _coordinate[i] * _coordinate[i]; 
  }
  return sqrt(t);
}

template<class T>
RAAngle RAVector<T>::angle(RAVector<T> &vector)
{
  if (size() != vector.size())
  {
    throw 0;
  }
  return RAAngle(acos(((*this) * vector) / (length() * vector.length())), RAAngle::RADIAN);  
}

template<class T>
void RAVector<T>::resize(int nDimensions)
{
  _coordinate.resize(nDimensions);
}

template<class T>
int RAVector<T>::size()
{
  return _coordinate.size();  
}

#endif // RASERVOS_H
