#pragma once

template<class T, int nDimensions>
class RACoordinate
{
private:
  T _elements[nDimensions];
public:
  RACoordinate();
  RACoordinate(const T *elements);
  RACoordinate(const RACoordinate<T, nDimensions> &p);
  ~RACoordinate();
  const RACoordinate operator + (const RACoordinate<T, nDimensions> &p);
  const RACoordinate operator - (const RACoordinate<T, nDimensions> &p);
  const RACoordinate& operator += (const RACoordinate<T, nDimensions> &p);
  const RACoordinate& operator -= (const RACoordinate<T, nDimensions> &p);
  const RACoordinate& operator = (const RACoordinate<T, nDimensions> &p);
  const RACoordinate& operator = (const T *elements);
  const T& operator [] (int index);
};

template<class T, int nDimensions>
RACoordinate<T, nDimensions>::RACoordinate()
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = 0;
  }
}

template<class T, int nDimensions>
RACoordinate<T, nDimensions>::RACoordinate(const T *elements)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = elements[i];
  }  
}

template<class T, int nDimensions>
RACoordinate<T, nDimensions>::RACoordinate(const RACoordinate<T, nDimensions> &p)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = p._elements[i];
  }
}

template<class T, int nDimensions>
RACoordinate<T, nDimensions>::~RACoordinate()
{

}

template<class T, int nDimensions>
const RACoordinate<T, nDimensions> RACoordinate<T, nDimensions>::operator + (const RACoordinate<T, nDimensions> &p)
{
  RACoordinate<T, nDimensions> t;
  for (int i = 0; i < nDimensions; ++i)
  {
    t._elements[i] = _elements[i] + p._elements[i];
  }
  return t;
}

template<class T, int nDimensions>
const  RACoordinate<T, nDimensions> RACoordinate<T, nDimensions>::operator - (const RACoordinate<T, nDimensions> &p)
{
  RACoordinate<T, nDimensions> t;
  for (int i = 0; i < nDimensions; ++i)
  {
    t._elements[i] = _elements[i] - p._elements[i];
  }
  return t;
}

template<class T, int nDimensions>
const RACoordinate<T, nDimensions>& RACoordinate<T, nDimensions>::operator += (const RACoordinate<T, nDimensions> &p)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] += p._elements[i];
  }
  return *this;
}

template<class T, int nDimensions>
const RACoordinate<T, nDimensions>& RACoordinate<T, nDimensions>::operator -= (const RACoordinate<T, nDimensions> &p)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] -= p._elements[i];
  }
  return *this;
}

template<class T, int nDimensions>
const RACoordinate<T, nDimensions>& RACoordinate<T, nDimensions>::operator = (const RACoordinate<T, nDimensions> &p)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = p._elements[i];
  }
  return *this;
}

template<class T, int nDimensions>
const RACoordinate<T, nDimensions>& RACoordinate<T, nDimensions>::operator = (const T *elements)
{
  for (int i = 0; i < nDimensions; ++i)
  {
    _elements[i] = elements[i];
  }
  return *this;  
}

template<class T, int nDimensions>
const T& RACoordinate<T, nDimensions>::operator [] (int index)
{
  return _elements[index];
}

