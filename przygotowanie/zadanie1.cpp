#include <stdio.h>
#include <stdlib.h>
#include "battery.h"
//#include "protectedbattery.h"

int main()
{
  battery bt1(1000,5000);
  bt1.status();
  battery bt2(bt1.chargeup(6000),3000);
  bt2.status();
  bt1.status();
  bt1.drain(5000);
  bt1.status();
  //bt1.drain(3000);
  //bt1.status();
  
  /*protectedBattery bt2(1000);
  bt2.status();
  bt2.drain(100);
  bt2.status();
  */

}
