#include <stdio.h>
#include <stdlib.h>

void printMean(int *arr, int size)
{
   float result = 0;
   for (int i = 0; i < size; ++i)
   {
      result += *(arr + i);
   }
   result /= size;
   printf("Der Durchschnitt Ihres Arrays ist: %.1f\n", result);
}

int main()
{
   int currentSize = 5;
   int iteration = 0;
   int *array = malloc(currentSize * sizeof(int));
   char input[255];
   while (input[0] != '\n')
   {
      printf("Eingabe #%d:\n", iteration + 1);
      fgets(input, 200, stdin);
      int num = atoi(input);
      if (num != 0)
      {
         *(array + iteration) = num;
         if (iteration + 1 == currentSize)
         {
            currentSize += 5;
            array = (int *)realloc(array, currentSize * sizeof(int));
         }
         ++iteration;
      }
   }

   printf("Eingabe beendet.\n");
   printMean(array, iteration);
   free(array);
   return 0;
}