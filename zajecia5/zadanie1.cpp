#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "student.h"
#include "vipaccount.h"
#include "list.h"

double account::m_interest;
double studentAccount::m_interest;
double vipAccount::m_interest;
int account::lastAccount = 1000;

double sum(accountList * list)
{
  double amount;
  for(account * ptr = list->getBegin();ptr;ptr=list->getNext(ptr))
    {
      amount += ptr->getBalance();
    }
  return amount;
}


int main()
{
  
  studentAccount acc1(100);
  studentAccount acc2(100);
  studentAccount acc3(100);
  accountList list;
  
  acc1.setInterest(5);
  acc2.setInterest(2);

  
  list.addBegin(&acc3);
  list.addBegin(&acc2);
  list.addBegin(&acc1);
  list.printall();
  list.info();
  list.capitalize();
  printf("\n\n");
  //  list.remove(list.findByNum(1001));
  list.printall();
  double sum1 = sum(&list);
  printf("suma=%.2lf; srednia=%.2lf\n",sum1,sum1/list.getSize());
  list.readFile("data.out");
  
  
  
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
	 
