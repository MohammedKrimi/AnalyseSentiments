#ifndef LIST_HACH
#define LIST_HACH
//clef: string
typedef char* Clef;

//ELEMENT (clef,sum,nb)

struct ELEMENT
{
	Clef key;
	int sum;
	int nb;
};
typedef struct ELEMENT *ELEMENT;
//cellule(elm,suiv)
typedef struct cellule cellule;
struct cellule {
	ELEMENT elm;
	cellule* suiv;
};
//Liste *cellule
typedef cellule* Liste;


typedef struct table tableHachage;
struct table
{
	Liste* tableauListe;
	int tailleTableau;
};
typedef tableHachage* TableHachage;

Liste list_creer(void);
int list_estVide(Liste L);
Liste list_ajoutTete(Liste L,ELEMENT e);
void list_ajoutFin(Liste L, ELEMENT e);  
void list_incrementation(Liste L,Clef c,int temp);
//ELEMENT list_rechN(Liste L, char*sk,int n); pas besoin pour le projet 
ELEMENT list_rech(Liste L,char *sk);
//Liste list_remove(Liste L, char*sk); ""
//Liste list_removeN(Liste L, int n); ""
void list_affiche(ELEMENT e);
void list_visualiser(Liste L);

int hachage(char *s, int mod);
TableHachage tableHachage_creer(int tailleTableau);
ELEMENT tableHachage_get(Clef c, TableHachage t);
void tableHachage_ajout(ELEMENT e, TableHachage t);
void tableHachage_incrementation(TableHachage t, Clef c, int temp);
void tableHachage_supprime(Clef c, TableHachage t);
void tableHachage_visualiser(TableHachage t);






#endif
