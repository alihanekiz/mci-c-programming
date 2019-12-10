#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main(int argc, char *argv[])
{
   if (argc < 4)
   {
      printf("Parameter missing.\n");
      return 1;
   }

   int num1 = atoi(argv[1]);
   int num2 = atoi(argv[3]);
   char *operator= argv[2];
   int result = calculate(num1, num2, operator);
   printf("Ergebnis: %d\n", result);
   return 0;
}