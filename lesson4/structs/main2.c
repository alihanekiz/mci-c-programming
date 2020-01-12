#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
   char *firstname;
   char *secondname;
   unsigned int age;
   char *hobbys;
};

typedef struct Person person;

person createPerson(char *firstname, char *secondname, int age, char *hobbys)
{
   person p;
   p.firstname = firstname;
   p.secondname = secondname;
   p.age = age;
   p.hobbys = hobbys;
   return p;
}

void printIfValid(person p)
{
   if (p.age >= 20 && p.age <= 30 && strstr(p.hobbys, "Tanzen") != '\0')
   {
      printf("%s\n", p.secondname);
   }
}

void filterData(char line[])
{
   char firstname[20];
   char secondname[20];
   char hobbys[100];
   int age = 0;
   int head = 0;

   char *token = strtok(line, ";");
   head = 0;
   while (token != NULL)
   {
      switch (head)
      {
      case 0:
      {
         strlcpy(firstname, token, sizeof(firstname));
      }
      break;
      case 1:
      {
         strlcpy(secondname, token, sizeof(secondname));
      }
      break;
      case 2:
      {
         age = atoi(token);
      }
      break;
      case 3:
      {
         strlcpy(hobbys, token, sizeof(hobbys));
         person p = createPerson(firstname, secondname, age, hobbys);
         printIfValid(p);
      }
      break;
      }
      token = strtok(NULL, ";");
      ++head;
   }
}

int main(void)
{

   FILE *filehandle = fopen("persons_input.txt", "r");
   char line[255];

   while (fscanf(filehandle, "%s", line) != EOF)
   {
      filterData(line);
   }

   return 0;
}