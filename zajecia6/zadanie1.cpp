#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main()
{
  array list(10,9);

  list.setAt(6,5);
  list.printArray();
  list.setSize(5);
  list.printArray();
  list.setSize(10,5);
  list.setAt(0,5);
  list[15] = 10;
  list.printArray();
  double s = 0;
  
  printf("\n%lf\n",s);
  for(int i=0;i<list.getSize();i++)
    s+=list[i];
  printf("suma=%.3lf,srednia=%.3lf\n",s,s/list.getSize());
}
