#pragma once
#include <stdio.h>
#include <stdlib.h>
class index_exception
{
  int m_index;
 public:
 index_exception(int index)
   : m_index(index) {};
  int getIndex() const { return m_index; };
};
class negative_index_exception : public index_exception
{
 public:
 negative_index_exception(int index) : index_exception(index) {};
};
class divbyzero_exception
{
};
class memory_exception
{
};

class array {
 private:
  int m_size = 0;
  double * m_data;
  double m_dummyData = 0;;
 public:
  array(int size);
  array(int size,double val);
  array(const array& arr);
  ~array();
  void printArray() const;
  double getAt(int pos) const;
  bool setAt(int post, double val);
  void fill(double val);
  void setSize(int newsize);
  void setSize(int newsize, double val);
  int getSize() const {return m_size;};
  double& operator[](int pos);
  //todo
  array& operator=(const array& arr);
  array& operator=(double var);
  bool operator==(const array& arr) const;
  bool operator!=(const array& arr) const;
  array operator+(const array& arr2) const;
  array operator-(const array& arr2) const;
  array& operator/(double val);

  //friend array operator+(const array& arr1, const array& arr2);
  //friend array operator-(const array& arr1, const array& arr2);
};
/*
array operator+(const array& arr1, const array& arr2)
{
  int newsize = arr1.m_size>arr2.m_size ? arr1.m_size : arr2.m_size;
  array newarray(newsize);

  for(int i=0;i<newsize;i++)
    {
      if(i>(arr1.m_size<arr2.m_size ? arr1.m_size : arr2.m_size))
	{
	  newarray.m_data[i] = (arr1.m_size>arr2.m_size ? arr1.m_data[i] : arr2.m_data[i]);
	}
      else
	{
	  newarray.m_data[i]=arr1.m_data[i]+arr2.m_data[i];
	}
    }
  return newarray;
}
*/
array& array::operator/(double val)
{
  if(val==0)
    throw divbyzero_exception();
  for(int i=0;i<m_size;i++)
    m_data[i]/val;

  return *this;
}


array array::operator+(const array& arr2) const
{
  int newsize = this->m_size>arr2.m_size ? this->m_size : arr2.m_size;
  array newarray(newsize);
  
  for(int i=0;i<newsize;i++)
    {
      if(i>(this->m_size<arr2.m_size ? this->m_size : arr2.m_size))
	{
	  newarray.m_data[i] = (this->m_size>arr2.m_size ? this->m_data[i] : arr2.m_data[i]);
	}
      else
	{
	  newarray.m_data[i]=this->m_data[i]+arr2.m_data[i];
	}
    }
  return newarray;
}
array array::operator-(const array& arr2) const
{
  int newsize = this->m_size>arr2.m_size ? this->m_size : arr2.m_size;
  array newarray(newsize);
  for(int i=0;i<newsize;i++)
    {
      if(i>(this->m_size<arr2.m_size ? this->m_size : arr2.m_size))
	{
	  newarray.m_data[i] = (this->m_size>arr2.m_size ? this->m_data[i] : arr2.m_data[i]);
	}
      else
	{
	  newarray.m_data[i]=this->m_data[i]-arr2.m_data[i];
	}
    }
  return newarray;
}

array::array(int size)
{
  if(size>100)
    throw memory_exception();
  m_data = new double[size];
  m_size = size;
}
array::array(int size,double val)
{
  if(size>100)
    throw memory_exception();
  m_size=size;
  m_data = new double[size];
  fill(val);
}
array::array(const array& arr)
{
  m_size = arr.m_size;
  m_dummyData = arr.m_dummyData;
  m_data = new double[m_size = arr.m_size];
  for(int i= 0; i<m_size;i++)
    {
      m_data[i]=arr.m_data[i];
    }
  printf("copy\n");
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
double& array::operator[](int pos)
{
  if(pos>m_size)
    {
      throw index_exception(pos);
    }
  if(pos<0)
    throw negative_index_exception(pos);
  return m_data[pos];
}

array& array::operator=(const array& arr)
{
  if(*this==arr)
    return *this;
  if(m_size!=arr.m_size)
    {
      delete m_data;
      m_data = new double[m_size=arr.m_size];
    }
  for(int i = 0; i<m_size;i++)
    {
      m_data[i]=arr.m_data[i];
    }
  
  
  
  return *this;
  
};
array& array::operator=(double var)
{
  fill(var);
  return *this;
};
bool array::operator==(const array& arr) const
{
  if(m_size!=arr.m_size)
    return false;
  else
    for(int i = 0;i<m_size;i++)
      {
	if(m_data[i]!=arr.m_data[i])
	  return false;
      }
  return true;
}
bool array::operator!=(const array& arr) const
{
  if(m_size!=arr.m_size)
    return true;
  else
    for(int i = 0;i<m_size;i++)
      {
	if(m_data[i]!=arr.m_data[i])
	  return true;
      }
  return false;
}
/*
array array::operator+(const array& arr) const
{
  
}
*/
