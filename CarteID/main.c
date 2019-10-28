#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TAILLENOM 100
#define TAILLEPRENOM 100
#define TAILLEADRESSE 255
#define TAILLECP 10
#define TAILLEVILLE 100
#define TAILLECONTINUE 100

int main()
{
    static int nID=0;
    char cNom[TAILLENOM], cPrenom[TAILLEPRENOM], cAdresse[TAILLEADRESSE], cCP[TAILLECP], cVille[TAILLEVILLE];
    const char finDeSaisie='n';
    char cContinue[TAILLECONTINUE];

    do{
    	//Saisie
    	printf("Programme carte ID\n");
    	printf("Saisir nom\n");
    	fgets(cNom,TAILLENOM,stdin);
    	fflush(stdin);
    	printf("Saisir prenom\n");
    	fgets(cPrenom,TAILLEPRENOM,stdin);
    	fflush(stdin);
    	printf("Saisir adresse\n");
    	fgets(cAdresse,TAILLEADRESSE,stdin);
    	fflush(stdin);
    	printf("Saisir Cp\n");
    	scanf("%5s",cCP); //Ne sera saisie que les 5 premier caractères saisies dans le flux (Masque de saisie)
    	fflush(stdin);
    	printf("Saisir ville\n");
    	fgets(cVille,TAILLEVILLE,stdin);
    	fflush(stdin);
    	++nID;

    	//Affichage
    	printf("ID : %d\n",nID);
    	printf("Nom : %s",cNom);
    	printf("prenom : %s",cPrenom);
    	printf("Adresse : %s",cAdresse);
    	printf("Ville : %s",cVille);
    	printf("CP : %s\n",cCP);

    	do{
    		printf("Saisir une autre carte o/n ?\n");
    		scanf("%s",cContinue);
    		fflush(stdin);
    	}while(strcmp(cContinue,"o") && strcmp(cContinue,"n"));
    }while(finDeSaisie!=cContinue[0]);

    return 0;
}
