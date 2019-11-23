#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
  srand(time(NULL));
  double h = 0;
  double r = 0;
  int size = 2;
  int count = 1;
  double x,y = 0;
  
  for(int i=0;i<1000;i++)
    {
      h =(double) size;
      count = 0;
      r=20;
      while(h<=r)
	{
	  r=h;
	  count++;
	  x = fmod(((double)rand()/1000),size);
	  y = fmod(((double)rand()/1000),size);
	  
	  h=sqrt(x*x+y*y);
	  
	}
      printf("%d\n", count);
    }
}
