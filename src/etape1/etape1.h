#ifndef ETAPE_1
#define ETAPE_1
#include <stdio.h>
#include <stdlib.h>
#include "../../lib/list_hach.h"
#include "../../lib/fileTreatment.h"
#define MAXLIGNE 400
//#define tailleTableau 500

FILE* file_open(char* s);


void traitement_ligne(FILE* filep, char tab[][MAXLIGNE]);

int commentaire_fichier(FILE* filep); // calcul le nbr de commentaire d'un fichier

//TableHachage table_score(FILE* filep);

void remplissage(char* s, TableHachage t,int temp);
TableHachage gestion(FILE* filep);
ELEMENT element_creer(ELEMENT elm,char* s,int temp,int n);
char* saisie();
void fsaisie();


double evaluer_bis(TableHachage t, int nbl, float f);
void evaluer(TableHachage t, int nbl, float f);
//void evaluer(TableHachage t);
void evaluer2(TableHachage t);
void evaluer3(TableHachage t);
void menu();
void sous_menu();
void sous_menu_stats();
void menu_stats(TableHachage t);


// ####### partie testing ############

// fonction à intégrer dans le menu, propose de faire des tests sur une base de données
void testing();
// fonction qui renvoie l'eqm en utilisant la fonction evaluer
//elle s'entraine sur fa et s'exécute sur fb 
//ps: fa et fb sont des bases de données formatés
double eqm(char* fa, char* fb);




void viderBuffer();


ELEMENT* freq(TableHachage t, int n);
int motsDif(TableHachage t, int d);
void repartition(TableHachage t, int n);
ELEMENT* motsPos(TableHachage t, int n);
ELEMENT* motsNeg(TableHachage t, int n);
float moyenne(TableHachage t);
int maxTab2(ELEMENT* tab, int n);
int minTab2(ELEMENT* tab, int n);


#endif
