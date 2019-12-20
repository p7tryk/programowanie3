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

  bool operator==(const vector2D& vec);
  bool operator!=(const vector2D& vec);
  bool operator<(const vector2D& vec);
  bool operator>(const vector2D& vec);
  vector2D& operator=(const vector2D& vec);
  vector2D operator+(const vector2D& vec);
};


vector2D::vector2D(double x, double y)
{
  m_x =x;
  m_y=y;
}
vector2D::~vector2D()
{
}
vector2D::vector2D(const vector2D &vec)
{
  m_x=vec.m_x;
  m_y=vec.m_y;
}
void vector2D::print() const
{
  printf("%.2lf,%.2lf\n",m_x,m_y);
}
double vector2D::length() const
{
  return sqrt(m_x*m_y);
}
bool vector2D::operator==(const vector2D& vec)
{
  return m_x == vec.m_x && m_y == vec.m_y;
}
bool vector2D::operator!=(const vector2D& vec)
{
  return !(m_x == vec.m_x && m_y == vec.m_y);
}
bool vector2D::operator<(const vector2D& vec)
{
  return m_x < vec.m_x || m_y < vec.m_y;
}
bool vector2D::operator>(const vector2D& vec)
{
  return m_x > vec.m_x || m_y > vec.m_y;
}
vector2D& vector2D::operator=(const vector2D& vec)
{
  if(&vec==this)
    return *this;

  m_x = vec.m_x;
  m_y = vec.m_y;
  return *this;
}
  vector2D vector2D::operator+(const vector2D& vec)
  {
    vector2D temp(m_x+vec.m_x,m_y+vec.m_y);
    return temp;
  }
