#include <stdio.h>
#include <stdlib.h>

void powerof2(int number)
{
   unsigned long int result = 2;
   for (int exp = 1; result <= number; ++exp)
   {
      result *= 2;
      if (result == number)
      {
         printf("%d\n", exp + 1);
         return;
      }
   }
}

int main(int argc, char *argv[])
{
   if (argc == 1)
   {
      printf("Parameter missing.");
   }
   int base = atoi(argv[1]);
   powerof2(base);
   return 0;
}