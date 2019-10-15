// BIBLIOTHEQUE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NFOIS 5 //Constante
#define PI 3.14
#define Nom "Cornu"
#define CAR "x"

int main()
{
    /*const int cnT=10; //Constance locale au main

    volatile int nVolN;

    static int nStatB;*/

    //Integer
    short int nA; //short sn
    int nB;
    long int nC; //long ln

    printf("Taille de nA : %d\n",sizeof(nA));
    printf("Taille de nB : %d\n",sizeof(nB));
    printf("Taille de nC : %d\n\n",sizeof(nC));

    //Real
    float fltReelSimple;
    double dblReelDouble;

    printf("Taille de fltReelSimple : %d\n",sizeof(fltReelSimple));
    printf("Taille de dblReelDouble : %d\n\n",sizeof(dblReelDouble));

    //Caractères
    char cCaractere;

    printf("Taille de cCaraactere : %d\n\n",sizeof(cCaractere));

    //Testet define
    printf("Taille de NFOIS : %d %d\n", sizeof(NFOIS), NFOIS);
    printf("Taille de PI : %d %f\n", sizeof(PI), PI);
    printf("Taille de Nom : %d %s\n", sizeof(Nom), Nom);
    printf("Taille de CAR : %d %c\n\n", sizeof(CAR), CAR);

    //Opérateurs
    int nI=0;
    ++nI; //pre-incrementation
    nI++; //post-incrementation

    //% modulo
    /* /division */

    //Cast
    long double ldblLongDouble=105.16841655189;
    printf("Valeur de ldblLongDouble : %lf\n\n", (double)ldblLongDouble);

    //Opérateurs relationnels
    // > , < , >= , <= , == , !=

    //Opérateurs logiques
    // & , && , | , || , !

    //Factorisation opérateurs
    // += , -= , %= , /= , *=
}
