#define FULL 4000

class battery {
 private:
  int amount; //in mAh
  int percent;

 public:
  battery();
  battery(int input);
  ~battery();
  bool chargeup(int input);
  bool drain(int input);
  int status();
  void update();
}
void battery::update()
{
  if(amount>FULL)
    amount=FULL;
  percent=(double)amount/(double)FULL*100.0;
}
battery::battery()
{
  amount=0;
  percent=0;
}
battery::battery(int input)
{
  amount=input;
  update();
}
bool battery::chargeup(int input)
{
  
}
