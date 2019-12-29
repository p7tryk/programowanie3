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


int main(int argc, char ** argv)
{
  
  char * filename = new char[256];
  if(argc>1)
    {
      filename = "data.out";
    }
  else
    {
      if(sizeof(argv[2])>sizeof(filename))
	{
	  filename = argv[2];
	}
      else
	filename = "data.out";
    }

  
  accountList list;
  list.readFile(filename);
  list.printall();
  list.info();
  list.writeFile(filename);
  double sum1 = sum(&list);
  printf("suma=%.2lf; srednia=%.2lf\n\n",sum1,sum1/list.getSize());
  list.removeall();
  
  list.readFile(filename);
  list.printall();
  list.removeall();
  
 
}
	 
