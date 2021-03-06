#include <stdio.h>
#include "PillBox.h"
#include "PillBoxCnt.h"

int main()
{
  //zwykla funkcjonalnosc
  PillBox pb1(10);
  pb1.take(6);
  printf("pb1\n");
  pb1.status();
  pb1.take(3);
  pb1.status();
  PillBox pb3(5);
  printf("pb3\n");
  pb3.status();
  pb3=pb1;
  pb3.status();

  //pillbox count
  printf("\n\npillbox count, take(4), take(5)\n");
  PillBoxCnt pb2;
  printf("%d taken\n",pb2.getTotal());
  pb2.refill(6);
  pb2.take(5);
  pb2.refill(10);
  pb2.take(4);
  printf("%d taken\n",pb2.getTotal());

  printf("\n\nprzesypywanie\n");
  //przesypywanie
  PillBox pb4(10);
  PillBox pb5(6);

  PillBox pb6 = pb4+pb5;
  
  printf("pb4=");
  pb4.status();
  
  printf("pb5=");
  pb5.status();

  printf("\npb4+=pb5\n");
  pb4+=pb5;
  printf("pb4=");
  pb4.status();
  printf("pb5=");
  pb5.status();
  printf("\npb4-=pb5\n");
  printf("pb4=");
  pb4-=pb5;
  pb4.status();
  printf("pb5=");
  pb5.status();

  
  //operatory globalne
  printf("\n\npb6=pb4+pb5\n");
  pb6.status();

  printf("\npb1==pb3\npb1=%d,pb3=%d\n%s\n",pb1.getNumber(),pb3.getNumber(),pb1==pb3 ? "true" : "false");
  printf("\npb4==pb5\npb4=%d,pb5=%d\n%s\n",pb4.getNumber(),pb5.getNumber(),pb4==pb5 ? "true" : "false");
  
  printf("\npb4>pb5\npb4=%d,pb5=%d\n%s\n",pb4.getNumber(),pb5.getNumber(),pb4>pb5 ? "true" : "false");
  printf("\npb4<pb5\npb4=%d,pb5=%d\n%s\n",pb4.getNumber(),pb5.getNumber(),pb4<pb5 ? "true" : "false");

  printf("\n\nwyjatki\n");
  int input;
  printf("ile elementow w pb7? take(11)\n");
  scanf("%d",&input);
  PillBox pb7(input);
  try
    {
      pb7.take(0);
    }
  catch(takefromzero &ex)
    {
      ex.print();
    }
  catch(invalidtake &ex)
    {
      ex.print();
    }
    
  return 0;
}
