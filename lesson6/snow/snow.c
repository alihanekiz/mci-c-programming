#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itoa(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

int checkIfNum(char* str) {
    for(int i=0; str[i] != '\0'; ++i) {
        if(str[i] < 48 || str[i] > 57) return -1;
    }
    return 0;
}

void getData(char* location, int* day) {
    char input[50];
    
    fprintf(stdout, "Geben Sie einen Ort an: ");
    fscanf(stdin, "%s", input);
    strlcpy(location, input, sizeof(location)+2);
    strlcpy(input, "",  sizeof(input));
    fprintf(stdout, "Geben Sie einen Tag an: ");
    fscanf(stdin, "%s", input);
    *day = atoi(input);
    if(checkIfNum(input) < 0) {
        *day = -1;
    }
}

int getTemp(char* fileloc, char* location) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int temp = 0;
    // int found = 0;
    char city[200];
    fp = fopen(fileloc, "r");
    if (fp == NULL)
      exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        sscanf(line, "%[^;]; %d", city, &temp);
        if(strcmp(location, city) == 0) {
            fclose(fp);
            return temp;
        }
    }
    return 0;
}

int main() {

    char location[50];
    int day = 0;

    getData(location, &day);

    if(day < 1 || day > 8) {
        fprintf(stderr , "Eingabefehler!");
        return EXIT_FAILURE;
    }

    return 0;
}   
