#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 10
#define MOT "HELLO"

//Les entrées et sorties conversationnelles

int main()
{
    printf("%d\n",TAILLE);
    printf("%s\n",MOT);

    //saisie
    int val;
    scanf("%d",&val);
    printf("Valeur : %d\n", val);
    fflush(stdin); //Vide le buffer de la saisie
    char car;
    scanf("%c",&car);
    printf("Lettre : %c\n", car);
    fflush(stdin);
    char tabCar[TAILLE]; //de 0 à TAILLE-1
    // scanf("%s",&tabCar);
    // gets(tabCar);
    fgets(tabCar,TAILLE,stdin);
    printf("Mot : %s\n", tabCar);


    return 0;
}
