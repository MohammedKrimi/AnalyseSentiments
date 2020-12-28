#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list_hach.h"


int main(int argc,char* argv[])
{	
	/*
	ELEMENT e=malloc(sizeof(ELEMENT));
	char *mot="bonjour";*/
	int a = 1;
	int b =2;/*
	(*e).key =mot;
	(*e).sum =a;
	(*e).nb =b;
	//list_affiche(e);

	Liste ma_liste=malloc(sizeof(Liste));
	ma_liste= list_creer();
	
	ma_liste=list_ajoutTete(ma_liste,e);
	//list_visualiser(ma_liste);
	*/	
	char *mot1="bisous";
	char *mot2="nounours";
	char *mot3="caca";
	char *mot4="biensur";
	char *mot5="fjeifie";
		
	ELEMENT e1= malloc(sizeof(ELEMENT));
	ELEMENT e2=malloc(sizeof(ELEMENT));
	ELEMENT e3=malloc(sizeof(ELEMENT));
	ELEMENT e4=malloc(sizeof(ELEMENT));
	ELEMENT e5=malloc(sizeof(ELEMENT));

	(*e1).key=mot1;
	(*e2).key=mot2; 
	(*e3).key=mot3; 
	(*e4).key=mot4; 
	(*e5).key=mot5; 
	
	(*e1).sum=a;
	(*e2).sum=a;  
	//(*e3).sum=a;  
	(*e4).sum=a;  
	(*e5).sum=a;  
	(*e1).nb=b;
	(*e2).nb=b; 
	//(*e3).nb=b; 
	(*e4).nb=b; 
	(*e5).nb=b; 
	

	TableHachage ma_table = tableHachage_creer(10);

	tableHachage_ajout(e1,ma_table);
	tableHachage_ajout(e2,ma_table); 
	tableHachage_ajout(e3,ma_table); 
	tableHachage_ajout(e4,ma_table); 
	tableHachage_ajout(e5,ma_table); 
	tableHachage_visualiser(ma_table);


	/*
	ma_liste=list_ajoutTete(ma_liste,e1);
	ma_liste=list_ajoutTete(ma_liste,e2);   
	ma_liste=list_ajoutTete(ma_liste,e3);   
	ma_liste=list_ajoutTete(ma_liste,e4);   
	ma_liste=list_ajoutTete(ma_liste,e5);   

	list_visualiser(ma_liste);

	ELEMENT get= malloc(sizeof(ELEMENT));
	get=list_rech(ma_liste,mot3);
	list_affiche(get);
	
	get=list_rech(ma_liste,"zad");
	printf("\n%p",get);
	*/
	return 0;
}
