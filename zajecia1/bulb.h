class bulb
{
public:
  bulb();
  bulb(bool st, int br);  
  ~bulb();
  void turnon();
  void turnoff();
  int checkstatus();
  void changebrightness(int newBrightness);
  void printstatus();
  void decBrightness(int in=10);
  void incBrightness(int in=10);
  
private:
  void checkBrightness();
  bool state;
  int power;
  int brightness;
};
bulb::bulb()
{
  power=60;
  state=false;
  brightness=100;
}
bulb::bulb(bool st = false,int br=100)
{
  power=60;
  state=st;
  brightness=br;
  checkBrightness();
}
bulb::~bulb()
{
  printf("destruktor\n");
}
void bulb::turnon()
{
  state = 1;
}
void bulb::turnoff()
{
  state = 0;
}
int bulb::checkstatus()
{
  return state*brightness;
}
void bulb::changebrightness(int newBrightness)
{  
  brightness = newBrightness;
  checkBrightness();
}
void bulb::printstatus()
{
  printf("status = %s %d\n",checkstatus() ? "on " : "off" , checkstatus());
}
void bulb::checkBrightness()
{
  if(brightness>100)
    brightness=100;
  if(brightness<0)
    brightness=0;
}

void bulb::decBrightness(int in)
{
  brightness -= in;
  checkBrightness();
}

void bulb::incBrightness(int in)
{
  brightness += in;
  checkBrightness();
}


  

