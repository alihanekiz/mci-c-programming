#include <stdio.h>
// #include "my_string.h"

int string_cmp(const char *str1, const char *str2);
unsigned int string_len(const char *str);
void string_rev(unsigned char *str);
char *string_chr(const char *str, const char c);

int main()
{
}

char *string_chr(const char *str, const char c)
{
   int i = 0;
   while (str[i] != '\0')
   {
      if (str[i] == c)
         return (void *)str + i;
      ++i;
   }
   return NULL;
}

//TODO: fix this!
void string_rev(unsigned char *str)
{
   int len = 0;
   while (str[len] != '\0')
   {
      ++len;
   }
   char str2[len];
   int end = len - 1;
   for (int begin = 0; begin < len; begin++)
   {
      str[begin] = str2[end];
      end--;
   }
}

unsigned int string_len(const char *str)
{
   int i = 0;
   while (str[i] != '\0')
   {
      ++i;
   }
   return i;
}

int string_cmp(const char *str1, const char *str2)
{
   int i = 0;
   while (str1[i] != '\0')
   {
      if (str2[i] == '\0' || str2[i] != str1[i])
         return 0;
      ++i;
   }
   i = 0;
   while (str2[i] != '\0')
   {
      if (str1[i] == '\0' || str2[i] != str1[i])
         return 0;
      ++i;
   }
   return 1;
}
