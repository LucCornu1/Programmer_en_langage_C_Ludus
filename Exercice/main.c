#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*void main()
{
    char car;
    do {
        printf("Veuillez entrer un caractere, le programme continue si vous entrez une lettre de l'alphabet\n");
        fflush(stdin);
        car=getchar();
    } while((car>='a' && car<='z') || (car>='A' && car<='Z'));
}*/

/*void main() //exercice Addition1
{
    int nI, nN, nSom;
    nSom=0;
    nI=0;
    while(nI<4){
        printf("Donnez un entier\n");
        scanf("%d",&nN);
        nSom+=nN;
        nI++;
    }
    printf("Somme : %d\n", nSom);
}*/

/*void main() //exercice Addition2
{
    int nI, nN, nSom;
    nSom=0;
    nI=0;
    do{
        printf("Donnez un entier\n");
        scanf("%d",&nN);
        nSom+=nN;
        nI++;
    } while(nI<4);
    printf("Somme : %d\n", nSom);
}*/

/*void main() //exercice MoyenneNote
{
    int nI, nMax, nN, nSom;
    printf("Veuillez entrer le maximum de notes\n");
    scanf("%d",&nMax);
    nSom=0;
    for(nI=0;nI<nMax;nI++){
        printf("Veuillez entrer la note n°%d\n",nI);
        scanf("%d",&nN);
        nSom+=nN;
    }
    nSom=nSom/nMax;
    printf("Voici la moyenne : %d",nSom);
    printf(" sur %d",nMax);
    printf(" notes\n");
}*/

/*void main() //exercice TriangleEtoile
{
    int nMax, nI, nY;
    printf("Veuillez entrer un nombre de lignes\n");
    scanf("%d",&nMax);
    for(nI=0;nI<nMax;nI++){
        for(nY=0;nY<=nI;nY++){
            printf("*");
        }
        printf("\n");
    }
}*/

/*void main() //exercice NombrePremier
{
    int nI, nNb, nP;
    float nR;
    printf("Veuillez entrer un entier a tester\n");
    scanf("%d",&nNb);
    nI=2;
    nP=0;
    while(nP!=1 && (nI<nNb && nNb>1)){
        nR=nNb%nI;
        if(nR==0){
            nP=1;
            printf("Ce nombre n'est pas premier : %d", nNb);
        }
        nI++;
    }
    if(nP==0){
        printf("Ce nombre est premier : %d", nNb);
    }
}*/

void main() //exercice TableMultiplication
{
    int nI, nJ, nR;
    const cT=10;
    for(nI=0;nI<=cT;nI++){
        if(nI==0){
            printf(" X  ");
        }else{
            printf(" %d  ",nI);
        }
    }
    printf("\n");

    for(nI=0;nI<cT;nI++){
        printf(" %d ",nI+1);
        if(nI+1<10){
            printf(" ");
        }
        for(nJ=0;nJ<cT;nJ++){
            nR=(nI+1)*(nJ+1);
            printf(" %d ",nR);
            if(nR+1<11){
                printf(" ");
            }
        }
        printf("\n");
    }
}
