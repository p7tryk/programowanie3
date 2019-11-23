#include <cmath>

class angle
{
 private:
  double value;
  void sanetize();
 public:
  angle(double input);
  angle(const angle  & anglep);
  ~angle();
  void setAngle(double input);
  double getAngle();
  void print();
  
  void addAngle(double input);
  void subAngle(double input);

  void addAngle(const angle * inputp);
  void subAngle(const angle * inputp);

  void addAngle(angle obj);
};
angle::angle(double input = 0)
{
  value = input;
  sanetize();
  printf("konstruktor %p\n",this);
}
angle::angle(const angle  & anglep)
{
  printf("konstruktor kopiujacy %p\n",this);
  this->value =  anglep.value;
}
angle::~angle()
{
  printf("destruktor %p\n", this);
}
double angle::getAngle()
{
  return value;
}
void angle::print()
{
  printf("%.2lf\n", getAngle());
}
void angle::setAngle(double input)
{
  value = input;
  sanetize();
}
void angle::addAngle(double input)
{
  value += input;
  sanetize();
}
void angle::addAngle(const angle * inputp)
{
  value += inputp->value;
  sanetize();
}
void angle::addAngle(angle obj) //test kopiujacego konstruktora
{
  value += obj.value;
  sanetize();
}
void angle::subAngle(double input)
{
  value -= input;
  sanetize();
}
void angle::subAngle(const angle * inputp)
{
  value -= inputp->value;
  sanetize();
}

void angle::sanetize()
{
  value =  fmod( value, 360.);
  
  if(value<0)
    value = 360-(-value);  
}

angle addAngles(const angle & a1,const angle & a2)
{
  angle output(a1);
  output.addAngle(&a2);
  return output;
}
angle subAngles(const angle & a1,const angle & a2)
{
  angle output(a1);
  output.subAngle(&a2);
  return output;
}
