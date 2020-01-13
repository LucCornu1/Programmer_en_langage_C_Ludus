#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Constantes
#define TAILLE_PAvion 5
#define TAILLE_Croiseur 4
#define TAILLE_CTorpilleur 3
#define TAILLE_Torpilleur 2 //Taille des bateau dans la partie
#define TAILLE_Tab 10 //Taille des grilles des joueurs

//Différents type structurés
typedef struct FLOTTE{
	int pvPAvion;
	int pvCroiseur;
	int pvCTorpilleur1;
	int pvCTorpilleur2;
	int pvTorpilleur;
	int etat_Flotte;
}FLOTTE;

typedef struct JOUEUR{
	int n_Joueur;
	char tabRadar[TAILLE_Tab][TAILLE_Tab];
	char tabJoueur[TAILLE_Tab][TAILLE_Tab];
	FLOTTE flotteJoueur;
}JOUEUR;

//Prototype des fonctions.
void sauvegardeFichier(FILE *, int);
void lectureFichier(FILE *, int);
void initTableauxJeu(char [][TAILLE_Tab], char [][TAILLE_Tab]);
void initPartie(char [][TAILLE_Tab], char [][TAILLE_Tab], int);
void afficheTableauxJeu(char [][TAILLE_Tab], char [][TAILLE_Tab], int);
void initBateaux(char [][TAILLE_Tab], int, int);
void directionBateaux(char [][TAILLE_Tab], char, int, int, int, int);
void cibleTir(int *, int *, char [][TAILLE_Tab]);
char verifToucher(char [][TAILLE_Tab], char [][TAILLE_Tab], int *, int *);
int verifDirectionBateau(char [][TAILLE_Tab], char, int, int, int);
int mainGame();

//Main [Menu du jeu].
int main(){
	int booleen=0, nJoueurVainqueur;
	char charUtilisateur;
	FILE *fichierScore;

	do{//Afficher le menu tant que le Joueur n'appuie pas sur une touche.
		system("cls");
		printf("            -- Bienvenue dans : BATAILLE NAVALE ! --\n\n");
		printf("Veuilez entrer \'N\' pour lancer une nouvelle partie !\n");
		printf("Ou bien \'T\' pour le tutoriel !!\n");
		printf("Ou encore \'S\' pour la table des scores.\n");
		printf("Ou alors \'X\' pour quitter...\n");
		fflush(stdin);
		scanf("%c", &charUtilisateur);
		if(charUtilisateur == 'N'){
			printf("C\'est partie !! (appuyez sur entree pour continuer)\n");
			fflush(stdin);
			getchar();
			nJoueurVainqueur = mainGame();
			sauvegardeFichier(fichierScore, nJoueurVainqueur);
			printf("Fichier sauvegarde... (appuyez sur entree pour continuer)\n");
			fflush(stdin);
			getchar();
		}else if(charUtilisateur == 'T'){
			printf("Voila comment jouer... (appuyez sur entree pour continuer)\n");
			fflush(stdin);
			getchar();
		}else if(charUtilisateur == 'X'){
			booleen=1;
		}else if(charUtilisateur == 'S'){
			lectureFichier(fichierScore, nJoueurVainqueur);
			fflush(stdin);
			getchar();
		}else{
			printf("ohoh erreur ! On recommence !! (appuyez sur entree pour continuer)\n");
			fflush(stdin);
			getchar();
		}
	}while(booleen == 0);
	printf("Aurevoir =\'(\n");

	return 0;
}

void sauvegardeFichier(FILE *fichierScore, int n){
	fichierScore = fopen("saveScore.bin","wb");
	if(fichierScore != NULL){
		fwrite(&n, sizeof(int), 1, fichierScore);
		fclose(fichierScore);
	}
}

void lectureFichier(FILE *fichierScore, int n){
	printf("Voici le dernier joueur à avoir gagné : ");
	fichierScore = fopen("saveScore.bin","rb");
	if(fichierScore != NULL){
		fread(&n, sizeof(int), 1, fichierScore);
		fclose(fichierScore);
	}
	printf("%d", n);
}

int mainGame(){//Fonction qui traite le jeu. Elle retourne le numéro du vainqueur.
	int nBoolVictoire = 0, *Xcible, *Ycible, nTour=0, vainqueur;
	char charCible;
	system("cls");
	JOUEUR Joueur1, Joueur2;

	Joueur1.n_Joueur = 1;
	Joueur2.n_Joueur = 2;

	//Initialisation des tables des joueurs, et des points de vie de leurs bateaux.
	initPartie(Joueur1.tabJoueur, Joueur1.tabRadar, Joueur1.n_Joueur);
	Joueur1.flotteJoueur.pvPAvion = 5;
	Joueur1.flotteJoueur.pvCroiseur = 4;
	Joueur1.flotteJoueur.pvCTorpilleur1 = 3;
	Joueur1.flotteJoueur.pvCTorpilleur2 = 3;
	Joueur1.flotteJoueur.pvTorpilleur = 2;
	Joueur1.flotteJoueur.etat_Flotte = 5;
	initPartie(Joueur2.tabJoueur, Joueur2.tabRadar, Joueur2.n_Joueur);
	Joueur2.flotteJoueur.pvPAvion = 5;
	Joueur2.flotteJoueur.pvCroiseur = 4;
	Joueur2.flotteJoueur.pvCTorpilleur1 = 3;
	Joueur2.flotteJoueur.pvCTorpilleur2 = 3;
	Joueur2.flotteJoueur.pvTorpilleur = 2;
	Joueur2.flotteJoueur.etat_Flotte = 5;

	while (nBoolVictoire == 0){//Tant qu'aucun des deux joueurs n'a remporté la victoire.
		if(nTour%2 == 0){//Quand le nombre de tour est pair :
			//Tour Joueur 1.
			printf("Attention ! C'est au tour du joueur 1. Veuillez appuyer sur la touche \'entree\' quand vous etes pret.\n");
			fflush(stdin);
			getchar();
			system("cls");

			afficheTableauxJeu(Joueur1.tabJoueur, Joueur1.tabRadar, Joueur1.n_Joueur);

			//Demande à l'utilisateur d'entrer les coordonées de tire.
			cibleTir(&Xcible, &Ycible, Joueur1.tabRadar);

			//Verification raté/touché.
			charCible = verifToucher(Joueur1.tabRadar, Joueur2.tabJoueur, &Xcible, &Ycible);

			if(charCible != ' '){
				switch(charCible){
					case 'A':
						Joueur2.flotteJoueur.pvPAvion--;
						if(Joueur2.flotteJoueur.pvPAvion == 0){
							printf("Nous avons coule le porte-avion ennemi !\n");
							Joueur2.flotteJoueur.etat_Flotte--;
						}
						break;
					case 'K':
						Joueur2.flotteJoueur.pvCroiseur--;
						if(Joueur2.flotteJoueur.pvCroiseur == 0){
							printf("Nous avons coule le croiseur ennemi !\n");
							Joueur2.flotteJoueur.etat_Flotte--;
						}
						break;
					case 'C':
						Joueur2.flotteJoueur.pvCTorpilleur1--;
						if(Joueur2.flotteJoueur.pvCTorpilleur1 == 0){
							printf("Nous avons coule un contre-torpilleur ennemi !\n");
							Joueur2.flotteJoueur.etat_Flotte--;
						}
						break;
					case 'Q':
						Joueur2.flotteJoueur.pvCTorpilleur2--;
						if(Joueur2.flotteJoueur.pvCTorpilleur2 == 0){
							printf("Nous avons coule un contre-torpilleur ennemi !\n");
							Joueur2.flotteJoueur.etat_Flotte--;
						}
						break;
					case 'T':
						Joueur2.flotteJoueur.pvTorpilleur--;
						if(Joueur2.flotteJoueur.pvTorpilleur == 0){
							printf("Nous avons coule le torpilleur ennemi !\n");
							Joueur2.flotteJoueur.etat_Flotte--;
						}
						break;
				}//fin switch.
			}//fin if.
		}else{//Quand le nombre de tour est impair :
			//Tour Joueur 2.
			printf("Attention ! C'est au tour du joueur 2. Veuillez appuyer sur la touche \'entree\' quand vous etes pret.\n");
			fflush(stdin);
			getchar();
			system("cls");

			afficheTableauxJeu(Joueur2.tabJoueur, Joueur2.tabRadar, Joueur2.n_Joueur);

			//Demande à l'utilisateur d'entrer les coordonées de tire.
			cibleTir(&Xcible, &Ycible, Joueur2.tabRadar);

			//Verification raté/touché.
			charCible = verifToucher(Joueur2.tabRadar, Joueur1.tabJoueur, &Xcible, &Ycible);
			if(charCible != ' '){
				switch(charCible){
					case 'A':
						Joueur1.flotteJoueur.pvPAvion--;
						if(Joueur1.flotteJoueur.pvPAvion == 0){
							printf("Nous avons coule le porte-avion ennemi !\n");
							Joueur1.flotteJoueur.etat_Flotte--;
						}
						break;
					case 'K':
						Joueur1.flotteJoueur.pvCroiseur--;
						if(Joueur1.flotteJoueur.pvCroiseur == 0){
							printf("Nous avons coule le croiseur ennemi !\n");
							Joueur1.flotteJoueur.etat_Flotte--;
						}
						break;
					case 'C':
						Joueur1.flotteJoueur.pvCTorpilleur1--;
						if(Joueur1.flotteJoueur.pvCTorpilleur1 == 0){
							printf("Nous avons coule un contre-torpilleur ennemi !\n");
							Joueur1.flotteJoueur.etat_Flotte--;
						}
						break;
					case 'Q':
						Joueur1.flotteJoueur.pvCTorpilleur2--;
						if(Joueur1.flotteJoueur.pvCTorpilleur2 == 0){
							printf("Nous avons coule un contre-torpilleur ennemi !\n");
							Joueur1.flotteJoueur.etat_Flotte--;
						}
						break;
					case 'T':
						Joueur1.flotteJoueur.pvTorpilleur--;
						if(Joueur1.flotteJoueur.pvTorpilleur == 0){
							printf("Nous avons coule le torpilleur ennemi !\n");
							Joueur1.flotteJoueur.etat_Flotte--;
						}
						break;
				}//fin switch.
			}//fin if.
		}//fin if else.

		if(Joueur2.flotteJoueur.etat_Flotte <= 0){//Si le joueur 2 est à 0 PV
			printf("\nLe joueur 1 a gagne ! Bravo !\n");
			nBoolVictoire = 1;
			vainqueur = Joueur1.n_Joueur;
		}else if(Joueur1.flotteJoueur.etat_Flotte <= 0){//Si le joueur 1 est à 0 PV
			printf("\nLe joueur 2 a gagne ! Bravo !\n");
			nBoolVictoire = 1;
			vainqueur = Joueur2.n_Joueur;
		}else{
			printf("Are we good ? Appuyez sur la touche \'entree\' pour continuer\n");
			fflush(stdin);
			getchar();
			system("cls");
			nTour++;
		}
	}//fin while.
	return vainqueur;
}//fin mainGame.

void cibleTir(int *Xcible, int *Ycible, char radarAttaquant[TAILLE_Tab][TAILLE_Tab]){
	int b=0;
	while(b == 0){
		//fflush(stdin);
		printf("Veuillez entrer la coordonnee X de votre cible : ");
		scanf("%d", Xcible);
		while(*Xcible < 1 || *Xcible > 10){
			//fflush(stdin);
			printf("Veuillez entrer une coordonnee correcte pour votre X : ");
			scanf("%d", Xcible);
		}
		//fflush(stdin);
		printf("Veuillez entrer la coordonnee Y de votre cible : ");
		scanf("%d", Ycible);
		while(*Ycible < 1 || *Ycible > 10){
			//fflush(stdin);
			printf("Veuillez entrer une coordonnee correcte pour votre Y : ");
			scanf("%d", Ycible);
		}
		if(radarAttaquant[*Ycible-1][*Xcible-1] == 'X' || radarAttaquant[*Ycible-1][*Xcible-1] == 'O'){
			printf("Vous avez deja tire a ces coordonnees mon capitaine ! Veuillez trouver une autre cible... \n\n");
			b=0;
		}
		else{
			b=1;
		}
	}
}

void initTableauxJeu(char Tab1[TAILLE_Tab][TAILLE_Tab], char Tab2[TAILLE_Tab][TAILLE_Tab]){
	int i,j;
	for(i=0; i<TAILLE_Tab; i++){
		for(j=0; j<TAILLE_Tab; j++){
			Tab1[i][j] ='~';
		}
	}
	for(i=0; i<TAILLE_Tab; i++){
		for(j=0; j<TAILLE_Tab; j++){
			Tab2[i][j] ='~';
		}
	}
}

void initPartie(char TabJoueurX[TAILLE_Tab][TAILLE_Tab], char RadarJoueurX[TAILLE_Tab][TAILLE_Tab], int NumJoueur){
	int b=0;
	initTableauxJeu(TabJoueurX, RadarJoueurX); //Initialisation des tableaux du joueur X

	afficheTableauxJeu(TabJoueurX, RadarJoueurX, NumJoueur); //Affichage des tableaux du joueur X
	initBateaux(TabJoueurX, TAILLE_PAvion, b); //Placement du porte avion du joueur X
	system("cls");
	afficheTableauxJeu(TabJoueurX, RadarJoueurX, NumJoueur); //Affichage des tableaux du joueur X
	initBateaux(TabJoueurX, TAILLE_Croiseur, b); //Placement du croiseur du joueur X
	system("cls");
	afficheTableauxJeu(TabJoueurX, RadarJoueurX, NumJoueur); //Affichage des tableaux du joueur X
	initBateaux(TabJoueurX, TAILLE_CTorpilleur, b); //Placement du contre-torpilleur du joueur X
	system("cls");
	afficheTableauxJeu(TabJoueurX, RadarJoueurX, NumJoueur); //Affichage des tableaux du joueur X
	b=1;
	initBateaux(TabJoueurX, TAILLE_CTorpilleur, b); //Placement du second contre-torpilleur du joueur X
	system("cls");
	afficheTableauxJeu(TabJoueurX, RadarJoueurX, NumJoueur); //Affichage des tableaux du joueur X
	initBateaux(TabJoueurX, TAILLE_Torpilleur, b); //Placement du torpilleur du joueur X
	system("cls");
	afficheTableauxJeu(TabJoueurX, RadarJoueurX, NumJoueur); //Affichage des tableaux du joueur X

	printf("Appuyez sur la touche \'entree\' pour continuer\n");
	fflush(stdin);
	getchar();
	system("cls");
}

void afficheTableauxJeu(char Tab1[TAILLE_Tab][TAILLE_Tab], char Tab2[TAILLE_Tab][TAILLE_Tab], int NumJoueur){
	int i,j;
	printf("Tableau du joueur numero %d : \n", NumJoueur);
	printf(" 1 2 3 4 5 6 7 8 9 10\n");
	printf("_____________________\n");
	for(i=0; i<TAILLE_Tab; i++){
		for(j=0; j<TAILLE_Tab; j++){
			printf(" %c", Tab1[i][j]);
		}
		printf(" | %d\n", i+1);
	}
	printf("\n\n\n");

	printf("Radar du joueur numero %d : \n", NumJoueur);
	printf(" 1 2 3 4 5 6 7 8 9 10\n");
	printf("_____________________\n");
	for(i=0; i<TAILLE_Tab; i++){
		for(j=0; j<TAILLE_Tab; j++){
			printf(" %c", Tab2[i][j]);
		}
		printf(" | %d\n", i+1);
	}
	printf("\n\n\n");
}

void initBateaux(char Tab1[TAILLE_Tab][TAILLE_Tab], int TailleBateau, int b){
	int X,Y;
	int IsOOOOR=1; //Il s'agit d'une variable qui indique si le bateau est en dehors du tableau, ou qu'il enmpiete sur un autre. "IsOOOOR" signifie : "Is Overlapping Or Out Of Range".
	char direction;

	while(IsOOOOR != 0){
		//Demande les coordonnées X et Y pour le bateau.
		fflush(stdin);
		printf("Veuillez entrer la coordonnee X de votre bateau a %d cases : ", TailleBateau);
		scanf("%d", &X);
		while(X < 1 || X > 10){
			fflush(stdin);
			printf("Veuillez entrer des coordonnees valides X : ");
			scanf("%d", &X);
		}
		fflush(stdin);
		printf("Veuillez entrer la coordonnee Y de votre bateau a %d cases : ", TailleBateau);
		scanf("%d", &Y);
		while(Y < 1 || Y > 10){
			fflush(stdin);
			printf("Veuillez entrer des coordonnees valides Y : ");
			scanf("%d", &Y);
		}

		//Demande de la direction du bateau au joueur.
		fflush(stdin);
		printf("Veuillez choisir la direction (\'H\' pour horizontale ; \'V\' pour verticale ; \'D\' pour diagonale) : ");
		scanf("%c", &direction);
		while((direction != 'H') && (direction != 'V') && (direction != 'D')){
			fflush(stdin);
			printf("Veuillez choisir une direction correcte (\'H\' pour horizontale ; \'V\' pour verticale ; \'D\' pour diagonale) : ");
			scanf("%c", &direction);
		}

		//Verification si le bateau n'empiète pas sur un autre.
		IsOOOOR = verifDirectionBateau(Tab1, direction, TailleBateau, X, Y);
	}

	directionBateaux(Tab1, direction, TailleBateau, X, Y, b);
}

void directionBateaux(char Tableau[TAILLE_Tab][TAILLE_Tab], char direction, int TailleBateau, int X, int Y, int b){
//Fonction qui prends en paramètres un tableau à remplir, une taille de bateau, et des coordonnées.
//Cette fonction rempli un tableau d'une bateau de taille Z, aux coordonnées (X,Y).
	int i;
	char charPrint;
	switch(TailleBateau){
		case 5:
			charPrint = 'A';
			break;
		case 4:
			charPrint = 'K';
			break;
		case 3:
			if(b==1){
				charPrint = 'Q';
			}else{
				charPrint = 'C';
			}
			break;
		case 2:
			charPrint = 'T';
			break;
	}
	if(direction == 'H'){
		for(i=0; i<TailleBateau; i++){
			Tableau[Y-1][X-1] = charPrint;
			X++;
		}
	}else if(direction == 'V'){
		for(i=0; i<TailleBateau; i++){
			Tableau[Y-1][X-1] = charPrint;
			Y++;
		}
	}else if(direction == 'D'){
		for(i=0; i<TailleBateau; i++){
			Tableau[Y-1][X-1] = charPrint;
			Y++;
			X++;
		}
	}
}

char verifToucher(char radarAttaquant[TAILLE_Tab][TAILLE_Tab], char tabDefenseur[TAILLE_Tab][TAILLE_Tab], int *Xcible, int *Ycible){
	char c;
	if(tabDefenseur[*Ycible-1][*Xcible-1] != '~'){
		printf("TOUCHE !!\n");
		c = tabDefenseur[*Ycible-1][*Xcible-1];
		tabDefenseur[*Ycible-1][*Xcible-1] = 'X';
		radarAttaquant[*Ycible-1][*Xcible-1] = 'X';
	}else{
		printf("Rate...\n");
		c = ' ';
		radarAttaquant[*Ycible-1][*Xcible-1] = 'O';
	}
	return c;
}

int verifDirectionBateau(char Tableau[TAILLE_Tab][TAILLE_Tab], char direction, int TailleBateau, int X, int Y){
	int i=0, b=0;
	if(direction == 'H'){
		while((b==0) && (i<TailleBateau)){
			if(X>10){
				b=2;
			}
			else if(Tableau[Y-1][X-1] != '~'){
				b=1;
			}
			i++;
			X++;
		}
	}else if(direction == 'V'){
		while((b==0) && (i<TailleBateau)){
			if(Y>10){
				b=2;
			}else if(Tableau[Y-1][X-1] != '~'){
				b=1;
			}
			i++;
			Y++;
		}
	}else if(direction == 'D'){
		while((b==0) && (i<TailleBateau)){
			if(X>10 || Y>10){
				b=2;
			}else if(Tableau[Y-1][X-1] != '~'){
				b=1;
			}
			i++;
			Y++;
			X++;
		}
	}
	if(b==1){
		printf("ATTENTION ! Votre bateau empiete sur un autre ! Veuillez reessayer s\'il vous plait\n");
	}else if(b==2){
		printf("ATTENTION ! Votre bateau sort de la zone de jeu ! Veuillez reessayer s\'il vous plait\n");
	}
	return b;
}
