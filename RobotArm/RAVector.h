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
  RAVector(const RAArray<T> &elements);
  RAVector(const RACoordinate<T> &coordinate);
  RAVector(const const RAVector<T> &vector);
  RAVector(const RAPoint<T> &start, const RAPoint<T> &end);
  ~RAVector();
  RAVector& operator = (const RAArray<T> &elements);
  RAVector& operator = (const RACoordinate<T> &coordinate);
  RAVector& operator = (const RAVector<T> &vector);
  RAVector operator + (const RAVector<T> &vector);
  RAVector operator - (const RAVector<T> &vector);
  RAVector operator * (T factor);
  T operator * (const RAVector<T> &vector);
  RAVector operator / (T divisor);
  RAVector& operator += (const RAVector<T> &vector);
  RAVector& operator -= (const RAVector<T> &vector);
  RAVector& operator *= (T factor);
  RAVector& operator /= (T divisor);
  T& operator [] (int index);

  T length();
  RAAngle angle(const RAVector<T> &vector);

  void resize(int nDimensions);
  int size() const;
};

template<class T>
RAVector<T> operator - (const RAPoint<T> &start, const RAPoint<T> &end)
{
  int nDimension = start.size();
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
RAVector<T>::RAVector(const RAArray<T> &elements)
{
  _coordinate = elements;
}

template<class T>
RAVector<T>::RAVector(const RACoordinate<T> &coordinate)
{
  _coordinate = coordinate;
}

template<class T>
RAVector<T>::RAVector(const RAVector<T> &vector)
{
  _coordinate = vector._coordinate;
}

template<class T>
RAVector<T>::RAVector(const RAPoint<T> &start, const RAPoint<T> &end)
{
  int nDimension = start.size();
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
RAVector<T>& RAVector<T>::operator = (const RAArray<T> &elements)
{
  _coordinate = elements;
  return *this;  
}

template<class T>
RAVector<T>& RAVector<T>::operator = (const RACoordinate<T> &coordinate)
{
    _coordinate = coordinate;
}

template<class T>
RAVector<T>& RAVector<T>::operator = (const RAVector<T> &vector)
{
  _coordinate = vector._coordinate;
  return *this;
}

template<class T>
RAVector<T> RAVector<T>::operator + (const RAVector<T> &vector)
{
  int nDimension = size();
  RAVector<T> t(nDimension);
  t._coordinate = _coordinate + vector._coordinate;
  return t;
}

template<class T>
RAVector<T> RAVector<T>::operator - (const RAVector<T> &vector)
{
  int nDimension = size();
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
T RAVector<T>::operator * (const RAVector<T> &vector)
{
  int nDimension = size();
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
RAVector<T>& RAVector<T>::operator += (const RAVector<T> &vector)
{
  _coordinate += vector._coordinate;
  return (*this);
}

template<class T>
RAVector<T>& RAVector<T>::operator -= (const RAVector<T> &vector)
{
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
RAAngle RAVector<T>::angle(const RAVector<T> &vector)
{
  return RAAngle(acos(((*this) * vector) / (length() * vector.length())), RAAngle::RADIAN);  
}

template<class T>
void RAVector<T>::resize(int nDimensions)
{
  _coordinate.resize(nDimensions);
}

template<class T>
int RAVector<T>::size() const
{
  return _coordinate.size();  
}

#endif // RASERVOS_H
