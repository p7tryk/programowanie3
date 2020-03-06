#pragma once
#define DEFAULTCAPACITY 4000

class battery {
 protected:
  int m_amount; //in mAh
  int m_percent;
  int m_capacity = DEFAULTCAPACITY ;

 public:
  battery();
  battery(int input);
  battery(int input, int capacity);
  ~battery();
  int chargeup(int input);
  virtual bool drain(int input);
  int getCharge();
  void status();
  virtual void update();

  battery& operator*(const battery& box);
  battery& operator+=(battery& box); //nie mozna zrobic za pomoca take() bo pillboxcnt bedzie liczyl przesypywanie
  battery& operator-=(battery& box);

};
void battery::update()
{
  m_percent=(double)m_amount/(double)m_capacity*100.0;
}
battery::battery()
{
  m_amount=0;
  m_percent=0;
}
battery::battery(int input)
{
  m_amount=input;
  update();
}
battery::battery(int input, int capacity)
{
  m_amount=input;
  m_capacity=capacity;
  update();
}
battery::~battery()
{

}
int battery::chargeup(int input)
{
  if(input<=0)
    throw;
  int temp=0;
  m_amount+=input;
  if(m_amount>m_capacity)
    {
      temp = m_amount-m_capacity;
      m_amount-=temp;
    }
  return temp;
}
void battery::status()
{
  printf("%d of %d, %d%%\n",m_amount,m_capacity,m_percent);
  return;
}
int battery::getCharge()
{
  return m_amount;
}
bool battery::drain(int input)
{
  if(input<=0||input>m_amount)
    throw;
  
  m_amount-=input;
  update();
  return true;
}
