#include <stdio.h>
#include "angle.h"
#include <cmath>



int main()
{
  angle a1(30);
  angle a2(80);
  a1.print();
  a2.print();
  /*
  for(int i=0;i<2;i++)
    {
      a1.subAngle(30.);
      a1.print();
    }
  printf("a1=");
  a1.print();
  printf("a2=");
  a2.print();
  printf("a1-a2=");
  a1.subAngle(&a2);
  a1.print();
*/
  //  a1.addAngle(a2);

  angle a3 =addAngles(a1,a2);
  a3.print();
}
