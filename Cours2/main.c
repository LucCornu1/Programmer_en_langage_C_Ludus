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

    //TQ
    i=0;
    while(i<TAILLE){
        printf("NON\n");
        i++;
    }

    //Faire TQ
    i=0;
    do{
        printf("NOUI\n");
        i++;
    }while(i<TAILLE);

    //Cas alternatif de la condition
    int choix=-1;
    printf("Veuillez entrer votre choix\n");
    scanf("%d", &choix);
    switch(choix){
        case 0:
            printf("Quitter\n");
            break;
        case 1:
            printf("Calculer\n");
            break;
        case 2:
            printf("Jouer\n");
            break;
        default:
            printf("default\n");
            break;
    }

    //a?b instruction1 : instruction2
    a==b? printf("Egaux\n"):printf("Different\n");

    //Instruction Break
    i=0;
    for(i=0;i<5;i++){
        printf("Hello World\n");
        if(i<3){
            printf("continue\n");
            continue;
        }
    }

    return 0;
}
