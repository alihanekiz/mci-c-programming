#include <stdio.h>
#include <stdlib.h>

void printPrimes(int range);

int main(int argc, char *argv[])
{
   if (argc <= 1)
   {
      printf("Parameter missing..\n");
      return 1;
   }
   int param = atoi(argv[1]);
   printPrimes(param);

   return 0;
}

void printTab() { printf("  "); }

void printPrimes(int range)
{
   int formating = 0;
   for (int i = 2; i <= range; ++i)
   {
      for (int j = 2; j <= i; ++j)
      {
         if (i % j == 0 && i != j)
            break;
         if (i == j)
         {
            ++formating;
            printf("%d", i);
            printTab();
            if (formating == 10)
            {
               printf("\n");
               formating = 0;
            }
         }
      }
   }
   printf("\n");
}