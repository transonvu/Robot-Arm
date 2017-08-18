#ifndef RAMATRIX_H
#define RAMATRIX_H

#include "RAArray.h"

template<class T>
class RAMatrix
{
private:
  RAArray<RAArray<T>> _elements;
public:
  RAMatrix();
  RAMatrix(int rows, int cols);
  RAMatrix(RAArray<RAArray<T>> &elements);
  RAMatrix(RAMatrix<T> &elements);
  ~RAMatrix();

  RAMatrix operator + (RAMatrix<T> &matrix);
  RAMatrix operator - (RAMatrix<T> &matrix);
  RAMatrix operator * (double factor);
  RAMatrix operator * (RAMatrix<T> &matrix);
  RAMatrix operator / (double divisor);

  RAMatrix& operator += (RAMatrix<T> &matrix);
  RAMatrix& operator -= (RAMatrix<T> &matrix);
  RAMatrix& operator *= (double factor);
  RAMatrix& operator /= (double divisor);

  RAMatrix& operator = (RAArray<RAArray<T>> &elements);
  RAMatrix& operator = (RAMatrix<T> &matrix);

  RAMatrix transpose();
  RAArray<T>& operator [] (int index);

  void resize(int rows, int cols);
  int rows();
  int cols();
};

template<class T>
RAMatrix<T>::RAMatrix()
{
  _elements.resize(4);
  for (int i = 0; i < 4; ++i)
  {
    _elements[i].resize(4);
  }
}

template<class T>
RAMatrix<T>::RAMatrix(int rows, int cols)
{
  _elements.resize(rows);
  for (int i = 0; i < rows; ++i)
  {
    _elements[i].resize(cols);
  }  
}

template<class T>
RAMatrix<T>::RAMatrix(RAArray<RAArray<T>> &elements)
{
  _elements = elements;  
}

template<class T>
RAMatrix<T>::RAMatrix(RAMatrix<T> &matrix)
{
  _elements = matrix._elements;    
}

template<class T>
RAMatrix<T>::~RAMatrix()
{
  
}

template<class T>
RAMatrix<T> RAMatrix<T>::operator + (RAMatrix<T> &matrix)
{
  int nRows = rows();
  int nCols = cols();
  if (!(nRows == matrix.rows() && nCols == matrix.cols()))
  {
    throw 0;
  }
  RAMatrix<T> t(nRows, nCols);
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nCols; ++j)
    {
      t._elements[i][j] = _elements[i][j] + matrix._elements[i][j];
    }
  }
  return t;
}

template<class T>
RAMatrix<T> RAMatrix<T>::operator - (RAMatrix<T> &matrix)
{
  int nRows = rows();
  int nCols = cols();
  if (!(nRows == matrix.rows() && nCols == matrix.cols()))
  {
    throw 0;
  }
  RAMatrix<T> t(nRows, nCols);
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nCols; ++j)
    {
      t._elements[i][j] = _elements[i][j] - matrix._elements[i][j];
    }
  }
  return t;  
}

template<class T>
RAMatrix<T> RAMatrix<T>::operator * (double factor)
{
  int nRows = rows();
  int nCols = cols();
  RAMatrix<T> t(nRows, nCols);
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nCols; ++j)
    {
      t._elements[i][j] = _elements[i][j] * factor;
    }
  }
  return t;
}

template<class T>
RAMatrix<T> RAMatrix<T>::operator * (RAMatrix &matrix)
{
  int nRows = rows();
  int nCols1 = cols();
  if (nCols1 != matrix.rows())
  {
    throw 0;
  }
  int nCols2 = matrix.cols();
  
  RAMatrix<T> t(nRows, nCols2);
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nCols2; ++j)
    {
      for (int k = 0; k < nCols1; ++k)
      {
        t._elements[i][j] += _elements[i][k] * matrix._elements[k][j];        
      }
    }
  }
  return t;  
}

template<class T>
RAMatrix<T> RAMatrix<T>::operator / (double divisor)
{
  int nRows = rows();
  int nCols = cols();
  RAMatrix<T> t(nRows, nCols);
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nCols; ++j)
    {
      t._elements[i][j] = _elements[i][j] / divisor;
    }
  }
  return t;  
}

template<class T>
RAMatrix<T>& RAMatrix<T>::operator += (RAMatrix<T> &matrix)
{
  int nRows = rows();
  int nCols = cols();
  if (!(nRows == matrix.rows() && nCols == matrix.cols()))
  {
    throw 0;
  }
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nCols; ++j)
    {
      _elements[i][j] += matrix._elements[i][j];
    }
  }
  return (*this);    
}

template<class T>
RAMatrix<T>& RAMatrix<T>::operator -= (RAMatrix<T> &matrix)
{
  int nRows = rows();
  int nCols = cols();
  if (!(nRows == matrix.rows() && nCols == matrix.cols()))
  {
    throw 0;
  }
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      _elements[i][j] -= matrix._elements[i][j];
    }
  }
  return (*this);
}

template<class T>
RAMatrix<T>& RAMatrix<T>::operator *= (double factor)
{
  int nRows = rows();
  int nCols = cols();
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nCols; ++j)
    {
      _elements[i][j] *= factor;
    }
  }
  return (*this);  
}

template<class T>
RAMatrix<T>& RAMatrix<T>::operator /= (double divisor)
{
  int nRows = rows();
  int nCols = cols();
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nCols; ++j)
    {
      _elements[i][j] /= divisor;
    }
  }
  return (*this);    
}

template<class T>
RAMatrix<T>& RAMatrix<T>::operator = (RAArray<RAArray<T>> &elements)
{
  _elements = elements;
  return (*this);
}

template<class T>
RAMatrix<T>& RAMatrix<T>::operator = (RAMatrix<T> &matrix)
{
  _elements = matrix._elements;
  return (*this);
}

template<class T>
RAMatrix<T> RAMatrix<T>::transpose()
{
  int nRows = rows();
  int nCols = cols();
  RAMatrix<T> t(nCols, nRows);
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nCols; ++j)
    {
      t._elements[j][i] = _elements[i][j];    
    }
  }
  return t;
}

template<class T>
RAArray<T>& RAMatrix<T>::operator [] (int index)
{
  return _elements[index];
}

template<class T>
void RAMatrix<T>::resize(int rows, int cols)
{
  _elements.resize(rows);
  for (int i = 0; i < rows; ++i)
  {
    _elements[i].resize(cols);
  }  
}

template<class T>
int RAMatrix<T>::rows()
{
  return _elements.size();
}

template<class T>
int RAMatrix<T>::cols()
{
  if (rows() == 0)
  {
    return 0;
  }
  return _elements[0].size();
}

#endif // RAMATRIX_H

