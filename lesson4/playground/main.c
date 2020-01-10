#include <stdio.h>
#include <math.h>

int getNumFromArr(int nums[], int len)
{
   int exponent = len - 1;
   int base = 10;
   int final_val = 0;
   int temp_val = 0;
   for (int iterator = 0; iterator < len; ++iterator)
   {
      temp_val = nums[iterator] * pow(base, exponent);
      final_val += temp_val;
      --exponent;
   }
   return final_val;
}

int isNumber(char c)
{
   if (c <= 47 || c >= 58)
      return 0;
   return 1;
}

int main()
{
   char text[20] = "Alihan";
   printf("%c", *text);
   return 0;
}
