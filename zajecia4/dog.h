#include "animals.h"

class dog : public animal{

  
 public:
  dog();
  ~dog();
  void run();
  void makeSound();
};

dog::dog() : animal(4)
{
  printf("pies %p urodzil sie\n",this);
}
dog::~dog()
{
  printf("pies %p umarl\n",this);
}
void dog::run()
{
  printf("Tup tup\n");
}
void dog::makeSound()
{
  printf("hau hau\n");

}
