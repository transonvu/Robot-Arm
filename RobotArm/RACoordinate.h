#ifndef RACOORDINATE_H
#define RACOORDINATE_H

#include "RAArray.h"

template<class T>
class RACoordinate
{
private:
  RAArray<T> _elements;
public:
  RACoordinate();
  RACoordinate(int nDimensions);
  RACoordinate(const RAArray<T> &elements);
  RACoordinate(const RACoordinate<T> &coordinate);
  ~RACoordinate();
  RACoordinate& operator = (const RAArray<T> &elements);
  RACoordinate& operator = (const RACoordinate<T> &coordinate);
  RACoordinate operator + (const RACoordinate<T> &coordinate);
  RACoordinate operator - (const RACoordinate<T> &coordinate);
  RACoordinate operator * (double factor);
  RACoordinate operator / (double divisor);
  RACoordinate& operator += (const RACoordinate<T> &coordinate);
  RACoordinate& operator -= (const RACoordinate<T> &coordinate);
  RACoordinate& operator *= (double factor);
  RACoordinate& operator /= (double divisor);

  T& operator [] (int index);

  void resize(int nDimensions);
  int size() const;
};

template<class T>
RACoordinate<T>::RACoordinate()
{
  _elements.resize(3);
}

template<class T>
RACoordinate<T>::RACoordinate(int nDimensions)
{
  _elements.resize(nDimensions);
}

template<class T>
RACoordinate<T>::RACoordinate(const RAArray<T> &elements)
{
  _elements = elements;
}

template<class T>
RACoordinate<T>::RACoordinate(const RACoordinate<T> &coordinate)
{
  _elements = coordinate._elements;
}

template<class T>
RACoordinate<T>::~RACoordinate()
{

}

template<class T>
RACoordinate<T>& RACoordinate<T>::operator = (const RAArray<T> &elements)
{
  _elements = elements;
  return *this;  
}

template<class T>
RACoordinate<T>& RACoordinate<T>::operator = (const RACoordinate<T> &coordinate)
{
  _elements = coordinate._elements;
  return *this;
}

template<class T>
RACoordinate<T> RACoordinate<T>::operator + (const RACoordinate<T> &coordinate)
{
  int nDimensions = size();
  RACoordinate<T> t(nDimensions);
  for (int i = 0; i < nDimensions; ++i)
  {
    t._elements[i] = _elements[i] + coordinate._elements[i];
  }
  return t;  
}

template<class T>
RACoordinate<T> RACoordinate<T>::operator - (const RACoordinate<T> &coordinate)
{
  int nDimensions = size();
  RACoordinate<T> t(nDimensions);
  for (int i = 0; i < nDimensions; ++i)
  {
    t._elements[i] = _elements[i] - coordinate._elements[i];
  }
  return t;  
}

template<class T>
RACoordinate<T> RACoordinate<T>::operator * (double factor)
{
  int nDimensions = size();
  RACoordinate<T> t(nDimensions);
  for (int i = 0; i < nDimensions; ++i)
  {
    t._elements[i] = _elements[i] * factor;
  }
  return t;  
}

template<class T>
RACoordinate<T> RACoordinate<T>::operator / (double divisor)
{
  int nDimensions = size();
  RACoordinate<T> t(nDimensions);
  for (int i = 0; i < nDimensions; ++i)
  {
    t._elements[i] = _elements[i] / divisor;
  }
  return t;  
}

template<class T>
RACoordinate<T>& RACoordinate<T>::operator += (const RACoordinate<T> &coordinate)
{
  int nDimensions = size();
  if (nDimensions != coordinate.size())
  {
    return 0;
  }
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] += coordinate._elements[i];
  }
  return *this;
}

template<class T>
RACoordinate<T>& RACoordinate<T>::operator -= (const RACoordinate<T> &coordinate)
{
  int nDimensions = size();
  if (nDimensions != coordinate.size())
  {
    return 0;
  }
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] -= coordinate._elements[i];
  }
  return *this;
}

template<class T>
RACoordinate<T>& RACoordinate<T>::operator *= (double factor)
{
  int nDimensions = size();
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] *= factor;
  }
  return *this;
}

template<class T>
RACoordinate<T>& RACoordinate<T>::operator /= (double divisor)
{
  int nDimensions = size();
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] /= divisor;
  }
  return *this;
}

template<class T>
T& RACoordinate<T>::operator [] (int index)
{
  return _elements[index];
}

template<class T>
void RACoordinate<T>::resize(int nDimensions)
{
  _elements.resize(nDimensions);
}

template<class T>
int RACoordinate<T>::size() const
{
  return _elements.size();
}

#endif // RACOORDINATE_H
