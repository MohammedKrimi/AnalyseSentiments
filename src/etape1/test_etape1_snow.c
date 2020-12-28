#include "etape1.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../lib/listSimpleChain.h"
#include "../../lib/tableHachage.h"
#define TAILLE_MAX 1000
#include <string.h>
#define marqueur_fin "FIN"
#include "../../snow-v2.3.0/snow.h"

describe(test_list_est_vide)
{
        before_each() {}
        after_each() {}
        it("test_ligne_1") {
		char* tab[TAILLE_MAX];     
               char chaine[TAILLE_MAX]="0 Downright transparent is the script 's endless assault of embarrassingly ham-fisted sex jokes that reek of a script rewrite designed to garner the film a `` cooler '' PG-13 rating .";
		traitement_ligne(chaine,tab);
		asserteq(tab[0],"0");
		asserteq(tab[2],"transparent");
		asserteq(tab[8],"assault"); 
	      asserteq(tab[12],"fisted");
      asserteq(tab[31],marqueur_fin);   	      



        }
        it("test_ligne_2") {
		char* tab[TAILLE_MAX];     
               char chaine[TAILLE_MAX]="1 Kung Pow is Oedekerk 's realization of his childhood dream to be in a martial-arts flick , and proves that sometimes the dreams of youth should remain just that .";
		traitement_ligne(chaine,tab);
		asserteq(tab[0],"1");
        	 asserteq(tab[5],"s");
                 asserteq(tab[10],"dream");
		 asserteq(tab[15],"martial");
  		asserteq(tab[19],"proves");
		asserteq(tab[30],marqueur_fin);
	
	}


}

snow_main();
