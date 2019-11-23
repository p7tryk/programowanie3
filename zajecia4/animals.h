#pragma once

class animal{
 protected:
  int m_legCount;
 public:
  animal();
  animal(int count);
  ~animal();
  void eat();
  virtual void makeSound();
  void info();
  void zryj();
};
animal::animal()
{
  m_legCount = 0;
  printf("zwierze %p urodzilo sie\n", this);
}
animal::~animal()
{
  printf("zwierze %p umarlo\n",this);
}
animal::animal(int count)
{
  m_legCount = count;
  printf("zwierze %p z %d nog urodzilo sie\n",this, count);
}
void animal::eat()
{
  printf("mniam mniam\n");
}
void animal::makeSound()
{
  printf("auuuu\n");
}
void animal::info()
{
  if(m_legCount<2)
    printf("jestem zwierzeciem i mam %d nog\n",m_legCount);
  else
    printf("jestem zwierzeciem i mam %d nogi \n",m_legCount);
}
void animal::zryj()
{
  eat();
  makeSound();
}
