#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <new> //for bad_alloc exception

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

template<class T>
class array {
 private:
  int m_size = 0;
  T * m_data;
  T* m_dummyData = 0;;
 public:
  array(int size);
  array(int size,T val);
  array(const array& arr);
  ~array();
  void printArray() const;
  T getAt(int pos) const;
  bool setAt(int post, T val);
  void fill(T val);
  void setSize(int newsize);
  void setSize(int newsize, T val);
  int getSize() const {return m_size;};
  T& operator[](int pos);
  //todo
  array& operator=(const array& arr);
  array& operator=(T var);
  bool operator==(const array& arr) const;
  bool operator!=(const array& arr) const;
  array operator+(const array& arr2) const;
  array operator-(const array& arr2) const;
  array& operator/(T val);

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
template<typename T>
array& array::operator/(T val)
{
  if(val==0)
    throw divbyzero_exception();
  for(int i=0;i<m_size;i++)
    m_data[i]/val;

  return *this;
}

template<typename T>
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
template<typename T>
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
template<typename T>
array::array(int size)
{
  try{
  m_data = new T[size];
  }
  catch(std::bad_alloc &ex)
    {
      throw memory_exception();
    }
  m_size = size;
}
template<typename T>
array::array(int size,T val)
{
  m_size=size;
  m_data = new(std::nothrow) T[size];
  if(!m_data)
      throw memory_exception();
  fill(val);
}
template<typename T>
array::array(const array& arr)
{
  m_size = arr.m_size;
  m_dummyData = arr.m_dummyData;
  m_data = new T[m_size = arr.m_size];
  for(int i= 0; i<m_size;i++)
    {
      m_data[i]=arr.m_data[i];
    }
  printf("copy\n");
}
template<typename T>
array::~array()
{
  delete m_data;
  m_size = 0;
}
template<typename T>
void array::printArray() const
{
  for(int i=0;i<m_size;i++)
    {
      printf("[%d]=%.3lf\n",i,m_data[i]);
    }
  printf("\n");
}
template<typename T>
bool array::setAt(int pos, T val)
{
  if(pos<0|| pos>m_size)
    return 0;
  m_data[pos] = val;
}
template<typename T>
T array::getAt(int pos) const
{
  if(pos<0|| pos>m_size)
    return 0;
  return m_data[pos];
}
template<typename T>
void array::fill(T val)
{
  for(int i=0;i<m_size;i++)
    {
      m_data[i] = val;
    }
}
template<typename T>
void array::setSize(int newsize)
{
  if(m_size==newsize)
    return;
  T * ptr = new T[newsize];
  for(int i = 0; i<newsize&&newsize<m_size;i++)
    {
      ptr[i] = m_data[i];
    }
  delete[] m_data;
  m_data=ptr;
  m_size=newsize;
}
template<typename T>
void array::setSize(int newsize, T val)
{
  int oldsize = m_size;
  setSize(newsize);
  if(oldsize>=m_size)
    return;
  for(int i=oldsize;i<m_size;i++)
    m_data[i] = val;
}
template<typename T>
T& array::operator[](int pos)
{
  if(pos>m_size)
    {
      throw index_exception(pos);
    }
  if(pos<0)
    throw negative_index_exception(pos);
  return m_data[pos];
}
template<typename T>
array& array::operator=(const array& arr)
{
  if(*this==arr)
    return *this;
  if(m_size!=arr.m_size)
    {
      delete m_data;
      m_data = new T[m_size=arr.m_size];
    }
  for(int i = 0; i<m_size;i++)
    {
      m_data[i]=arr.m_data[i];
    }
  
  
  
  return *this;
  
};
template<typename T>
array& array::operator=(T var)
{
  fill(var);
  return *this;
};
template<typename T>
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
template<typename T>
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
