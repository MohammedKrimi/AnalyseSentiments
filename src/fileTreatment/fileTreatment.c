#include "fileTreatment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define del "., !?'\n`-;\\/	"
#define MAXLIGNE 400
#define separator "."
#define new_file "traited.txt"
#define fileA "fileA.txt"
#define fileB "fileB.txt"


FILE *file_open_treatment(char* s,const char* modeOuverture){
	//"r" = Mode lecture 
	//"w+" = Mode lecture/ecriture avec suppression prealable	
	FILE* filep = NULL; //Déclarer un pointeur sur lr fichier des données
	filep = fopen(s,modeOuverture); //Ouvrir le fichier en Mode "r" = Mode lecture 	
       	if (filep == NULL) /*Tester si l'ouverture du fichier s'est effectuée correctement ou pas*/
	{
		printf("Impossible d'ouvrir le fichier\n");
		return NULL;
	}
	else 
	{
		return filep;
	}	
	return 0;	
}

// La fonction qui permet de printer un fichier
void visualiser_fichier_treatment(FILE* filep){
	char* chaine = malloc(sizeof(char)*MAXLIGNE);
	while( fgets(chaine,MAXLIGNE,filep) != NULL)
	{
		printf("%s",chaine);
	}
	rewind(filep);
}

// fonction qui sépare un texte en 2 fragments
// le premer contien n lignes, le 2° le reste
// on appele fileA et fileB les 2 nouveaux fichiers

void split(char* s, int nb)
{
	FILE* file_source = file_open_treatment(s,"r");
	FILE* file_first = file_open_treatment(fileA,"w+");
	FILE* file_scnd = file_open_treatment(fileB, "w+");
	int i = 1;

	char* chaine = malloc(sizeof(char)*MAXLIGNE);
	while( fgets(chaine,MAXLIGNE,file_source) != NULL)
	{
		//strcat(chaine,"\n");
		
		if( i <= nb)
		{
			fputs(chaine,file_first);
		} else {
			fputs(chaine,file_scnd);
		}
		i++;
	}
	fclose(file_first);
	fclose(file_scnd);
	fclose(file_source);


}




//transfrome le fichier en un autre traité comme il faut
void file_treatment(char*s)
{
	FILE* file_source=file_open_treatment(s,"r"); //on ouvre en lecture seulement

	FILE* file_target=file_open_treatment(new_file,"w+"); //on veut écrire dedans en supprimant ce qu'il y'avait avant

	char * chaine = malloc(sizeof(char)*MAXLIGNE);
	while( fgets(chaine,MAXLIGNE,file_source) != NULL)
	{
		casse(chaine);
		
		char* nv_chaine = malloc(sizeof(char) * MAXLIGNE);
		char* token = strtok(chaine,del);

		while( token != NULL)
		{
			nv_chaine = strcat(nv_chaine, separator);
			nv_chaine = strcat(nv_chaine, token);
			token = strtok(NULL,del);
		}
		strcat(nv_chaine,"\n");
		strcpy(chaine,nv_chaine);
		fputs(chaine,file_target);
	}
	fclose(file_source);
	fclose(file_target);
}

//la fonction qui passe un mot en majuscule (plus de casse)
void casse(char* ligne)
{
	for (int i = 0; ligne[i]!='\0'; i++) 
	{
	// si les caractères sont en minuscules, convertissez-les en majuscules 
	// en soustrayant 32 de leur valeur ASCII.
 		if(ligne[i] >= 'a' && ligne[i] <= 'z')
	       	{
		    ligne[i]=ligne[i]-32;
		}
	}
}
// la fonction qui s'occupe d'éliminer la casse,
// d'enelever les n't et les 's
//
/*
char* ligne_treatment(const char* ligne)
{
	char *TxtRetour;
	int TailleAlloue = strlen(ligne);
	TxtRetour = malloc(sizeof(char)*TailleAlloue);

	//TxtRetour = str_replace(ligne,"n't","not");
	//TxtRetour = str_replace(TxtRetour,"'s",".");
	strcpy(TxtRetour, ligne);
	char *nouvelle_ligne;
	nouvelle_ligne = malloc(sizeof(char)*TailleAlloue);


	char *token = strtok(TxtRetour,del);
	while( token != NULL)
	{		
		nouvelle_ligne = strcat(nouvelle_ligne,separator);
		token = casse(token);
		nouvelle_ligne = strcat(nouvelle_ligne,token);
		token = strtok(NULL, del);
	}
	strcat(nouvelle_ligne,separator);
	strcpy( nouvelle_ligne, str_replace(nouvelle_ligne, "^M", "."));
	return nouvelle_ligne;
}

*/
//la fonction qui permet de remplacer un pattern "avant" par un paterne "apres" dans une ligne
char* str_replace (const char* txt, const char* Avant, const char* Apres)
{
	const char* pos;           // Position d'une occurance de Avant dans txt
	char* TxtRetour;           // La chaine retournée
	int PosTxtRetour;       // Position du prochain caractère à écrire dans TxtRetour
	int Long;               // Long d'une chaine à écrire dans TxtRetour
	int TailleAllouee;      // Taille allouée à TxtRetour
	

	// Cherche la première occurancce
	pos = strstr (txt,Avant);

	// Aucune occurance : renvoie simplement une copie de la chaine
	if (pos == NULL){
	 	TailleAllouee = strlen(txt);
		TxtRetour = malloc(sizeof(char)*TailleAllouee);
		TxtRetour = strcpy(TxtRetour, txt);
		return TxtRetour;

	}
	//alloue une nouvelle chaine
	Long = (size_t)pos -(size_t)txt;
	TailleAllouee = Long +strlen(Apres)+1;	   
	TxtRetour = malloc(sizeof(char)*TailleAllouee);      
	PosTxtRetour = 0;

	//copie de la 1° partie de la chaine 
	strncpy (TxtRetour+PosTxtRetour,txt,Long);
       	PosTxtRetour += Long;	
      	txt = pos+strlen(Avant);
	
	//ajout la chaine de remplacement apres
	Long = strlen(Apres);	
      	strncpy (TxtRetour+PosTxtRetour,Apres,Long); PosTxtRetour += Long;

	// Cherche la prochaine occurance
	pos = strstr (txt,Avant);
	while (pos != NULL)	
       	{
		//agrandit la chaine
		Long = (size_t)pos -(size_t)txt;
	     	TailleAllouee += Long+strlen(Apres);	
		TxtRetour = (char *)realloc(TxtRetour,TailleAllouee);

		// Copie ce qu'il y a entre la dernier occurance et la nouvelle
		strncpy (TxtRetour+PosTxtRetour,txt,Long); PosTxtRetour += Long;      
		
		// Passe l'occurance
		txt = pos+strlen(Avant);
		              
		// Ajoute la chaîne de remplacement
		Long = strlen(Apres);
		strncpy (TxtRetour+PosTxtRetour,Apres,Long); PosTxtRetour += Long;
		                         
		// Cherche la prochaine occurance
		pos = strstr (txt,Avant);

	}
	
	//ajout le reste de la chaine
	Long = strlen(txt)+1;
	TailleAllouee += Long;
	TxtRetour = (char*)realloc(TxtRetour,TailleAllouee);
	strncpy (TxtRetour+PosTxtRetour,txt,Long);
	return TxtRetour;
}
		
		

