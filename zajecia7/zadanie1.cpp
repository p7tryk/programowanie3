#include <stdio.h>
#include <stdlib.h>
#include "vector.h"



int main()
{
  vector2D v1(1,3);
  vector2D v2=v1;
  v2=v2+v1;
  v1.print();
  v2.print();

  printf("%.3lf,%.3lf == %.3lf,%.3lf %s\n",v1.getX(),v1.getY(),v2.getX(),v2.getY(),v1==v2 ? "true" : "false");
  printf("%.3lf,%.3lf != %.3lf,%.3lf %s\n",v1.getX(),v1.getY(),v2.getX(),v2.getY(),v1!=v2 ? "true" : "false");
  printf("%.3lf,%.3lf < %.3lf,%.3lf %s\n",v1.getX(),v1.getY(),v2.getX(),v2.getY(),v1<v2 ? "true" : "false");
  printf("%.3lf,%.3lf > %.3lf,%.3lf %s\n",v1.getX(),v1.getY(),v2.getX(),v2.getY(),v1>v2 ? "true" : "false");
  
  //  double c = v1.length
  //printf("%lf\n",c)
    
}
