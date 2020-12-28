#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "etape1.h"
#include <ctype.h>
#define TAILLE_MAX 500 // la taille de notre table de hachage
#define MAXLIGNE 400 // le nbr max de caractere par commentaire 
#define new_file "traited.txt"
#define del "., !?'\n`-;\\/	"
#define fileA "fileA.txt"
#define fileB "fileB.txt"
#define fileComm "../../data/commentaire.txt" // le path vers un commentaire à évaluer 
#define fileData "../../data/movie_reviews.txt" // le path vers le fichier data
#define square(a)  (a)*(a)



/*############## Fonction permettant d'ouvrir le fichier ##############*/
FILE* file_open(char* s) {
	FILE* filep = NULL; //Déclarer un pointeur sur lr fichier des données
	filep = fopen(s,"r"); //Ouvrir le fichier en Mode "r" = Mode lecture
	if (filep == NULL) /*Tester si l'ouverture du fichier s'est effectuée correctement ou pas*/
	{
		printf("Impossible d'ouvrir le fichier\n");
		return NULL;
	}
	else {
		//printf("Le fichier est ouvert correctement\n");
		return filep;
	}
	return 0;
}
/*############## Fonction permettant de visualiser le fichier ##############*/
void visualiser_fichier(FILE* filep){
	
	char* chaine = malloc(sizeof(char)*MAXLIGNE);
	while( fgets(chaine,MAXLIGNE,filep) != NULL)
	{
		printf("%s",chaine);
	}
	rewind(filep);

}
/*############## Fonction permettant d'ajouter (ou incrémenter) ##############*/
void remplissage(char* s, TableHachage t,int temp) {
	ELEMENT elm = malloc(sizeof(struct ELEMENT)); // allocation de la mémoire pour un element
	if (elm != NULL) 
	{
		if (tableHachage_get(s,t) == NULL) // si l'élément n'est pas dans la table : on l'ajoute
		{	
			elm->key = s; elm->sum = temp; elm->nb = 1;
			tableHachage_ajout(elm,t);
			
		}
		else { //sinon on incrémente sum avec la note du commentaire et nb avec 1
			tableHachage_incrementation(t,s,temp);
		}
	}

}
/*############## Fonction permettant le calcul de nombre de commentaire d'un fichier ##############*/
int commentaire_fichier(FILE* filep) {
	int count = 0;
	char* chaine = malloc(sizeof(char)*MAXLIGNE);
	while( !feof(filep))
	{
		count++;
		fgets(chaine,MAXLIGNE,filep);
	}
	rewind(filep);
	return count-1;
}
/*############## Fonction permettant de stocker chaque ligne du fichier dans une case du tableau ##############*/
void traitement_ligne(FILE* filep, char tab[][MAXLIGNE])
{
	int nombre_commentaire = commentaire_fichier(filep); //printf("%d\n", nombre_commentaire);
	char* chaine = malloc(sizeof(char)*MAXLIGNE); // allocation de la mémoire pour un pointeur sur une chaine de caractère
	for (int i = 0; i < nombre_commentaire ; i++) // en parcourant tous le fichier ligne par ligne, on stocke chaque ligne dans une case du tableau 
	{
		fgets(chaine,MAXLIGNE,filep); //récupérer la ligne
		strcpy(tab[i],chaine); //copier la ligne dans le tableau 
	} 
}

/*############## Fonction permettant de remplir toute la table à partir du fichier ##############*/
TableHachage gestion(FILE* filep) {
	TableHachage mots_score = tableHachage_creer(TAILLE_MAX);
	int nombre_commentaire = commentaire_fichier(filep); //créer la table de hachage
	char tab[nombre_commentaire][MAXLIGNE]; 
	traitement_ligne(filep,tab); //remplir le tableau avec les commentaire un par un
	rewind(filep); //remettre le curseur au début
	double temp;
	for(int i=0;i<nombre_commentaire;i++) { // on parcourt tous le tableau
		char* ligne = tab[i]; //on stocke la case i dans un pointeur sur une chaine de carctères
		char* p = strtok(ligne,del); //on récupère le premier element de la chaine = note du commentaire
		temp = atoi(p); //on le convertit en entier
		p = strtok(NULL,del); // on récupère le deuxième element
		while(p!=NULL) {
			remplissage(p,mots_score,temp); // on le mets dans la liste
			p = strtok(NULL,del); //on avance element par element dans la chaine de caractère
		}
	}
	fclose(filep); //on ferme le fichier
	return mots_score;
}

char* saisie(){
	//permet de stocker un commentaire saisi par l'utilisateur dans une variable
	char* commentaire = malloc(301*sizeof(char));
	printf("Veuillez saisir un commentaire (300 caractères max.)\n");
	fgets(commentaire, 301, stdin);
	printf("Votre commentaire :\n%s\n", commentaire);
	return commentaire;
}

void fsaisie()
{
	//permet de stocker un comentaire saisi par l'utilisateur dans un fichier commentaire.txt
	char* commentaire = malloc(301*sizeof(char));
	fgets(commentaire, 301, stdin);
    	FILE* fichier = NULL;
    	fichier = fopen(fileComm, "w");
    	if (fichier != NULL)
	{
    		fputs(commentaire, fichier);
        	fclose(fichier);
    	}
    	else
    	printf("erreur lors de l'ouverture du fichier\n");
}

//meme fonction que evaluer sans la partie blabla
double evaluer_bis(TableHachage t, int nbl, float f)
{
	float sum = 0;
	int n = 0;
	char tab[1][MAXLIGNE];

	FILE *commentaire = file_open(fileComm);
	
	traitement_ligne(commentaire, tab);

	char* mot = malloc(sizeof(char)*30); //les mots font moins de 30 lettres	
       	mot = strtok(tab[0],del);

	while(mot!=NULL) 
	{		
		if(strlen(mot)>nbl)
		{
			ELEMENT e = tableHachage_get(mot, t);		            
	    		if (e==NULL)
			{
				 sum = sum + 2;
				 n++;
			} else 
			{
				if(e->nb < f*150000)
				{
					float score_mot = (float) e->sum / e->nb;
					sum = sum + score_mot;
					n++;
				} else 
				{
					float score_mot = (float) e->sum / e->nb;
					if(1.8>score_mot || score_mot>2.2 || f==0)
					{
						sum = sum + score_mot;				
						n++;
					}
				}
			}	
		}
		mot = strtok(NULL,del);
	}		
	fclose(commentaire);
	return sum/n;
}



void evaluer(TableHachage t, int nbl, float f){
	//cette version ignore les mots considérés comme n'apportant pas d'information
	//quant à l'avis en se basant sur le score des mots très fréquents (de fréquence > à f)
	//elle ignore aussi les mots de nbl lettres ou moins.
	float sum = 0; 	//somme des scores du commentaire
	int n =0; 	//nombre de mots du commentaire
	char tab[1][MAXLIGNE]; 
	FILE* commentaire = file_open(fileComm);
	traitement_ligne(commentaire, tab);
	char* mot = malloc(sizeof(char)*30); //les mots font moins de 30 lettres
	mot = strtok(tab[0],del);
	while(mot!=NULL) {
		if(strlen(mot)>nbl){
			//printf("%s\n", mot);
			ELEMENT e = tableHachage_get(mot, t);
			if (e==NULL){
				sum = sum + 2; //le mot n'a pas été trouvé, on lui donne une valeur neutre
				n++;
				//printf("pas trouvé\n");
			}
			else{
				if(e->nb < f*150000){ //150000 est le nombre de mots de moviesreviex.txt
					float score_mot = (float) e->sum / e->nb;
					sum = sum + score_mot;
					n++;
					//printf("peu fréquent\n");
				}
				else{	//dans le cas où le mot est très fréquent
					float score_mot = (float) e->sum / e->nb;
					//printf("frequent\n");
				
					if(1.8>score_mot || score_mot>2.2 || f==0){ 
						//On l'ajoute seulement si son score
						//n'est pas compris entre 1.8 et 2.2
						sum = sum + score_mot;		
						//Si f = 0, on ne prend pas en compte 
						n++;						
						//la fréquence donc on ajoute tout.
						//1.8 et 2.2 sont des valeurs arbitraires.
					}
				}
			}
		}
		mot = strtok(NULL,del); //passage au mot suivant
	}
	printf(".----------------------------------------.\n");
	printf("|Le score du commentaire est : %f |\n", sum/n);
	printf(".----------------------------------------.\n");
	if(sum/n<1.8) {
		printf("le commentaire est négatif\n");
		printf(".--------------------------.\n");
	}
	else if(sum/n>2.2) {
		printf("le commentaire est positif\n");
		printf(".--------------------------.\n");
	}
	else {
		printf("le commentaire est neutre\n");
		printf(".--------------------------.\n");
	}
}
void viderBuffer() /*cette fonction permet de vider le pointeur stdin qui prends les données saisit par l'utilisateur en ligne de commande*/
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
void sous_menu() {
	int num;
	printf("Avez-vous une autre requête à effectuer ?\n1 : Oui\n2 : Non\n");
			scanf("%d",&num);
			switch(num) {
				case 1 :
					viderBuffer();
					menu();
					break;
				case 2 :
					printf("*************************\n");
					printf("* Merci pour votre test *\n");
					printf("*************************\n");
					break;
			}
}
void sous_menu_stats(TableHachage t) {
	int num;
	printf("Voulez-vous récupérer une autre données statistique ?\n1 : Oui\n2 : Non\n3 : Revenir vers le menu principal\n");
			scanf("%d",&num);
			switch(num) {
				case 1 :
					menu_stats(t);
					break;
				case 2 :
					printf("*************************\n");
					printf("* Merci pour votre test *\n");
					printf("*************************\n");
					break;
				case 3 :
					viderBuffer();
					menu();
					break;
			}
}
void menu_stats(TableHachage t) {
	printf("=======================MENU STATS=======================\n\n--------------------------------------------------\n");
	int num,temp;
	printf("Voila les données que vous pouvez recupérer\n");
	printf("1 : Afficher le nombre totals des mots du fichier\n");
	printf("2 : Afficher le nombre différents des mots du fichier\n");
	printf("3 : Afficher les n nombre les plus fréquents\n");
	printf("4 : Afficher le nombre des mots dans n intervalles critique entre 0 et 4\n");
	printf("5 : Afficher les n mots les plus notés\n");
	printf("6 : Afficher les n mots les moins notés\n");
	printf("7 : Afficher la moyenne et la variance des notes de la table\n");
	printf("8 : Retour au menu principal\n");
	printf("9 : Quittez le menu\n");
	scanf("%d",&num);
	switch(num) {
		case 1 :
			motsDif(t,0);
			sous_menu_stats(t);
			break;
		case 2 :
			motsDif(t,1);
			sous_menu_stats(t);
			break;
		case 3 :
			viderBuffer();
			printf("Veuillez saisir le nombre d'élémnts à afficher :\n");
			scanf("%d",&temp);
			freq(t,temp);
			sous_menu_stats(t);
			break;
		case 4 :
			viderBuffer();
			printf("Veuillez saisir le nombre d'intervalles n :\n");
			scanf("%d",&temp);
			repartition(t,temp);
			sous_menu_stats(t);
			break;
		case 5 :
			viderBuffer();
			printf("Veuillez saisir le nombre d'élémnts à afficher:\n");
			scanf("%d",&temp);
			motsPos(t,temp);
			sous_menu_stats(t);
			break;
		case 6 :
			viderBuffer();
			printf("Veuillez saisir le nombre d'élémnts à afficher:\n");
			scanf("%d",&temp);
			motsNeg(t,temp);
			sous_menu_stats(t);
			break;
		case 7 :
			moyenne(t);
			sous_menu_stats(t);
			break;
		case 8 : 
			menu();
			break;
		case 9 :
			printf("*************************\n");
			printf("* Merci pour votre test *\n");
			printf("*************************\n");
			break;
		default :
			printf(" 6 Veuillez réessayer , le numéro que vous avez entrer n'est pas une option de ce menu\n");
			menu_stats(t);
			break;
	}
}
void menu() {
	TableHachage t = tableHachage_creer(TAILLE_MAX);
	FILE* filep = NULL;
	filep = file_open(fileData);
	t = gestion(filep);
	int num;
	printf("=======================MENU=======================\n\n--------------------------------------------------\n");
	printf("              Que voulez vous faire ?\n--------------------------------------------------\n\n1 : Afficher la critique associée à votre commentaire\n2 : Tester le menu avec la méthode EQM\n3 : Récupérer des données statistique sur le fichier des commentaires\n4 : Quittez le menu\n");
	printf("Tapez le numéro correspondant à votre requête : \n");
	scanf("%d",&num);
	switch(num) {
		case 1 :
			printf("Veuillez saisir un commentaire (300 caractères max.)\n");
			viderBuffer();
			fsaisie();
			evaluer(t,2,0.1);
			sous_menu();
			break;
		case 2 :
			testing();
			sous_menu();
			break;
		case 3 :
			menu_stats(t);
			break;
		case 4 :
			printf("*************************\n");
			printf("* Merci pour votre test *\n");
			printf("*************************\n");
			break;
			
		default :
			printf("5 Veuillez réessayer , le numéro que vous avez entrer n'est pas une option de ce menu\n");
			viderBuffer();
			menu();
			break;
	}
}


//###################### Partie Testing ################################################

// ############# fonction de testing ##################
// cette fonction offre un menu de communication pour réaliser des jeux de tests
// sur des fichier de données


void testing()
{
	
	printf("#### Menu Testing ####\n");


	// Le but est de rendre ce process le plus général possible
	//#########################################################################################
	// ##### 1: On demande le fichier a tester ### 
	// ########################################################################################
	
	printf(".----------------------------------------.\n");
	printf("|Indiquez le nom du fichier de données(dans le repertoire data): |\n");
	printf(".----------------------------------------.\n");
	viderBuffer();
	char* path = malloc(401*sizeof(char));
	fgets(path, 401, stdin);
	path=str_replace(path,"\n","");
		
	//ici on appalle la fonction depuis src/etape1 
	//or on demande le chemin depuis la racine; il faut ajuster
	char* nv_path = malloc(301*sizeof(char));
	strcpy(nv_path,"../../data/");
	strcat(nv_path,path);
	strcpy(path,nv_path);
	//free(nv_path);
	
	printf("le path vaut:%s\n",path);

	//#####################################################################################
	// ###### 2: on demande du traitement additionnel #####
	// ###################################################################################
	// on inclut la possibilité de rendre la casse en utilisant les
	// fonctions de FileTreatment

	printf(".----------------------------------------.\n");
	printf("|Voulez vous rendre le fichier insenssible à la casse ? [0(non)\\1(oui)] |\n");
	printf(".----------------------------------------.\n");
	
	int a; 
     scanf("%d",&a);
	//printf("%d\n",a);	
	if( a == 1)	// si on a choisit de faire le traitement, il faut le faire lol
	{
		file_treatment(path); // on genere le fichier traited.txt
		strcpy(path,new_file); // on indique le nouveau fichier à prendre en compte
	}
	
	//ce print est a enlever
	printf("\npath vaut: %s\n",path);

	//########################################################################################
	// #### 3: on demande sur combien de ligne on veut tester #####
	// ######################################################################################
	int nb_ligne; //le nombre de ligne du fichier initial
	FILE* pth = NULL;
	pth =file_open(path);
	nb_ligne = commentaire_fichier(pth);
	// L'idée est de tester notre fonction sur quelques lignes de notre fichier de données
	printf(".----------------------------------------.\n");
	printf("|Le fichier présenté possède %d lignes.| \n", nb_ligne);
	printf(".----------------------------------------.\n");
	fclose(pth);

	//on s'occupe de spliter notre fichier path en 2 sous fichier
	//fileA.txt et fileB.txt
	//le premier permettra a créer notre table de hachage
	//le deuxieme a realiser nos tests dessus	
	int b;
	printf(".----------------------------------------.\n");
	printf("|On test notre programme sur combien de ligne ?(tapez un nombre) | \n");
	printf(".----------------------------------------.\n");
	
	scanf("%d",&b);

	//operation de splitage
	split(path,nb_ligne-b); 
	
	// ######################################################################################
	// #### 4: on passe au calcul de l'erreur #######
	// #####################################################################################
	//on peut passer au calcul de l'eqm
	
	double LEQM;
	LEQM = eqm(fileA,fileB);
	
	printf(".----------------------------------------.\n");
	printf("|EQM sur les n lignes:%f|\n",LEQM);
	printf(".----------------------------------------.\n");
	

}

// #################### fonction de calcul de l'eqm ##########################
// son but principal est d'évaluer l'erreur que notre programme peut faire en s'entrainant sur 
// un premier fichier fa, et en comparant le resultat attendu sur les commentaires de fb 
// on va utiliser l'eqm comme indicateur: 
//     eqm = sqrt( somme_sur_l'ensemble_des_com_de_fb(    (note_obtenue - note_attendue)**2) ) )
double eqm(char* fa,char* fb)
{
	double eqm = 0.0; // notre eqm à calculer
	

	FILE* first_file = NULL;	// correspond a l'entrainement de notre table
	first_file = file_open(fa); 

	FILE* scnd_file = NULL;		// correspond a l'evaluation
	scnd_file = file_open(fb);
	
	TableHachage t = tableHachage_creer(TAILLE_MAX); // on creer notre table entrainee sur fa
	t = gestion(first_file);
	//tableHachage_visualiser(t);
	// ici le but va être d'évaluer chaque ligne de scnd_file, 
	// de calculer la note à partie de evaluer 
	// et de la comparer avec sa note réelle disponible dans scnd file
	
	int note_reelle = 1; //va stocker la note relle de chaque commentaire 
	double note_calculee;
	int lines_number = 0;

	char *chaine = malloc(sizeof(char)*MAXLIGNE); 
	char *nv_chaine = malloc(sizeof(char)*MAXLIGNE);
	int nbl; // pour les parametres de evaluer
	float f; //pour les parametres de evaluer	
	
	//on va demander a l'utilisateur les parametres qu'il veut donner a la fonction evaluer:
	printf(".----------------------------------------.\n");
	printf("Il va falloir que vous nous donniez les parametres pour l'evaluation\n");
	printf("On supprimer les mots de nbl lettres ou moins: tapper un entier.(par défault 1)\n");
	scanf("%d",&nbl);
	printf("On ne considere pas les mots ayant une frequence d'apparition inferieur à: tappez un floattant.(par défault 0.1)\n");
	scanf("%f",&f);
	printf(".----------------------------------------.\n");

	while( fgets(chaine,MAXLIGNE,scnd_file) != NULL)
	{	

		if( chaine[0] == '.') //alors on sait que scnd_file est passé par fileTreatment
		{
			note_reelle = (int)chaine[1] - 48; //la note se situe en realite sur la 2° position de notre commentaire
		} else
		{
			note_reelle = (int)chaine[0] - 48; //sinon la note est sur la premiere position
		}
		nv_chaine = chaine +2; // permet d'enlever la note dans notre chaine pour l'evaluer
		
		//il faut qu'on remplisse le fichier de commentaire avec notre nvl_chaine
		FILE* file_com = file_open_treatment(fileComm,"w+");
		fputs(nv_chaine,file_com);
		fclose(file_com);
		//ici on passe a l'evaluation de ce commentaire
		note_calculee = evaluer_bis(t,nbl,f);	

		printf(".----------------------------------------.\n");
		printf("|Notre chaine est: %s\n",nv_chaine);
		printf("|La note reelle est: %d|\n",note_reelle);
		printf("|La note calculée est: %f|\n",note_calculee);
		printf(".----------------------------------------.\n");
		
		eqm = eqm + square( note_reelle - note_calculee);
		lines_number++;
	}
	
	

	fclose(first_file);
	fclose(scnd_file);

	return eqm/lines_number;
}



//###################### Partie analyse statistique ###################################
//

int motsDif(TableHachage t, int d){  //d = 0 pour le nb de mots et d = 1 pour le nb de mots différents
	int n = t->tailleTableau;
	int md = 0;
	int m = 0;
	for (int i=0; i<n; i++){
			Liste p = t->tableauListe[i];
			while (p!=NULL){
				md++;
				m = m + p->elm->nb;
				p = p->suiv;
			}
	}
	if(d){
		printf("Nombre de mots différents : %d\n", md);
		return md;
	} else {
		printf("Nombre de mots : %d\n", m);
		return m;
	}
}

int minTab(ELEMENT* tab, int n){
//fonction utilisée dans freq pour connaitre l'indice de l'element à remplacer dans le tableau
	int min = 999999;
	int imin = 0;
	for (int i = 0; i<n; i++){
		if(tab[i]->nb < min){
			imin = i;
			min = tab[i]->nb;
		}	
	}
	return imin;
}

ELEMENT* freq(TableHachage t, int n){
//cette fonction revoie les n mots (elements) les plus fréquents de la table t
	ELEMENT* tab = malloc(n*sizeof(ELEMENT));
	int tt = t->tailleTableau;
	int count = 0;
	for (int i=0; i<tt; i++){
		Liste p = t->tableauListe[i];
		while (p!=NULL){
			if(count < n){
				tab[count]=p->elm;
				count++;
			}
			else{
				int imin = minTab(tab, n);
				if(tab[imin]->nb < p->elm->nb){
					tab[imin]=p->elm;
				}
			}
			p = p->suiv;
		}
	}
	printf("Les mots les plus fréquents sont :\n");
	for(int j = 0;j<n;j++){
		printf("%s \t apparaissant %d fois\n", tab[j]->key, tab[j]->nb);
	}
	return tab;
}

void repartition(TableHachage t, int n){
	//Cette fonction permet de voir la répartition des mots selon leur note
	//n est le nombre d'intervalles utilisés pour la répartition
	if(n<2){
		if(n==1)
			printf("Il y a donc %d mots entre 0 et 4\n",motsDif(t,1));
		else{
			printf("Merci de choisir n>=1\n");
		}
		return;
	}
	int* tab = malloc(n*sizeof(int));
	int tt = t->tailleTableau;
	//int total=0;
	for(int k = 0; k<n; k++) //initiaisation du tableau
		tab[k]=0;
	for (int i=0; i<tt; i++){
			Liste p = t->tableauListe[i];
			while (p!=NULL){
				float score = (float)p->elm->sum/p->elm->nb; //la note du mot qu'on étudie
				for(int k = 0; k<n; k++){
					if(score>=(float)k*4/n && score<(float)(k+1)*4/n){
						tab[k]++;
						//total++;
					}
				}	
				if(score == 4){
					tab[n-1]++;
					//total++;
				}
				
				p = p->suiv;
			}
	}
	for(int k = 0; k<n-1; k++){
		printf("Il y a %d mots entre %4.2f et %4.2f (exclu)\n",tab[k], (float)k*4/n, (float)(k+1)*4/n);
	}
	printf("Il y a %d mots entre %4.2f et %4.2f (inclu)\n",tab[n-1], (float)(n-1)*4/n, (float)(n)*4/n);
	//printf("%d\n", total);
}

int minTab2(ELEMENT* tab, int n){
//fonction utilisée dans motsPos pour connaitre l'indice de l'element à remplacer dans le tableau
	float min = 999999;
	int imin = 0;
	for (int i = 0; i<n; i++){
		float score= (float)tab[i]->sum/tab[i]->nb;
		if(score< min){
			imin = i;
			min = score;
		}	
	}
	return imin;
}

ELEMENT* motsPos(TableHachage t, int n){
	//renvoie un tableau contenant les n mots (ELEMENT) les mieux notés (pas ordonné)
	ELEMENT* tab = malloc(n*sizeof(ELEMENT));
	int tt = t->tailleTableau;
	int count = 0;
	for (int i=0; i<tt; i++){
		Liste p = t->tableauListe[i];
		while (p!=NULL){
			if(count < n){
				tab[count]=p->elm;
				count++;
			}
			else{
				int imin = minTab2(tab, n);
				if((float)tab[imin]->sum/tab[imin]->nb < (float)p->elm->sum/p->elm->nb){
					tab[imin]=p->elm;
				}
			}
			p = p->suiv;
		}
	}
	printf("Les mots les mieux notés sont :\n");
	for(int j = 0;j<n;j++){
		printf("%s \t \t noté %4.3f \n", tab[j]->key, (float)tab[j]->sum/tab[j]->nb);
	}
	return tab;
}

int maxTab2(ELEMENT* tab, int n){
//fonction utilisée dans motsNeg pour connaitre l'indice de l'element à remplacer dans le tableau
	float max = 0;
	int imax = 0;
	for (int i = 0; i<n; i++){
		float score= (float)tab[i]->sum/tab[i]->nb;
		if(score> max){
			imax = i;
			max = score;
		}	
	}
	return imax;
}

ELEMENT* motsNeg(TableHachage t, int n){
	//renvoie un tableau contenant les n mots (ELEMENT) les mieux notés (pas ordonné)
	ELEMENT* tab = malloc(n*sizeof(ELEMENT));
	int tt = t->tailleTableau;
	int count = 0;
	for (int i=0; i<tt; i++){
		Liste p = t->tableauListe[i];
		while (p!=NULL){
			if(count < n){
				tab[count]=p->elm;
				count++;
			}
			else{
				int imax = maxTab2(tab, n);
				if((float)tab[imax]->sum/tab[imax]->nb > (float)p->elm->sum/p->elm->nb){
					tab[imax]=p->elm;
				}
			}
			p = p->suiv;
		}
	}
	printf("Les mots les moins bien notés sont :\n");
	for(int j = 0;j<n;j++){
		printf("%s \t \t noté %4.3f \n", tab[j]->key, (float)tab[j]->sum/tab[j]->nb);
	}
	return tab;
}

float moyenne(TableHachage t){
	int tt = t->tailleTableau;
	float sum = 0;
	float sum2 = 0;
	int n = 0;
	for (int i=0; i<tt; i++){
			Liste p = t->tableauListe[i];
			while (p!=NULL){
				float score = (float)p->elm->sum/p->elm->nb;
				sum = sum + score;
				sum2 = sum2 + score*score;
				n++;
				p = p->suiv;
			}
	}
	float moyenne = sum/n;
	float moyenne2 = sum2/n;
	float variance = moyenne2 - moyenne*moyenne;
	printf("La moyenne des notes est : %f\n", moyenne);
	printf("La variance des notes est : %f\n", variance);
	return moyenne;
}



















