#include <stdio.h>
#include <stdlib.h>

void powerof2(int number)
{
   unsigned long int result = 2;
   for (int i = 1; i < number; ++i)
   {
      result = result * 2;
   }
   printf("%lu\n", result);
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