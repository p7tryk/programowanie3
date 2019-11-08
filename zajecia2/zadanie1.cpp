#include <stdio.h>
#include <stdlib.h>
#include "account.h"


void menu(account * acc)
{
  char input;
  double amount;
  while(true)
    {
      while ((getchar()) != '\n'); 
      amount = 0;
      input = 12;
      printf("\n\n1 zeby sprawdzic status\n2 zeby wplacic\n3 zeby wyplacic\n0 zeby wyjsc\n\n");
      scanf("%c", &input);
            
      
      if(input == '1')
	acc->info();
      else if(input == '2')
	{
	  printf("wpisz ilosc do wplacenia\n");
	  scanf("%lf", &amount);
	  printf("operacja %s",acc->deposit(amount) ? "udana" : "nieudana");
	}
      else if(input == '3')
	{
	  printf("wpisz ilosc do pobrania\n");
	  scanf("%lf", &amount);
	  printf("operacja %s",acc->withdraw(amount) ? "udana" : "nieudana");
	}
      else if(input == '0')
	return;
      else
	printf("niewlasciwy klawisz");
    }
}

int main()
{
  account user(1337);
  menu(&user);
  account test(420);

  test.deposit(200);
  test.info();
  user.deposit(100);
  user.info();
  user.transferTo(&test, 80);
  test.info();
  user.info();  
  
}
	 
