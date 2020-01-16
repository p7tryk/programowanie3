#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <math.h>


void fun(array& arr)
{
  try{
    arr[arr.getSize()+10]=10;
  }
  catch (...)
    {
      printf("wyjatek w funkcji\n");
      throw;
    }
}

int main()
{
  array ar(10,1);
  ar[2] = 2;
  array ar2 = ar;
  try
    {
      array ar10(10,1);
      ar2=ar2/1;
      ar2[-2] = 4;
      fun(ar10);
      for(int i = 0; i<=ar2.getSize();i++)
	ar2[i] = sin(i/10.);
    }
  catch(divbyzero_exception)
    {
      printf("division by 0\n");
    }
  catch(negative_index_exception ex)
    {
      printf("negative index=%d\n",ex.getIndex());
    }
  catch(index_exception ex)
    {
      printf("index out of range. index=%d\n",ex.getIndex());
    }
  catch(...)
    {
      printf("jakis blad\n");
      throw;
    }
  
  array ar3(12,3);
  ar.printArray();
  printf("+\n");
  ar3.printArray();
  array ar4 = ar + ar3;
  printf("=\n");
  ar4.printArray();
  printf("-\n");
  ar2.printArray();
  ar4 = ar4 - ar2;
  printf("=\n");
  ar4.printArray();
  
  
  
  /*
  printf("\n%lf\n",s);
  for(int i=0;i<list.getSize();i++)
    s+=list[i];
  printf("suma=%.3lf,srednia=%.3lf\n",s,s/list.getSize());
  */
}
