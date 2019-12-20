#pragma once
#include <stdio.h>
#include <stdlib.h>

class array {
 private:
  int m_size = 0;
  double * m_data;
  
 public:
  array(int size);
  array(int size,double val);
  ~array();
  void printArray() const;
  double getAt(int pos) const;
  bool setAt(int post, double val);
  void fill(double val);
  void setSize(int newsize);
  void setSize(int newsize, double val);
  int getSize() const {return m_size;};
  double operator[](int pos);
};


array::array(int size)
{
  m_data = new double[size];
  m_size = size;
}
array::array(int size,double val)
{
  m_size=size;
  m_data = new double[size];
  fill(val);
}

array::~array()
{
  delete m_data;
  m_size = 0;
}
void array::printArray() const
{
  for(int i=0;i<m_size;i++)
    {
      printf("%.3lf ",m_data[i]);
    }
  printf("\n");
}

bool array::setAt(int pos, double val)
{
  if(pos<0|| pos>m_size)
    return 0;
  m_data[pos] = val;
}
double array::getAt(int pos) const
{
  if(pos<0|| pos>m_size)
    return 0;
  return m_data[pos];
}
void array::fill(double val)
{
  for(int i=0;i<m_size;i++)
    {
      m_data[i] = val;
    }
}
void array::setSize(int newsize)
{
  if(m_size==newsize)
    return;
  double * ptr = new double[newsize];
  for(int i = 0; i<newsize&&newsize<m_size;i++)
    {
      ptr[i] = m_data[i];
    }
  delete[] m_data;
  m_data=ptr;
  m_size=newsize;
}
void array::setSize(int newsize, double val)
{
  int oldsize = m_size;
  setSize(newsize);
  if(oldsize>=m_size)
    return;
  for(int i=oldsize;i<m_size;i++)
    m_data[i] = val;
}
double array::operator[](int pos)
{
  if(pos<0|| pos>m_size)
    return 0;
  return m_data[pos];
}
