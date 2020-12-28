#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_hach.h"

//#################################################################################
// Listes
//#####################################################################################

Liste list_creer(void)
{
	Liste ma_liste=malloc(sizeof(Liste));
	(*ma_liste).elm=NULL;
	(*ma_liste).suiv=NULL;
	return ma_liste;
}

int list_estVide(Liste L)
{
	if(L==NULL){ exit(EXIT_FAILURE);}
	if( (*L).elm==NULL && (*L).suiv==NULL){ return 1;} //c'est vide
	return 0;
}

Liste list_ajoutTete(Liste L,ELEMENT e){
	cellule *cel_tete=malloc(sizeof(*cel_tete));
	(*cel_tete).elm=e;
	(*cel_tete).suiv=NULL;
	if(list_estVide(L)) 
	{
	L=cel_tete; 
	} else 
	{	
		cellule *cel_i=malloc(sizeof(*cel_i));									      cel_i=L;
		while( (*cel_i).suiv != NULL)
		{
			cel_i=(*cel_i).suiv;	
		}
		(*cel_i).suiv=cel_tete;
	}	
	return L;
}

void list_ajoutFin(Liste L, ELEMENT e){
	if(list_estVide(L)){
		L->elm = e;
	}
	else {
		cellule* cel = malloc(sizeof(cellule));
		cel->elm = e;
		cel->suiv = NULL;

		cellule* celp = L;
		while (celp->suiv != NULL){
			celp = celp->suiv;
		}

		celp->suiv = cel;
	}
}

ELEMENT list_rech(Liste L, char* s){

	ELEMENT e =NULL;
	if(list_estVide(L)){return e;}
	
	cellule *cel_i=malloc(sizeof(*cel_i));
	cel_i=L;

	while(cel_i!=NULL)
	{
		char *ki="";
		ki=  ( * (*cel_i).elm).key; 
 		if(strcmp(ki,s)==0) 
		{
			   return (*cel_i).elm;
		}						 
	 cel_i=(*cel_i).suiv;
	 }
return e;
}

void list_incrementation(Liste L,Clef c,int temp) {
	while (strcmp(L->elm->key,c)!=0) {
		L = L->suiv;
	}
	L->elm->sum += temp;
	L->elm->nb++;
}



void list_affiche(ELEMENT e)
{
	printf("(%s",(*e).key);
	printf(",%i",(*e).sum);
	printf(",%i)",(*e).nb);
	printf("\n");
}

void list_visualiser(Liste L)
{
	ELEMENT e = malloc(sizeof(ELEMENT));
	if( list_estVide(L)){ printf("VIDE"); }
	else
	{
		e= (*L).elm;
		cellule* sv = malloc(sizeof(sv));
		sv=(*L).suiv;
		list_affiche(e);	
		while( sv != NULL)
		{
			printf("-->");
			e=(*sv).elm;
			if( e == NULL) { printf("EXCEPTION:list_visualiser"); exit(EXIT_FAILURE);}
			list_affiche(e);
			sv = (*sv).suiv;
		}

	}
}




int hachage(char *s, int mod)
{
	int i = 0, cpt = 0;
	    while (s[i] != '\0')	     
	    {			
	    	    cpt += (int)s[i];
		    i++;				
	    }    
	    cpt += strlen(s);	
	    cpt = cpt % mod;	        
	    return cpt;
}
//################################################################################
// Tables 
//####################################################################################

TableHachage tableHachage_creer(int tailleTableau)
{
	TableHachage ma_table = malloc(sizeof(ma_table));        
	if( ma_table == NULL){ exit(EXIT_FAILURE);}
       	(*ma_table).tableauListe = malloc( sizeof(Liste) * tailleTableau);
	//on check que tous ce passe bien 
	if( (*ma_table).tableauListe == NULL){exit(EXIT_FAILURE);}                
	for(int i = 0; i<tailleTableau; i++)                        
	{         
		(*ma_table).tableauListe[i]=list_creer();
	}
	(*ma_table).tailleTableau=tailleTableau;        
	return ma_table;
}

	
void tableHachage_ajout(ELEMENT e, TableHachage t)
{
	
	int hashcode = hachage( (*e).key, (*t).tailleTableau );
	list_ajoutFin( (*t).tableauListe[hashcode],e );

}



ELEMENT tableHachage_get(Clef c, TableHachage t){
	int hashcode = hachage(c,t->tailleTableau);
	return list_rech(t->tableauListe[hashcode], c);
}


void tableHachage_incrementation(TableHachage t, Clef c, int temp) {
	int hashcode = hachage(c,t->tailleTableau);
	list_incrementation(t->tableauListe[hashcode],c,temp);
}

void tableHachage_visualiser(TableHachage t)
{	
	for(int i = 0; i < (*t).tailleTableau; i++)
	{
		
		Liste ma_liste=malloc(sizeof(Liste));
		printf("\n###########");

		ma_liste =(*t).tableauListe[i];

		list_visualiser(ma_liste);
		
	}
}
