#include <stdio.h>
#include <stdlib.h>

void printPyramid(int height);

int main(int argc, char *argv[])
{
   if (argc == 1)
   {
      printf("Parameter missing.\n");
      return 1;
   }
   int param = atoi(argv[argc - 1]);
   printPyramid(param);
   return 0;
}

void printPyramid(int height)
{
   for (int step = 1; height > 0; --height)
   {
      int distance = height - 1;
      for (; distance > 0; --distance)
      {
         printf(" ");
      }
      for (int i = 1; i <= step; ++i)
      {
         printf("*");
      }
      printf("\n");
      step += 2;
   }
   return;
}