#include <stdio.h>
#include <stdlib.h>

void is_odd(int number)
{
   if (number % 2 == 0)
   {
      printf("false\n");
   }
   else
   {
      printf("true\n");
   }
}

int main(int argc, char *argv[])
{
   if (argc == 1)
   {
      printf("Parameter missing.\n");
      return 1;
   }
   int param = atoi(argv[argc - 1]);
   is_odd(param);
   return 0;
}
