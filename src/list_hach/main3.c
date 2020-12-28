#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list_hach.h"
#define TAILLE_MAX 1000
#define TAILLE_TAB 500
#define marqueur_fin "FIN"




int main(int argc,char* argv[])
{
	char chaine[TAILLE_MAX]="1 While The Importance of Being Earnest offers opportunities for occasional smiles and chuckles , it does n't give us a reason to be in the theater beyond Wilde 's wit and the actors ' performances . ";

	char *tab[TAILLE_MAX];
	traitement_ligne(chaine,tab);

	TableHachage ma_table= tableHachage_creer(TAILLE_TAB);
	
	  int n = 0;
	  char *mot="";
	  mot = tab[n];
	  int note = atoi(mot);
	  int unitaire = 1;
	  printf("ma note vaut: %i\n",note);
	  n=1;
	  mot=tab[n];
	  while(strcmp(mot,marqueur_fin) != 0)
	  {
		  ELEMENT ge = malloc(sizeof(ge));		  
		  ge=tableHachage_get(mot,ma_table);
		  if( ge == NULL) // le mot n'est pas encore présent dans la table, faut le rajouter
		  {		
			  ELEMENT e = malloc(sizeof(ELEMENT));
			  (*e).key=mot;		  
			  (*e).sum = note;
			  (*e).nb = unitaire;
			  tableHachage_ajout(e,ma_table);
		  } else {   // le mot est déjà la, faut faire les modif
			(*ge).sum = (*ge).sum + note;
		  	(*ge).nb= (*ge).nb + unitaire;
		  }
		 n++;
		 mot=tab[n];
	}

	tableHachage_visualiser(ma_table);
	return 0;
}
