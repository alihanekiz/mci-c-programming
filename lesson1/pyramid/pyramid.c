#include <stdio.h>

void pyramid() {
   printf("  * \n");
   printf(" ");
   for(int i=0; i<=2; ++i) {
      printf("*");
   }
   printf("\n");
   for(int i=0; i<=4; ++i) {
      printf("*");
   }
   printf("\n");
}


int main() {
   pyramid();
   return 0;
}