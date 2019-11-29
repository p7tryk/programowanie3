#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "student.h"
#include "vipaccount.h"

double account::m_interest;
double studentAccount::m_interest;
double vipAccount::m_interest;
int account::lastAccount = 1000;



int main()
{
  
  account acc1(100);
  studentAccount acc2(100);
  studentAccount acc3(100);
  acc1.setInterest(2);
  acc2.setInterest(5);
  acc1.info();
  acc2.info();
  acc1.capitalize();
  acc2.capitalize();
  acc3.capitalize();
  acc1.info();
  acc2.info();
  acc3.info();

   /*
  account test;
  account user;
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
  */
  /*
  account test1(300);
  vipAccount test2(100);
  test2.setInterest(3);
  test1.info();
  test2.info();
  test1.transferTo(&test2, 100);
  test1.info();
  test2.info();
  test2.transferTo(&test1, 100);
  test1.info();
  test2.info();
  */
 
}
	 
