#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 3

void initTabMorpion(char [][TAILLE]);
void afficheTabMorpion(char [][TAILLE]);
int tourJeuMorpion(char [][TAILLE],int);
int verifTabMorpion(char [][TAILLE]);
int verifVictoire(char [][TAILLE], int);

int main(){
	char cTabMorpion[TAILLE][TAILLE];
	initTabMorpion(cTabMorpion);
	int nVictoire=0, nJoueur=1, nCompt;
	//afficheTabMorpion(cTabMorpion);
	while(nVictoire==0){
		nJoueur = tourJeuMorpion(cTabMorpion, nJoueur);
		afficheTabMorpion(cTabMorpion);
		nVictoire = verifVictoire(cTabMorpion, nVictoire);
		nCompt = verifTabMorpion(cTabMorpion);
		if(nCompt>8){
			break;
		}
	}
	if(nVictoire>0){
		printf("Joueur 1 a gagne\n");
	}else if(nVictoire<0){
		printf("Joueur 2 a gagne\n");
	}else{
		printf("Egalite\n");
	}
	return 0;
}

void initTabMorpion(char cTabMorpion[TAILLE][TAILLE]){
	int i, j;
	for(i=0;i<TAILLE;i++){
		for(j=0;j<TAILLE;j++){
			cTabMorpion[i][j] = ' ';
		}
	}
}

int tourJeuMorpion(char cTabMorpion[TAILLE][TAILLE], int nJoueur){
	int x, y;
	do{
		if(nJoueur>0){
			printf("C'est au tour du joueur 1\n");
		}else{
			printf("C'est au tour du joueur 2\n");
		}
		do{
			printf("Veuillez entrer la ligne entre 1 et %d : \n", TAILLE);
			printf("Ligne : ");
			scanf("%d",&x);
		}while((x<1) || (x>3));
		do{
			printf("Veuillez entrer la colonne entre 1 et %d : \n",TAILLE);
			printf("Colonne : ");
			scanf("%d",&y);
		}while((y<1) || (y>3));
		x = x-1;
		y = y-1;
	}while(cTabMorpion[x][y]!=' ');
	if(nJoueur>0){
		cTabMorpion[x][y] = 'O';
	}else if(nJoueur<0){
		cTabMorpion[x][y] = 'X';
	}
	nJoueur *= -1;
	return nJoueur;
}

void afficheTabMorpion(char cTabMorpion[TAILLE][TAILLE]){
	int i, j;
	for(i=0;i<TAILLE;i++){
		printf("|");
		for(j=0;j<TAILLE;j++){
			printf(" %c |",cTabMorpion[i][j]);
		}
		printf("\n");
	}
}

int verifTabMorpion(char cTabMorpion[TAILLE][TAILLE]){
	int i, j, nCompt=0;
	for(i=0;i<TAILLE;i++){
		for(j=0;j<TAILLE;j++){
			if(cTabMorpion[i][j]!=' '){
				nCompt++;
			}
		}
	}
	return nCompt;
}

int verifVictoire(char cTabMorpion[TAILLE][TAILLE], int nVictoire){
	int i, j, comptX, comptO;
	for(i=0;i<TAILLE;i++){
		comptX = 0;
		comptO = 0;
		for(j=0;j<TAILLE;j++){
			if(cTabMorpion[i][j]=='X'){
				comptX += 1;
			}else if(cTabMorpion[i][j]=='O'){
				comptO += 1;
			}
		}
		if(comptX==3){
			nVictoire = -1;
		}else if(comptO==3){
			nVictoire = 1;
		}
	}
	for(j=0;j<TAILLE;j++){
		comptX = 0;
		comptO = 0;
		for(i=0;i<TAILLE;i++){
			if(cTabMorpion[i][j]=='X'){
				comptX += 1;
			}else if(cTabMorpion[i][j]=='O'){
				comptO += 1;
			}
		}
		if(comptX==3){
			nVictoire = -1;
		}else if(comptO==3){
			nVictoire = 1;
		}
	}
	if((cTabMorpion[0][0]=='X') && (cTabMorpion[1][1]=='X') && (cTabMorpion[2][2]=='X')){
		nVictoire = -1;
	}else if((cTabMorpion[0][0]=='O') && (cTabMorpion[1][1]=='O') && (cTabMorpion[2][2]=='O')){
		nVictoire = 1;
	}
	if((cTabMorpion[0][2]=='X') && (cTabMorpion[1][1]=='X') && (cTabMorpion[2][0]=='X')){
		nVictoire = -1;
	}else if((cTabMorpion[0][2]=='O') && (cTabMorpion[1][1]=='O') && (cTabMorpion[2][0]=='O')){
		nVictoire = 1;
	}
	return nVictoire;
}
