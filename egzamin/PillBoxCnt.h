#include "PillBox.h"
#pragma once

class PillBoxCnt : public PillBox{
 protected:
  int m_pillsTaken = 0;
 public:
  
 PillBoxCnt() : PillBox(){};
 PillBoxCnt(int num) : PillBox(num){};
  PillBoxCnt(const PillBoxCnt& box);
  void take(int num);
  int getTotal();
  
};
/*
PillBoxCnt::PillBoxCnt()
{
  m_pillsTaken=0; 
}
PillBoxCnt::PillBoxCnt(int num)
{
  m_pillsTaken=0;
}*/

PillBoxCnt::PillBoxCnt(const PillBoxCnt& box)
{
  m_pillsNum=box.m_pillsNum;
  m_pillsTaken = box.m_pillsTaken;
}
void PillBoxCnt::take(int num)
{
  if(m_pillsNum==0)
    throw takefromzero(num);
  if(num<=m_pillsNum)
    {
      m_pillsNum-=num;
      m_pillsTaken+=num;
    }
  else
    throw invalidtake(num,m_pillsNum);                        //odkomentuj
}
int PillBoxCnt::getTotal()
{
  return m_pillsTaken;
}
