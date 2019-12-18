#include <stdio.h>

int main(int argc, char *argv[])
{
   if (argc == 1)
   {
      printf("check params.\n");
      return 1;
   }
   char *param = *(argv + 1);
   int j = 0;
   int sum = 0;
   for(int i=32; i<126; ++i) {
      char cr = i;
      j = 0;
      sum = 0;
      while(param[j] != '\0') {
         int asciiVal = *(param + j);
         if (asciiVal == cr) {
            sum++;
            
         }
         j++;
      }
      if(sum > 0) {
         printf("Zeichen: '%c' - Häufigkeit: %d\n", cr, sum);
      }  
      
   }
   return 0;
}