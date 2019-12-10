#include <stdio.h>
#include <string.h>

int calculate(int x, int y, char *operation)
{
   if (!strcmp(operation, "+"))
   {
      return x + y;
   }
   if (!strcmp(operation, "-"))
   {
      return x - y;
   }
   if (!strcmp(operation, "/"))
   {
      return x / y;
   }
   if (!strcmp(operation, "*"))
   {
      return x * y;
   }

   return 0;
}
