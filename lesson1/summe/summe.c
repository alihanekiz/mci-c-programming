#include <stdio.h>

int sumLoop();

int main()
{
   int result = sumLoop();
   printf("Das Ergebnis lautet: %d\n", result);
   return 0;
}

int sumLoop()
{
   int step = 0;
   int start = 2;
   int sum = start;
   for (int i = 2; i <= 1000; ++i)
   {
      if (step == 8)
      {
         sum += i;
         step = 0;
      }
      step += 1;
   }
   
   return sum;
}