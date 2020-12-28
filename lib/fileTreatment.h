#ifndef FILETREATMENT
#define FILETREATMENT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//pour ouvrir un fichier
FILE *file_open_treatment(char* s,const char* modeOuverture);
//pour visualiser un fichier
void visualiser_fichier_treatment(FILE* filep);
// la fonction qui s'occupe de faire les changement qu'il faut dans ligne
char* ligne_treatment(const char* ligne);
// remplce dans txt les patternes Avant par Apres
char* str_replace(const char* txt,const char* Avant,const char* Apres);
// la fonction qui passe un mot en majuscule (regle le probleme de la casse)
char* casse(const char* mot); 
// fonction qui va réecrire un fichier en :
// - passant tout en majuscule
// - enlevant les 's 
// - remplacant n't par not
// dans le dossier courant 
// le fichier s'appellera traited.txt
void file_treatment(char *s);
// fonction qui permet de spliter un document
// en deux documents:
// le premier contient n lignes
// le deuxième contient le reste
void split(char* s, int nb);

#endif 
