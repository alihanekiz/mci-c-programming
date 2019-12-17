#include <stdio.h>

void forEach(char *str, void (*f)(char *));
void toUpper(char *character);

int main()
{
   char eingabe[100];
   char *ptr = eingabe;
   printf("Geben Sie eine Buchstabenfolge ein: ");
   scanf("%s", ptr);
   printf("Ergebnis: ");
   forEach(ptr, toUpper);
   printf("\n");
   return 0;
}

void toUpper(char *character)
{
   int diff = 32;
   int asciiNr = *character;
   if (asciiNr >= 97 && asciiNr <= 122)
   {
      printf("%c", *character - diff);
   }
   else
   {
      printf("%c", *character);
   }
}

void forEach(char *str, void (*f)(char *))
{
   int i = 0;
   while (str[i] != '\0')
   {
      f(&str[i]);
      ++i;
   }
}