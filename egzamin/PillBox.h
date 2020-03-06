#pragma once
class invalidtake
{
 protected:
  int m_taken;
  int m_exists;
 public:
  invalidtake(int taken,int exists)
    {
      m_taken=taken;
      m_exists=exists;
    };
  void print() const
  {
    printf("invalid take\n");
    status();
  }
  void status() const
  {
      printf("%d tabletek, %d do pobrania \ndelta=%d\n",m_exists,m_taken,m_exists-m_taken);
  }
};
class takefromzero : public invalidtake
{
 public:
 takefromzero(int taken) : invalidtake(taken, 0) {};
  void print() const
  {
    printf("take from zero\n");
    status();
  }
};
class PillBox
{
 protected:
  int m_pillsNum;

 public:
  PillBox();
  PillBox(int num);
  PillBox(const PillBox& box);
  //~PillBox();

  virtual void take(int num);
  void refill(int num);
  void empty();
  int getCharge() const;
  void status();

  PillBox& operator=(const PillBox& box);
  PillBox& operator+=(PillBox& box); //nie mozna zrobic za pomoca take() bo pillboxcnt bedzie liczyl przesypywanie
  PillBox& operator-=(PillBox& box);

  //friend operatory globalne
  //  friend PillBox operator+(const PillBox& box1, const PillBox& box2);
};
//konstruktory
PillBox::PillBox()
{
  m_pillsNum=0;
}
PillBox::PillBox(int num)
{
  m_pillsNum=num;
}
PillBox::PillBox(const PillBox& box)
{
  m_pillsNum=box.m_pillsNum;
}
void PillBox::status()
{
  printf("%d\n",m_pillsNum);
}
//operatory globalne
PillBox operator+(const PillBox& box1, const PillBox& box2)
{
  PillBox temp(box1.getCharge()+box2.getCharge());
  return temp;
}
bool operator==(const PillBox& box1, const PillBox& box2)
{
  if(box1.getCharge()==box2.getCharge())
    return true;
  else
    return false;
}
bool operator>(const PillBox& box1, const PillBox& box2)
{
  if(box1.getCharge()>box2.getCharge())
    return true;
  else
    return false;
}
bool operator<(const PillBox& box1, const PillBox& box2)
{
  if(box1.getCharge()<box2.getCharge())
    return true;
  else
    return false;
}


//operatory
PillBox& PillBox::operator=(const PillBox& box)
{
  m_pillsNum=box.m_pillsNum;
}

PillBox& PillBox::operator+=(PillBox& box)
{
  m_pillsNum+=box.m_pillsNum;
  box.m_pillsNum = 0;
}
PillBox& PillBox::operator-=(PillBox& box)
{
  box.m_pillsNum+=m_pillsNum;
  m_pillsNum = 0;
}

//metody
void PillBox::take(int num)
{
  if(m_pillsNum==0)
    throw takefromzero(num);
  if(num<=m_pillsNum)
    m_pillsNum-=num;
  else
    throw invalidtake(num,m_pillsNum);                        //odkomentuj
}
void PillBox::refill(int num)
{
  m_pillsNum+=num;
}
void PillBox::empty()
{
  m_pillsNum=0;
}
int PillBox::getCharge() const
{
  return m_pillsNum;
}
