#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class vector2D {
 private:
  double m_x;
  double m_y;
 public:
  vector2D(double x=0, double y=0);
  ~vector2D();
  vector2D(const vector2D &vec);
  double getY(){return m_y;};
  double getX(){return m_x;};
  double length() const;
  void print() const;

  bool operator==(const vector2D& vec) const;
  bool operator!=(const vector2D& vec) const;
  bool operator<(const vector2D& vec) const;
  bool operator>(const vector2D& vec) const;
  vector2D& operator=(const vector2D& vec);
  vector2D operator+(const vector2D& vec) const;
  vector2D operator-(const vector2D& vec) const;
  vector2D operator*(double val) const;
  double operator*(const vector2D& vec) const;
  vector2D operator/(double val) const;
  vector2D operator-() const;
  vector2D& operator*=(double val);
  vector2D& operator/=(double val);
  vector2D& operator++(); //prefix
  vector2D operator++(int); //postifx
  vector2D& operator--(); //prefix
  vector2D operator--(int); //postifx
};


vector2D::vector2D(double x, double y)
{
  m_x=x;
  m_y=y;
  printf("konstruktor %p\n",this);
}
vector2D::~vector2D()
{
  printf("destruktor %p\n",this);
}
vector2D::vector2D(const vector2D &vec)
{
  m_x=vec.m_x;
  m_y=vec.m_y;
  printf("konstruktor kopiujacy %p\n",this);
}
void vector2D::print() const
{
  printf("%.2lf,%.2lf\n",m_x,m_y);
}
double vector2D::length() const
{
  return sqrt(m_x*m_y);
}
bool vector2D::operator==(const vector2D& vec) const
{
  return m_x == vec.m_x && m_y == vec.m_y;
}
bool vector2D::operator!=(const vector2D& vec) const
{
  return !(m_x == vec.m_x && m_y == vec.m_y);
}
bool vector2D::operator<(const vector2D& vec) const
{
  return m_x < vec.m_x || m_y < vec.m_y;
}
bool vector2D::operator>(const vector2D& vec) const
{
  return m_x > vec.m_x || m_y > vec.m_y;
}
vector2D& vector2D::operator=(const vector2D& vec)
{
  printf("operator=%p\n",this);
  if(&vec==this)
    return *this;

  m_x = vec.m_x;
  m_y = vec.m_y;
  return *this;
}
  vector2D vector2D::operator+(const vector2D& vec) const
  {
    printf("operator+%p\n",this);
    vector2D temp(m_x+vec.m_x,m_y+vec.m_y);
    return temp;
  }
vector2D vector2D::operator-(const vector2D& vec) const
  {
    printf("operator-%p\n",this);
    vector2D temp(m_x-vec.m_x,m_y-vec.m_y);
    return temp;
  }
vector2D vector2D::operator*(double val) const
{
  printf("mnozenie przez skalar %p\n",this);
  vector2D temp(m_x*val,m_y*val);
  return temp;
}
double vector2D::operator*(const vector2D& vec) const
{
  printf("iloczyn skalarny %p\n",this);
  return vec.m_x*m_x+vec.m_y*m_y;
}
vector2D vector2D::operator/(double val) const
{
  printf("dzielenie przez skalar %p\n",this);
  vector2D temp(m_x/val,m_y/val);
  return temp;
}
vector2D vector2D::operator-() const
{
  printf("operator negacja %p\n",this);
  vector2D temp(-m_x,-m_y);
  return temp;
}
vector2D& vector2D::operator*=(double val)
{
  printf("operator *= %p\n",this);
  m_x*=val;
  m_y*=val;
}
vector2D& vector2D::operator/=(double val)
{
  printf("operator /= %p\n",this);
  m_x*=val;
  m_y*=val;
}
vector2D& vector2D::operator++()
{
  printf("++operator %p\n",this);
  m_x++;
  m_y++;
  return *this;
}
vector2D vector2D::operator++(int)
{
  printf("operator++ %p\n",this);
  vector2D temp(m_x,m_y);
  m_x++;
  m_y++;
  return temp;
}
vector2D& vector2D::operator--()
{
  printf("--operator %p\n",this);
  m_x++;
  m_y++;
  return *this;
}
vector2D vector2D::operator--(int)
{
  printf("operator-- %p\n",this);
  vector2D temp(m_x,m_y);
  m_x++;
  m_y++;
  return temp;
}
