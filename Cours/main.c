// BIBLIOTHEQUE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NFOIS 5 //Constante
#define TAILLE 10
#define PI 3.14
#define Nom "Cornu"
#define CAR "x"

int main()
{
    int a=0,b=0,c=0,d=0;

    //condition

    if(a==b){
        printf("Ils sont egaux\n");
    }else{
        printf("Ils ne sont pas egaux\n");
    }

    //condition avec opérateur logique

    if((a==b) && (a==c)){
        printf("Ils sont tous egaux\n");
    }else{
        printf("Il ne sont pas tous egaux\n");
    }

    if((a==b) || (a==c)){
        printf("Ils sont egaux\n");
    }else{
        printf("Ils ne sont pas egaux\n");
    }

    if((a==b) || (a==c)){
        printf("Ils sont egaux\n");
    }else if((a==c) && (a!=d)){
        printf("OUI\n");
    }

    //Boucle
    int i=0;

    for(i=0;i<TAILLE;i++){
        printf("OUI\n");
    }

    return 0;
}
