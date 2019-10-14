// BIBLIOTHEQUE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// CONSTANTE
#define NFOIS 5 // Constante

// Exemple de proramme en C

// MAIN
int main()
{
    int i;
    float x;
    float racx;

    printf("Bonjour\n"); //méthode de sortie standard qui renvoie sur la console, un flux de données
    printf("Calcul de %d racines carrees \n",NFOIS); //%d indique le format de la variable qui va être affichée (ici int)
    for (i=0; i<NFOIS; i++){
        printf("Donnez un nombre : ");
        scanf("%f",&x); //fonction servant à récupérer la saisie de donnée d'un certain type. %f indique le format qui va être affichée (ici float)
        if (x<0.0) //.0 !!! important car c'est un réel !!!
            printf("Le nombre %f ne possede pas de racine carre\n",x);
        else{
            racx=sqrt(x);
            printf("Le nombre %f a pour racine carree : %f\n",x,racx);
        }
    }
    printf("Travail termine");

    return 0;
}
