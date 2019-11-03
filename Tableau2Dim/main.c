#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 10

//Prototypes
void initMatrice(int [][TAILLE], int);
void afficheMatrice(int [][TAILLE]); //Ou : void afficheMatrice(int nMatriceEntier[TAILLE][TAILLE])
int nSommeElementMatrice(int [][TAILLE]);

int main()
{
    int nMatriceEntier[TAILLE][TAILLE];
    initMatrice(nMatriceEntier,5);
    afficheMatrice(nMatriceEntier);
    printf("%d\n",nSommeElementMatrice(nMatriceEntier));
    return 0;
}

//Implementation des fonctions
//Procedures
void initMatrice(int nMatriceEntier[TAILLE][TAILLE], int nValInit){
	int i, j;
	//Initialisation Matrice
	for(i=0;i<TAILLE;i++){
    	for(j=0;j<TAILLE;j++){
    		nMatriceEntier[i][j]=nValInit;
    	}
    }
    afficheMatrice(nMatriceEntier);
}

void afficheMatrice(int nMatriceEntier[TAILLE][TAILLE]){
	int i, j;
	//Affichage Matrice
	for(i=0;i<TAILLE;i++){ //Lignes
    	for(j=0;j<TAILLE;j++){ //Colonnes
    		printf("%d",nMatriceEntier[i][j]);
    	}
    	printf("\n");
    }
}

//Fonction
int nSommeElementMatrice(int nMatriceEntier[TAILLE][TAILLE]){
	int nResSommeMatrice=0, i, j;
	for(i=0;i<TAILLE;i++){
		for(j=0;j<TAILLE;j++){
			nResSommeMatrice+=nMatriceEntier[i][j];
		}
	}
	return nResSommeMatrice;
}