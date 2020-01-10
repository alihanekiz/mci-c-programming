#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
   const char *name = "hello";
   const char *extension = ".txt";

   char *name_with_extension;
   name_with_extension = malloc(strlen(name) + 1 + 4); /* make space for the new string (should check the return value ...) */
   strcpy(name_with_extension, name);                  /* copy name into the new var */
   strcat(name_with_extension, extension);             /* add the extension */
   char eingabe[200];
   int numbers[100];

   printf("Geben Sie Ihren Text ein:\n");
   while (1)
   {
      fscanf(stdin, "%s", eingabe);
   }

   printf("Ihr Text:\n%s", eingabe);
   return 0;
}

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