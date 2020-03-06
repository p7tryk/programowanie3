#include "battery.h"
#define DEFAULTTHRESHOLD 20
class protectedBattery : public battery
{
protected:
  int m_threshold = DEFAULTTHRESHOLD;
  
public:
  protectedBattery() : battery() {};
  protectedBattery(int input) : battery(input) {};
  protectedBattery(int input, int capacity) : battery(input,capacity) {};
  protectedBattery(int input, int capacity,int threshold) : battery(input,capacity) {m_threshold=threshold;};
  void update();
  bool drain(int input);
};

void protectedBattery::update()
{
  if(m_threshold<0)
    m_threshold=0;
  battery::update();
}

bool protectedBattery::drain(int input)
{
  if(input<=0||input>m_amount-m_threshold*m_capacity/100)
    return false;
  m_amount-=input;
  update();
  return true;
}
