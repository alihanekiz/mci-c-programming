#include <stdio.h>

void forEachForString(char *str, void (*f)(char *));
void changeMe(char *character)
{
   int ascii = *character;
   int diff = 32;
   if (ascii >= 97)
      printf("%c\n", *character - diff);
   else
      printf("%c\n", *character + diff);
}

int main()
{
   char *mystr = "asdf";
   forEachForString(mystr, changeMe);
}

void forEachForString(char *str, void (*f)(char *))
{
   int i = 0;
   while (str[i] != '\0')
   {
      f(&str[i]);
      ++i;
   }
}