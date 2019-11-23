#include "animals.h"
class bird : public animal{
 public:
  bird();
  ~bird();
  void fly();
  void makeSound();
};
bird::bird() : animal(2)
{
  printf("ptak %p urodzil sie\n",this);
}
bird::~bird()
{
  printf("ptak %p umarl\n",this);
}
void bird::fly()
{
  printf("fruuuu fruuuu\n"); 
}
void bird::makeSound()
{
  printf("kraaa kraaa\n");
}
