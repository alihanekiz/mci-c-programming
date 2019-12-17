#include <stdio.h>
#include <stdlib.h>

void calcMean(int *arr, int size)
{
   float result;
   for (int i = 0; i < size; ++i)
   {
      result = result + arr[i];
   }
   result = result / size;
   printf("Mean: %.1f\n", result);
}

int main()
{
   char userInput[20];
   printf("Wie viele Zahlen wollen Sie eingeben ?\n");
   printf("Ihre Eingabe: ");
   scanf("%s", userInput);
   int size = atoi(userInput);
   int myArr[size];
   for (int i = 0; i < size; ++i)
   {
      printf("Geben Sie eine Zahl ein: ");
      scanf("%s", userInput);
      *(myArr + i) = atoi(userInput);
   }
   calcMean(myArr, size);

   return 0;
}
