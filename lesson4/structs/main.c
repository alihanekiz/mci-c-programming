#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void createHobbies(char *hobbys[5], char hobbysAsString[15])
{
   char temp[50];
   int head = 0;
   int stored = 0;
   for (int iterator = 0; hobbysAsString[iterator] != '\0'; ++iterator)
   {
      if (hobbysAsString[iterator] == 44 || hobbysAsString[iterator + 1] == '\0')
      {
         //store the data
         if (hobbysAsString[iterator + 1] == '\0')
         {
            temp[head + 1] = hobbysAsString[iterator];
            printf("%s\n", temp);
         }
         // strcpy(hobbys[stored], temp);

         for (; head >= 0; --head)
         {
            temp[head] = '\0';
         }
         head = 0;
         ++stored;
      }
      else
      {
         temp[head] = hobbysAsString[iterator];
         ++head;
      }
   }
}

int main(void)
{
   char line[100] = "Samatha;Bullis;34;op,Spielen";
   char temp[50];
   int head = 0;
   int toDo = 1;
   char firstname[15];
   char secondname[15];
   char hobbysAsString[15];
   int age;
   for (int iterator = 0; line[iterator] != '\0'; ++iterator)
   {
      if (line[iterator] == 59 || line[iterator + 1] == '\0')
      {
         //store data set.
         switch (toDo)
         {
         case 1:
         {
            strcpy(firstname, temp);
         }
         break;
         case 2:
         {
            strcpy(secondname, temp);
         }
         break;
         case 3:
         {
            age = atoi(temp);
         }
         break;
         case 4:
         {
            // temp[head + 1] = line[iterator];
            strcpy(hobbysAsString, temp);
            printf("%s", firstname);
            printf("%s", secondname);
            printf("%d", age);

            printf("%s", hobbysAsString);
            // char *hobbyArray[5] = {NULL};
            // createHobbies(hobbyArray, hobbysAsString);
         }
         break;
         }
         for (; head >= 0; --head)
         {
            temp[head] = '\0';
         }
         head = 0;
         if (toDo == 4)
         {
            toDo = 1;
         }
         else
            toDo++;
      }
      else
      {
         temp[head] = line[iterator];
         ++head;
      }
   }
   return 0;
}