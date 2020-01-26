
#include "umrechnen.h"
#include <stdio.h>


void umrechnen (float eurobetrag, char* waehrung, float kurs) {
        
    fprintf (stdout, "%.2f %s\n", eurobetrag * kurs, waehrung);
}
