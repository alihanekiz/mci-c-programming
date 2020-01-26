

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "umrechnen.h"

int main (int argc, char *argv[]) {
    
    char tmp [4];
    float eurobetrag;

            
    for (int i = 2; i < argc; i++) {
        sscanf (argv[i], "%4[A-Z]", tmp);
        if (strlen(tmp) != 3) {
            fprintf (stderr, "Eingabefehler: Bitte geben Sie ein gültiges Währungskürzel ein!\n");
            return EXIT_FAILURE;
        }
    }
    
    sscanf (argv[1], "%f", &eurobetrag);
    if (eurobetrag <= 0) {
        eurobetrag = 0;
    }
    
    struct curr {
        char wname[25];
        char wkuerzel[3];
        float wkurs;
    } waehrung [32];
    
    
    FILE *quelle =  fopen ("currency_data.txt", "r");
    
    if (quelle == NULL) {
        fprintf (stderr, "Lesefehler: Die Datei \"currency_data.txt\" konnte nicht geöffnet werden!\n");
        return 1;
    }
    char buffer [1024];
    
    for (int i = 0; i < 32; i++) {
    fgets (buffer, 1024, quelle);
    sscanf (buffer, "%[^;]; %[^;]; %f",
            waehrung[i].wname,
            waehrung[i].wkuerzel,
            &waehrung[i].wkurs);
    }
    fclose (quelle);
    
    fprintf (stdout, "%.2f€ sind umgerechnet:\n", eurobetrag);
    
    for (int j = 2; j < argc; j++) {
        char *gesuchteWaehrung = argv[j];
        int treffer = 0;
        for (int k = 0; k < 32; k++) {
            if (strstr (waehrung[k].wkuerzel, gesuchteWaehrung)) {
                umrechnen (eurobetrag, waehrung[k].wname, waehrung[k].wkurs);
                treffer += 1;
            }
        }
        if (treffer == 0)
            fprintf (stdout, "Kürzel '%s' nicht gefunden.\n", gesuchteWaehrung);
    }

    return 0;
}
