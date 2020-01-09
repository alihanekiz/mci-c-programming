#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
      {
         printf("Geben Sie Zahl 1 ein: ");
         scanf("%s", &eingabe);
         num1 = atoi(eingabe);
      }
      break;
      case 1:
      {
         int valid = 0;
         do
         {
            printf("Geben Sie die Operation ein: ");
            scanf("%s", &eingabe);
            if (strcmp(eingabe, "exit") == 0)
            {
               return 0;
            }
            if (strcmp(eingabe, "+") == 0 || strcmp(eingabe, "-") == 0 || strcmp(eingabe, "*") == 0 || strcmp(eingabe, "/") == 0)
            {
               valid = 1;
               operand = eingabe[0];
            }
            else
            {
               printf("Falsche Eingabe!\n");
            }
         } while (valid == 0);
      }
      break;
      case 2:
      {
         printf("Geben Sie Zahl 2 ein: ");
         scanf("%s", &eingabe);
         num2 = atoi(eingabe);
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