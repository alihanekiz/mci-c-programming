#include <stdio.h>

#define HELLO "Hello World!\n"

#define IS_SMALLER100(x) (x < 100)

#define FOR(a, b, c, d)         \
   {                            \
      int e;                    \
   }                            \
   for (int a = b; a <= c; d++) \
   {                            \
      int e;                    \
   }

#define PRINT(a)           \
   {                       \
      printf(a);           \
   }                       \
   {                       \
      int i = 0;           \
      while (i < 10)       \
      {                    \
         printf("\ntest"); \
         ++i;              \
      }                    \
   }

int main()
{
   PRINT("a")
   {
      printf("another print");
   };
   return 0;
}