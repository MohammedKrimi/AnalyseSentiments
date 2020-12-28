#include<stdio.h>
#include<stdlib.h>

char* saisie(){
	//permet de stocker un commentaire saisi par l'utilisateur dans une variable
	char* commentaire = malloc(301*sizeof(char));
	printf("Veuillez saisir un commentaire (300 caractères max.)\n");
	fgets(commentaire, 301, stdin);
	printf("Votre commentaire :\n%s\n", commentaire);
	return commentaire;
}

void fsaisie(){
	//permet de stocker un comentaire saisi par l'utilisateur dans un fichier commentaire.txt
	char* commentaire = malloc(301*sizeof(char));
	printf("Veuillez saisir un commentaire (300 caractères max.)\n");
	fgets(commentaire, 301, stdin);
    FILE* fichier = NULL;
    fichier = fopen("../data/commentaire.txt", "w");
    if (fichier != NULL){
    	fputs(commentaire, fichier);
        fclose(fichier);
    }
    else
    	printf("erreur lors de l'ouverture du fichier\n");
}
