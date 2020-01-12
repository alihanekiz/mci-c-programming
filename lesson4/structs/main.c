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
         printf("%s\n", p.hobbys[i]);
      }
   }
   printf("\n\n");
}

void printIfValid(person p)
{
   if (p.age >= 20 && p.age <= 30)
   {
      for (int i = 0; i < 5; ++i)
      {
         if (p.hobbys[i] != NULL && strcmp(p.hobbys[i], "Tanzen") == 0)
         {
            printf("%s\n", p.secondname);
         }
      }
   }
}

void createHobbies(char *hobbys[], char hobbysAsString[15])
{
   char temp[50];
   int head = 0;
   int stored = 0;
   for (int iterator = 0; hobbysAsString[iterator] != '\0'; ++iterator)
   {
      if (hobbysAsString[iterator] == 44 || hobbysAsString[iterator + 1] == '\0')
      {
         //store the data
         temp[head] = '\0';
         if (hobbysAsString[iterator + 1] == '\0')
         {
            strncat(temp, &hobbysAsString[iterator], sizeof(temp) - strlen(temp) - 1);
         }
         hobbys[stored] = malloc(strlen(temp) + 1);
         strcpy(hobbys[stored], temp);
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
   for (; stored <= 5; ++stored)
   {
      hobbys[stored] = NULL;
   }
}

void prepData(char line[])
{
   char temp[51];
   int head = 0;
   int toDo = 1;
   char firstname[15];
   char secondname[15];
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
            strlcpy(firstname, temp, sizeof(firstname));
         }
         break;
         case 2:
         {
            strlcpy(secondname, temp, sizeof(secondname));
         }
         break;
         case 3:
         {
            age = atoi(temp);
         }
         break;
         case 4:
         {
            strncat(temp, &line[iterator], sizeof(temp) - strlen(temp) - 1);

            char *hobbyArray[5];
            createHobbies(hobbyArray, temp);
            person p = createPerson(firstname, secondname, age, hobbyArray);
            printPerson(p);
            printIfValid(p);
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
}

int main(void)
{
   FILE *fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen("persons_input.txt", "r");
   if (fp == NULL)
      exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, fp)) != -1)
   {
      prepData(line);
   }

   fclose(fp);
   if (line)
      free(line);
   return 0;
}