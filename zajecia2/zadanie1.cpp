#include <stdio.h>
#include <stdlib.h>
#include "account.h"

double account::m_interest;
int account::lastAccount = 1000;



int main()
{
  //account lol[1000];
  account test;
  account user;
  //menu(&user);
 

  

  account::setInterest(10.);
  user.getInterest();
  user.deposit(100);
  user.transferTo(&test, 80);
  test.info();
  user.info();
  for(int i=0;i<10;i++)
    {
      printf("\n");
      user.capitalize();
      test.capitalize();
      test.info();
      user.info();
    }
}
	 
