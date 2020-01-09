#include <stdio.h>
#include <string.h>

int *getNumbers(char input[])
{
   int i = 0;
   while (*(input + i) != '\0')
   {
      printf("%c", *(input + i));
      ++i;
   }
   return NULL;
}

int main()
{
   char eingabe[200];
   printf("Geben Sie Ihren Text ein:\n");
   fscanf(stdin, "%s", eingabe);
   getNumbers(&eingabe);
   return 0;
}