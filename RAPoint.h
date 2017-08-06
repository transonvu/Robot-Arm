#pragma once

template<class T, int nDimensions>
class RAPoint
{
private:
  T _elements[nDimensions];
public:
  RAPoint();
  RAPoint(const T *elements);
  RAPoint(const RAPoint<T, nDimensions> &p);
  ~RAPoint();
  const RAPoint operator + (const RAPoint<T, nDimensions> &p);
  const RAPoint operator - (const RAPoint<T, nDimensions> &p);
  const RAPoint& operator += (const RAPoint<T, nDimensions> &p);
  const RAPoint& operator -= (const RAPoint<T, nDimensions> &p);
  const RAPoint& operator = (const RAPoint<T, nDimensions> &p);
  const RAPoint& operator = (const T *elements);
  const T& operator [] (int index);
};

template<class T, int nDimensions>
RAPoint<T, nDimensions>::RAPoint()
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = 0;
  }
}

template<class T, int nDimensions>
RAPoint<T, nDimensions>::RAPoint(const T *elements)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = elements[i];
  }  
}

template<class T, int nDimensions>
RAPoint<T, nDimensions>::RAPoint(const RAPoint<T, nDimensions> &p)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = p._elements[i];
  }
}

template<class T, int nDimensions>
RAPoint<T, nDimensions>::~RAPoint()
{

}

template<class T, int nDimensions>
const RAPoint<T, nDimensions> RAPoint<T, nDimensions>::operator + (const RAPoint<T, nDimensions> &p)
{
  RAPoint<T, nDimensions> t;
  for (int i = 0; i < nDimensions; ++i)
  {
    t._elements[i] = _elements[i] + p._elements[i];
  }
  return t;
}

template<class T, int nDimensions>
const  RAPoint<T, nDimensions> RAPoint<T, nDimensions>::operator - (const RAPoint<T, nDimensions> &p)
{
  RAPoint<T, nDimensions> t;
  for (int i = 0; i < nDimensions; ++i)
  {
    t._elements[i] = _elements[i] - p._elements[i];
  }
  return t;
}

template<class T, int nDimensions>
const RAPoint<T, nDimensions>& RAPoint<T, nDimensions>::operator += (const RAPoint<T, nDimensions> &p)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] += p._elements[i];
  }
  return *this;
}

template<class T, int nDimensions>
const RAPoint<T, nDimensions>& RAPoint<T, nDimensions>::operator -= (const RAPoint<T, nDimensions> &p)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] -= p._elements[i];
  }
  return *this;
}

template<class T, int nDimensions>
const RAPoint<T, nDimensions>& RAPoint<T, nDimensions>::operator = (const RAPoint<T, nDimensions> &p)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = p._elements[i];
  }
  return *this;
}

template<class T, int nDimensions>
const RAPoint<T, nDimensions>& RAPoint<T, nDimensions>::operator = (const T *elements)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = elements[i];
  }
  return *this;  
}

template<class T, int nDimensions>
const T& RAPoint<T, nDimensions>::operator [] (int index)
{
  return _elements[index];
}

