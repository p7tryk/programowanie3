#include <stdio.h>
#include <stdlib.h>
#include "animals.h"
#include "dog.h"
#include "bird.h"
#include "fish.h"

int main()
{
  /*
  animal *pz = new animal;
  pz->zryj();
  delete pz;
    */
  /*
  fish*akwarium = new fish[2];
  fish * test = akwarium;
  printf("akwarium = %p, test = %p\n", akwarium, test);
  delete[] test;
  */
 
  fish akwarium;
  

   printf("sizeof: animal %lu, dog %lu, bird %lu, fish %lu\n", sizeof(animal), sizeof(dog),sizeof(bird),sizeof(fish));
}
