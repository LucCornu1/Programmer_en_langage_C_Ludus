#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 100

int main()
{
    int nTabInteger[TAILLE];
    float fltTabFlaot[TAILLE];
    double dblTabDouble[TAILLE];
    char cTabCar[TAILLE];
    int nI=0;

    for(nI=0;nI<TAILLE;nI++){
        nTabInteger[nI]=0;
        fltTabFlaot[nI]=0.0;
        dblTabDouble[nI]=0.0;
        cTabCar[nI]='\0'; //'\0' caract�re de fin de cha�ne
    }
    // Nom, pr�nom, DDN, Adresse (code postal, nom de la rue, num�ro, ville) -> TD carte identit�

    return 0;
}
