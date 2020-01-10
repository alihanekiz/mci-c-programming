#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumber(char *str)
{
   int isNumber = 1;
   for (int i = 0; str[i] != '\0'; ++i)
   {
      if (str[i] <= 47 || str[i] >= 58)
      {
         isNumber = 0;
      }
   }
   return isNumber;
}

int main()
{

   char eingabe[200];
   int iteration = 0;
   int num1;
   int num2;
   char operand;
   while (strcmp(eingabe, "exit") != 0)
   {
      switch (iteration)
      {
      case 0:
      case 2:
      {
         int passed = 0;
         do
         {
            if (iteration == 0)
               printf("Geben Sie Zahl 1 ein: ");
            if (iteration == 2)
               printf("Geben Sie Zahl 2 ein: ");
            fscanf(stdin, "%s", eingabe);
            if (strcmp(eingabe, "exit") == 0)
            {
               printf("Rechner wird geschlossen\n");
               return 0;
            }
            if (isNumber(eingabe) == 1)
            {
               passed = 1;
            }
            else
            {
               fprintf(stderr, "Falsche Eingabe!\n");
            }
         } while (passed == 0);

         if (iteration == 0)
            num1 = atoi(eingabe);
         if (iteration == 2)
            num2 = atoi(eingabe);
      }
      break;
      case 1:
      {
         int valid = 0;
         do
         {
            printf("Geben Sie die Operation ein: ");
            fscanf(stdin, "%s", eingabe);
            if (strcmp(eingabe, "exit") == 0)
            {
               printf("Rechner wird geschlossen\n");
               return 0;
            }
            if (strcmp(eingabe, "+") == 0 || strcmp(eingabe, "-") == 0 || strcmp(eingabe, "*") == 0 || strcmp(eingabe, "/") == 0)
            {
               valid = 1;
               operand = eingabe[0];
            }
            else
            {
               fprintf(stderr, "Falsche Eingabe!\n");
            }
         } while (valid == 0);
      }
      break;
      case 3:
      {
         switch (operand)
         {
         case '+':
         {
            int erg = num1 + num2;
            printf("Ergebnis: %d\n", erg);
         }
         break;
         case '-':
         {
            int erg = num1 - num2;
            printf("Ergebnis: %d\n", erg);
         }
         break;
         case '*':
         {
            int erg = num1 * num2;
            printf("Ergebnis: %d\n", erg);
         }
         break;
         case '/':
         {
            float erg = (float)num1 / (float)num2;
            printf("Ergebnis: %.2f\n", erg);
         }
         break;
         }
      }
      }
      if (iteration != 3)
      {
         ++iteration;
      }
      else
         iteration = 0;
   }
   printf("Rechner wird geschlossen\n");
   return 0;
}