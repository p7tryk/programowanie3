#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <math.h>
#include <new>  //zeby lapac badalloc

/*
void fun(array<double& arr)
{
  try{
    arr[arr.getSize()+10]=10;
  }
  catch (...)
    {
      printf("wyjatek w funkcji fun\n");
      throw;
    }
}
void sinus(array<double& arr)
{
  for(int i=0; i<arr.getSize();i++)
    {
      arr[i]+= sin(i/10.0);
    }
}
*/
int main()
{
  //unsigned int s = 100;
  array<double> ar(10,1);
  ar[2] = 2;
  array<double> ar2 = ar;
  /*
  try
    {
      array ar10<double>(s,1);
      //scanf("%d");
      ar2=ar2/1;
      ar2[2] = 4;
      sinus(ar10);
      ar10.printArray();
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
  catch(memory_exception ex)
    {
      printf("brak pamieci\n");
    }
  catch(...)
    {
      printf("jakis blad\n");
      throw;
    }
  */
  array<double> ar3(12,3);
  ar.printArray();
  printf("+\n");
  ar3.printArray();
  array<double> ar4 = ar + ar3;
  printf("=\n");
  ar4.printArray();
  printf("-\n");
  ar2.printArray();
  ar4 = ar4 - ar2;
  printf("=\n");
  ar4.printArray();
  printf("\n");
  array<char> archar(12,'C');
  archar.printArray();
  array<char> archar2(12,' ');
  printf("\n");
  archar2 = archar + archar2;
  archar2.printArray();
  
  /*
  printf("\n%lf\n",s);
  for(int i=0;i<list.getSize();i++)
    s+=list[i];
  printf("suma=%.3lf,srednia=%.3lf\n",s,s/list.getSize());
  */
}
