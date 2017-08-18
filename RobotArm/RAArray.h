#ifndef RAARRAY_H
#define RAARRAY_H

template<class T>
class RAArray
{
private:
  int _size;
  T *_elements;

public:
  RAArray();
  RAArray(int size);
  RAArray(const RAArray<T> &array);
  ~RAArray();
  RAArray<T>& operator = (const RAArray<T> &array);
  T& operator [] (int index);

  void resize(int size);
  int size();
};

template<class T>
RAArray<T>::RAArray()
{
  _size = 0;
  _elements = NULL;
}

template<class T>
RAArray<T>::RAArray(int size)
{
  _size = size;
  _elements = new T[_size];
  memset(_elements, 0, sizeof(T) * size);  
}

template<class T>
RAArray<T>::RAArray(const RAArray<T> &array)
{
  _size = array._size;
  for (int i = 0; i < _size; ++i)
  {
    _elements[i] = array._elements[i];
  }  
}

template<class T>
RAArray<T>::~RAArray()
{
  if (_elements != NULL)
    delete []_elements;
}

template<class T>
RAArray<T>& RAArray<T>::operator = (const RAArray<T> &array)
{
  if (_size != array._size)
  {
    _size = array._size;
    if (_elements != NULL)
      delete []_elements;
    _elements = new T[_size];    
  }
  for (int i = 0; i < _size; ++i)
  {
    _elements[i] = array._elements[i];
  }
  return *this;
}

template<class T>
T& RAArray<T>::operator [] (int index)
{
  return _elements[index];
}

template<class T>
void RAArray<T>::resize(int size)
{
  _size = size;
  if (_elements != NULL)
    delete []_elements;
  _elements = new T[_size];
  memset(_elements, 0, sizeof(T) * size);  
}

template<class T>
int RAArray<T>::size()
{
  return _size;
}

#endif // RAARRAY_H
