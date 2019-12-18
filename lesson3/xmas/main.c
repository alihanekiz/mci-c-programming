#include <stdio.h>

void xmas_sort(int* array, const int n);

int main() {

   int myArr[] = {100, 2, 20, 3, 12, 40, 70, 10};
   int amount = 8;
   xmas_sort(myArr, amount);
   
   return 0;
}

void xmas_sort(int* array, const int n) {
   int i = 0;
   while (i < n) {
      if ((i + 1) < n) {
         if (array[i] > array[i+1]) {
            int h = array[i];
            array[i] = array[i+1];
            array[i+1] = h;
            if ((i - 1) < 0) ++i;
            else --i;
         } else ++i;
      } else ++i;
   }
}