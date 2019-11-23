#include "animals.h"

class fish: public animal{

 public:
  fish();
  ~fish();
  void makeSound();

};
fish::fish():animal()
{
  printf("ryba %p urodzila sie\n",this);
}
fish::~fish()
{
  printf("ryba %p utopila sie\n", this);
}
void fish::makeSound()
{
  printf("bulb bulb\n");
}
