#include <stdio.h>
#include "my_string.h"

int main()
{
   void *str = "Alihan";
   string_rev(str);
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

void string_rev(unsigned char *str)
{
   int len = 0;
   while (str[len] != '\0')
   {
      ++len;
   }

   unsigned char *rev_str[len];
   int reverse = len - 1;
   for (int i = 0; i < len; ++i)
   {
      rev_str[i] = &str[reverse];
      --reverse;
   }
   for (int i = 0; i < len; ++i)
   {
      printf("%c", *rev_str[i]);
   }
   printf("\n");
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
