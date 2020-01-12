#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
   FILE *handle = fopen("integers_output.txt", "w");
   if (handle == NULL)
   {
      fprintf(stderr, "Fehler. Datei konnte nicht angelegt werden.");
      return 1;
   }
   fprintf(stdout, "Geben Sie Ihren Text ein: \n");

   char input[200];

   while (input[0] != '\n')
   {
      fgets(input, 200, stdin);
      int i = 0;

      while (input[i] != '\0')
      {
         if (input[i] > 47 && input[i] < 58)
         {
            fprintf(handle, "%c", input[i]);
            if (input[i + 1] < 48 || input[i + 1] > 57)
               fprintf(handle, " ");
         }
         if (input[i] == '\n')
            fprintf(handle, "\n");
         i++;
         fflush(handle);
      }
   }

   fprintf(stdout, "Ende der Eingabe!\n");
   fclose(handle);
   return 0;
}