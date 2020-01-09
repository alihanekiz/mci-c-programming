#include <stdio.h>

struct Person
{
   char *firstname;
   char *secondname;
   unsigned int age;
   char *hobbys[5];
};

typedef struct Person person;

person createPerson(char *firstname, char *secondname, unsigned int age, char *hobbys[5])
{
   person p;
   p.firstname = firstname;
   p.secondname = secondname;
   p.age = age;
   for (int i = 0; i < 5; ++i)
   {
      p.hobbys[i] = hobbys[i];
   }
   return p;
}

void printPerson(person p)
{
   printf("Firstname: %s\nSecondname: %s\nAge: %d\n", p.firstname, p.secondname, p.age);
   for (int i = 0; i < 5; ++i)
   {
      if (p.hobbys[i] != NULL)
      {
         printf("%s, ", p.hobbys[i]);
      }
   }
}

char *seperateStringToArray(char *str)
{
   char *hobbys_array[5] = {NULL};
   int iterator = 0;
   int head = 0;
   int hobby_count = 0;
   char temp[200];
   while (str[iterator] != '\0')
   {
      if (str[iterator] != ',' && str[iterator + 1] != '\0')
      {
         temp[head] = str[iterator];
         ++head;
      }
      else
      {
         hobbys_array[hobby_count] = temp;
         ++hobby_count;
         head = 0;
         temp[2] = '\0';
      }
      ++iterator;
   }
   printf("%s", hobbys_array[1]);
   return NULL;
}

int main(void)
{
   // FILE *filehandle = fopen("persons_input.txt", "r");
   // person people_array[100] = {NULL};
   // char buffer[255];

   // while (fgets(buffer, 255, filehandle) != NULL)
   // {
   //    printf("%s", buffer);
   // }

   // fgets(buffer, 255, filehandle);
   // printf("%s", buffer);
   // fgets(buffer, 255, filehandle);
   // printf("%s", buffer);
   seperateStringToArray("Laufen, XYZ");
   // person p = createPerson("Test", "Ekiz", 20, );
   // printPerson(p);
   return 0;
}