#include <stdio.h>
#include "bulb.h"

int main()
{
  bulb zarowka1(1,68);
  bulb zarowka2(1);
  bulb zarowka3;
    
  zarowka1.printstatus();

  
  zarowka1.turnon();
  zarowka1.changebrightness(54);
  
  zarowka1.printstatus();

  
  zarowka1.changebrightness(250);

  
  zarowka1.printstatus();

  zarowka1.decBrightness();
  zarowka1.printstatus();

  zarowka1.decBrightness(14);
  zarowka1.printstatus();

  zarowka1.incBrightness();
  zarowka1.printstatus();

  zarowka1.incBrightness(14);
  zarowka1.printstatus();
  
  zarowka1.turnoff();

  
  zarowka1.printstatus();
  
}
