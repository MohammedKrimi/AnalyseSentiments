#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list_hach.h"


int main(int argc,char* argv[])
{
	char *mot1="mot1";
	    	char *mot2="ezadmzad";
	char *mot3="mzadzada";
	char *mot4="modqqzdt1";
	char *mot5="motqdzqdzdz1";
	char *mot6="mccdjot1";
	char *mot7="mot1dsqmdlq";
	char *mot8="mot1dzdqzdqz";
	char *mot9="motcscs1";
	char *mot10="motahiujop1";
	char *mot11="motvbcnx1";
	char *mot12="motytrueizo1";
	char *mot13="motpamqsldk1";
	char *mot14="motbvneh1";
	char *mot15="mot1zaeozaie";
ELEMENT e1= malloc(sizeof(ELEMENT));
ELEMENT e2=malloc(sizeof(ELEMENT));
ELEMENT e3=malloc(sizeof(ELEMENT));
ELEMENT e4=malloc(sizeof(ELEMENT));
ELEMENT e5=malloc(sizeof(ELEMENT));
ELEMENT e6= malloc(sizeof(ELEMENT));
ELEMENT e7=malloc(sizeof(ELEMENT));
ELEMENT e8=malloc(sizeof(ELEMENT));
ELEMENT e9=malloc(sizeof(ELEMENT));
ELEMENT e10=malloc(sizeof(ELEMENT));
ELEMENT e11= malloc(sizeof(ELEMENT));
ELEMENT e12=malloc(sizeof(ELEMENT));
ELEMENT e13=malloc(sizeof(ELEMENT));								        
ELEMENT e14=malloc(sizeof(ELEMENT));
ELEMENT e15=malloc(sizeof(ELEMENT));
(*e1).key=mot1;
(*e2).key=mot2;
(*e3).key=mot3;
(*e4).key=mot4;
(*e5).key=mot5;
(*e6).key=mot6;
(*e7).key=mot7;
(*e8).key=mot8;
(*e9).key=mot9;
(*e10).key=mot10;
(*e11).key=mot11;
(*e12).key=mot12;
(*e13).key=mot13;
(*e14).key=mot14;
(*e15).key=mot15;
	


	TableHachage ma_table = malloc(sizeof(ma_table));
	ma_table=tableHachage_creer(10);

	tableHachage_ajout(e1,ma_table);
	tableHachage_ajout(e2,ma_table);
	tableHachage_ajout(e3,ma_table);
	tableHachage_ajout(e4,ma_table);
	tableHachage_ajout(e5,ma_table);
	tableHachage_ajout(e6,ma_table);
	tableHachage_ajout(e7,ma_table);
	tableHachage_ajout(e8,ma_table);
	tableHachage_ajout(e9,ma_table);
	tableHachage_ajout(e10,ma_table);
	tableHachage_ajout(e11,ma_table);
	tableHachage_ajout(e12,ma_table);
	tableHachage_ajout(e13,ma_table);
	tableHachage_ajout(e14,ma_table);
	tableHachage_ajout(e15,ma_table);

	tableHachage_visualiser(ma_table);

	ELEMENT get1 = malloc(sizeof(ELEMENT));
	ELEMENT get2 = malloc(sizeof(ELEMENT));

	printf("\n\n\n");

	get1= tableHachage_get( mot4,ma_table  );
	get2=tableHachage_get( mot15,ma_table  );
	list_affiche(get1);
	list_affiche(get2);

	/*
	Liste ma_liste=list_creer();
	list_ajoutFin( ma_liste, e1);
	list_ajoutFin( ma_liste, e2); 
	list_ajoutFin( ma_liste, e3); 
	list_ajoutFin( ma_liste, e4); 
	list_ajoutFin( ma_liste, e5); 
	list_ajoutFin( ma_liste, e6); 
	list_ajoutFin( ma_liste, e7); 
	list_ajoutFin( ma_liste, e8); 
	list_ajoutFin( ma_liste, e9); 
	list_ajoutFin( ma_liste, e10); 
	list_ajoutFin( ma_liste, e11); 
	list_ajoutFin( ma_liste, e12); 
	list_ajoutFin( ma_liste, e13); 
	list_ajoutFin( ma_liste, e14); 
	list_ajoutFin( ma_liste, e15); 
	list_visualiser(ma_liste);
	*/


	return 0;
}
