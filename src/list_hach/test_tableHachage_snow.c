#include "./snow-v2.3.0/snow.h"
#include "list_hach.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

describe(test_tableHachage_creer)
{
	before_each(){}
	after_each() {}

	it("verification_liste_vide")
	{
		int nb=5;
		TableHachage ma_table=malloc(sizeof(ma_table));
		ma_table=tableHachage_creer(nb);
		Liste ma_liste= malloc(sizeof(ma_liste));
		for(int i = 0; i < nb; i++)
		{
			ma_liste=(*ma_table).tableauListe[i];
			asserteq_int( list_estVide(ma_liste),1);
		}
	}
	it("verification_tailleTableau")
	{
		int nb = 7;
		TableHachage ma_table=malloc(sizeof(ma_table));
		ma_table=tableHachage_creer(nb);
		asserteq_int( (*ma_table).tailleTableau, nb);
	}
	
}

describe(test_tableHachage_get)
{
	before_each() {}
	after_each() {}

	it( "not_here") 
	{
		int nb=5;
       		TableHachage ma_table=malloc(sizeof(ma_table));
 		ma_table = tableHachage_creer(nb);
		
		char* ki="oui";		
		ELEMENT e =malloc(sizeof(ELEMENT));
		e = tableHachage_get(ki,ma_table);
		asserteq(e,NULL);
	}


 	it( "here_1key")
        {
		// on creer notre petite table de hachage
                int nb=5;
                TableHachage ma_table=malloc(sizeof(ma_table));
                ma_table = tableHachage_creer(nb);
		
		// on définit notre key/clef
                char* ki="oui";
		int hc = hachage(ki,nb);

		Liste ma_liste= malloc(sizeof(ma_liste));
		ma_liste= (*ma_table).tableauListe[hc];
		asserteq_int( list_estVide(ma_liste),1);// tant qu'a faire autant verifier
		

		// on veut ajouter un element a notre liste: on le formate
		ELEMENT a = malloc(sizeof(ELEMENT));
		(*a).key=ki;
		(*ma_liste).elm=a;

                ELEMENT b = malloc(sizeof(ELEMENT));
                b = tableHachage_get(ki,ma_table);
		
                asserteq(   strcmp( ki ,(*b).key),0    ) ;

        }
 	it( "here_manykey")
        {
                // on creer notre petite table de hachage
                int nb=5;
                TableHachage ma_table=malloc(sizeof(ma_table));
                ma_table = tableHachage_creer(nb);

                // on définit notre key/clef
                char* ki="oui";
                int hc = hachage(ki,nb);

                Liste ma_liste= malloc(sizeof(ma_liste));
                ma_liste= (*ma_table).tableauListe[hc];
                asserteq_int( list_estVide(ma_liste),1);// tant qu'a faire autant verifier


                // on veut ajouter un element a notre liste: on le formate
                ELEMENT a = malloc(sizeof(ELEMENT));
                (*a).key=ki;
                (*ma_liste).elm=a;


		//on va ajouter pleins d'autres mots
		ELEMENT a1a = malloc(sizeof(ELEMENT));
		ELEMENT a2a = malloc(sizeof(ELEMENT));
		ELEMENT a3a = malloc(sizeof(ELEMENT));
		ELEMENT a4a = malloc(sizeof(ELEMENT));
		ELEMENT a5a = malloc(sizeof(ELEMENT));
		ELEMENT a6a = malloc(sizeof(ELEMENT));
		ELEMENT a7a = malloc(sizeof(ELEMENT));
		ELEMENT a8a = malloc(sizeof(ELEMENT));
		ELEMENT a9a = malloc(sizeof(ELEMENT));
		ELEMENT a0a = malloc(sizeof(ELEMENT));
		char* k1k= "zadzad";
		char* k2k= "zdzaxcv";
		char* k3k= "m";
		char* k4k= "xaazzadzfdazfazfazfaz";
		char* k5k= "vvcccv";
		char* k6k= "vbbnn";
		char* k7k= "rvza";
		char* k8k= "aer";
		char* k9k= "pmmdazd";
		char* k0k= "dvh";
		(*a1a).key=k1k;
		(*a2a).key=k2k;
		(*a3a).key=k3k;
		(*a4a).key=k4k;
		(*a5a).key=k5k;
		(*a6a).key=k6k;
		(*a7a).key=k7k;
		(*a8a).key=k8k;
		(*a9a).key=k9k;
		(*a0a).key=k0k;
		int n1n = hachage(k1k,nb);
		int n2n = hachage(k2k,nb);
		int n3n = hachage(k3k,nb);
		int n4n = hachage(k4k,nb);
		int n5n = hachage(k5k,nb);
		int n6n = hachage(k6k,nb);
		int n7n = hachage(k7k,nb);
		int n8n = hachage(k8k,nb);
		int n9n = hachage(k9k,nb);
		int n0n = hachage(k0k,nb);

		list_ajoutFin( (*ma_table).tableauListe[n1n] , a1a);
		list_ajoutFin( (*ma_table).tableauListe[n2n] , a2a);
		list_ajoutFin( (*ma_table).tableauListe[n3n] , a3a);
		list_ajoutFin( (*ma_table).tableauListe[n4n] , a4a);
		list_ajoutFin( (*ma_table).tableauListe[n5n] , a5a);
		list_ajoutFin( (*ma_table).tableauListe[n6n] , a6a);
		list_ajoutFin( (*ma_table).tableauListe[n7n] , a7a);
		list_ajoutFin( (*ma_table).tableauListe[n8n] , a8a);
		list_ajoutFin( (*ma_table).tableauListe[n9n] , a9a);
		list_ajoutFin( (*ma_table).tableauListe[n0n] , a0a);


                ELEMENT b = malloc(sizeof(ELEMENT));
                b = tableHachage_get(ki,ma_table);

                asserteq(   strcmp( ki ,(*b).key),0    ) ;
		free(b);	
		free(a1a);
		free(a2a);
		free(a3a);
		free(a4a);
		free(a5a);
		free(a6a);
		free(a7a);
		free(a8a);
		free(a9a);
		free(a0a);
		free( ma_table);
        }
}

describe(test_tableHachage_ajout)
{
	
	before_each() {}
        after_each() {}

        it( "verification_positionementValidite_tableVide")
        {
	
	int nb=5;
        TableHachage ma_table=malloc(sizeof(ma_table));
        ma_table = tableHachage_creer(nb);

        // on définit notre key/clef
        char* ki="pqrs";
        int hc = hachage(ki,nb);

	Liste ma_liste= malloc(sizeof(ma_liste));
        ma_liste= (*ma_table).tableauListe[hc];

	asserteq( list_estVide(ma_liste),1); 
	
	ELEMENT b = malloc(sizeof(ELEMENT));
	(*b).key=ki;
	tableHachage_ajout(b,ma_table);
	
	asserteq( list_estVide( (*ma_table).tableauListe[hc]),0);
	
	ELEMENT c = malloc(sizeof(ELEMENT));	
	c=tableHachage_get(ki,ma_table);

	asserteq(   strcmp( ki ,(*c).key),0    ) ;

	}
	
	it( "verification_positionementValidite_tableRemplie")
	{
		
		int nb=5;
	        TableHachage ma_table=malloc(sizeof(ma_table));
       		ma_table = tableHachage_creer(nb);

		// on définit notre key/clef
	        char* ki="zkdzkad";
        	int hc = hachage(ki,nb);
		
		Liste ma_liste= malloc(sizeof(ma_liste));
        	ma_liste= (*ma_table).tableauListe[hc];
	        asserteq( list_estVide(ma_liste),1); //au cas ou

		ELEMENT b = malloc(sizeof(ELEMENT));
        	(*b).key=ki;
        	tableHachage_ajout(b,ma_table);

		asserteq( list_estVide( (*ma_table).tableauListe[hc]),0);
			
		ELEMENT c = malloc(sizeof(ELEMENT));
        	c=tableHachage_get(ki,ma_table);
        	asserteq(   strcmp( ki ,(*c).key),0    ) ;

		//on va ajouter pleins d'autres mots
                ELEMENT a1a = malloc(sizeof(ELEMENT));
                ELEMENT a2a = malloc(sizeof(ELEMENT));
                ELEMENT a3a = malloc(sizeof(ELEMENT));
                ELEMENT a4a = malloc(sizeof(ELEMENT));
                ELEMENT a5a = malloc(sizeof(ELEMENT));
                ELEMENT a6a = malloc(sizeof(ELEMENT));
                ELEMENT a7a = malloc(sizeof(ELEMENT));
                ELEMENT a8a = malloc(sizeof(ELEMENT));
                ELEMENT a9a = malloc(sizeof(ELEMENT));
                ELEMENT a0a = malloc(sizeof(ELEMENT));
                char* k1k= "zadzad";
                char* k2k= "zdzaxcv";
                char* k3k= "m";
                char* k4k= "xaazzadzfdazfazfazfaz";
                char* k5k= "vvcccv";
                char* k6k= "vbbnn";
                char* k7k= "rvza";
                char* k8k= "aer";
                char* k9k= "pmmdazd";
                char* k0k= "dvh";

		(*a1a).key=k1k;
                (*a2a).key=k2k;
                (*a3a).key=k3k;
                (*a4a).key=k4k;
                (*a5a).key=k5k;
                (*a6a).key=k6k;
                (*a7a).key=k7k;
                (*a8a).key=k8k;
                (*a9a).key=k9k;
                (*a0a).key=k0k;
                int n1n = hachage(k1k,nb);
                int n2n = hachage(k2k,nb);
                int n3n = hachage(k3k,nb);
                int n4n = hachage(k4k,nb);
                int n5n = hachage(k5k,nb);
                int n6n = hachage(k6k,nb);
                int n7n = hachage(k7k,nb);
                int n8n = hachage(k8k,nb);
                int n9n = hachage(k9k,nb);
                int n0n = hachage(k0k,nb);

                list_ajoutFin( (*ma_table).tableauListe[n1n] , a1a);
                list_ajoutFin( (*ma_table).tableauListe[n2n] , a2a);
                list_ajoutFin( (*ma_table).tableauListe[n3n] , a3a);
                list_ajoutFin( (*ma_table).tableauListe[n4n] , a4a);
                list_ajoutFin( (*ma_table).tableauListe[n5n] , a5a);
                list_ajoutFin( (*ma_table).tableauListe[n6n] , a6a);
                list_ajoutFin( (*ma_table).tableauListe[n7n] , a7a);
                list_ajoutFin( (*ma_table).tableauListe[n8n] , a8a);
                list_ajoutFin( (*ma_table).tableauListe[n9n] , a9a);
                list_ajoutFin( (*ma_table).tableauListe[n0n] , a0a);
		

		

                // on définit notre key/clef
                char* kii="zlezgababa";
                int hci = hachage(kii,nb);

                ELEMENT bi = malloc(sizeof(ELEMENT));
                (*bi).key=kii;
                tableHachage_ajout(bi,ma_table);

                asserteq( list_estVide( (*ma_table).tableauListe[hci]),0);

                ELEMENT ci = malloc(sizeof(ELEMENT));
                ci=tableHachage_get(kii,ma_table);
                asserteq(   strcmp( kii ,(*ci).key),0    ) ;
	}
}
/*describe(test_tableHachage_supprime)
{

        before_each() {}
        after_each() {}

        it( "verification_vide_table_a_1_element")
        {
		int nb=5;
                TableHachage ma_table=malloc(sizeof(ma_table));
                ma_table = tableHachage_creer(nb);

                // on définit notre key/clef
                char* ki="zkdzkad";
                int hc = hachage(ki,nb);

                Liste ma_liste= malloc(sizeof(ma_liste));
                ma_liste= (*ma_table).tableauListe[hc];
                asserteq( list_estVide(ma_liste),1); //au cas ou

                ELEMENT b = malloc(sizeof(ELEMENT));
                (*b).key=ki;

                tableHachage_ajout(b,ma_table);
		asserteq( list_estVide( (*ma_table).tableauListe[hc]),0);

                ELEMENT c = malloc(sizeof(ELEMENT));
                c=tableHachage_get(ki,ma_table);
                asserteq(   strcmp( ki ,(*c).key),0    ) ;
		

		tableHachage_supprime(ki,ma_table);
		asserteq( list_estVide( (*ma_table).tableauListe[hc]),1);
		asserteq(tableHachage_get(ki,ma_table),NULL);


	}



	it( "verification_vide_table_a_plein_element")
        {
                int nb=5;
                TableHachage ma_table=malloc(sizeof(ma_table));
                ma_table = tableHachage_creer(nb);

                // on définit notre key/clef
                char* ki="oui";
             	
		ELEMENT e1e = malloc(sizeof(ELEMENT));
		ELEMENT e2e = malloc(sizeof(ELEMENT));
		ELEMENT e3e = malloc(sizeof(ELEMENT));
		ELEMENT e4e = malloc(sizeof(ELEMENT));
		ELEMENT e5e = malloc(sizeof(ELEMENT));
		ELEMENT e6e = malloc(sizeof(ELEMENT));
		ELEMENT e7e = malloc(sizeof(ELEMENT));
		ELEMENT e8e = malloc(sizeof(ELEMENT));
		ELEMENT e9e = malloc(sizeof(ELEMENT));
		ELEMENT e0e = malloc(sizeof(ELEMENT));

		char* k1k= "zadddzdzzad";
                char* k2k= "zdzaxcdfjkmhfev";
                char* k3k= "mfdq";
                char* k4k= "xaazfqfccvzadzfdazfazfazfaz";
                char* k5k= "vvcccbzaezrv";
                char* k6k= "vbbnnbvcn";
                char* k7k= "rvznbva";
                char* k8k= "aerpoiuy";
                char* k9k= "pmmdazdpoiuy";
                char* k0k= "dvhzazzzzzzzz";

		(*e1e).key=k1k;
		(*e2e).key=k2k;
		(*e3e).key=k3k;
		(*e4e).key=k4k;
		(*e5e).key=k5k;
		(*e6e).key=k6k;
		(*e7e).key=k7k;
		(*e8e).key=k8k;
		(*e9e).key=k9k;
		(*e0e).key=k0k;

                tableHachage_ajout(e1e,ma_table);
                tableHachage_ajout(e2e,ma_table);
                tableHachage_ajout(e3e,ma_table);
                tableHachage_ajout(e4e,ma_table);
                tableHachage_ajout(e5e,ma_table);
                tableHachage_ajout(e6e,ma_table);
                tableHachage_ajout(e7e,ma_table);
                tableHachage_ajout(e8e,ma_table);
                tableHachage_ajout(e9e,ma_table);
                tableHachage_ajout(e0e,ma_table);



		ELEMENT b = malloc(sizeof(ELEMENT));
                (*b).key=ki;
                tableHachage_ajout(b,ma_table);
                

		ELEMENT c = malloc(sizeof(ELEMENT));
                c=tableHachage_get(ki,ma_table);
		assertneq(c,NULL);
                asserteq(strcmp( ki ,(*c).key),0);
		

		ELEMENT e1ee = malloc(sizeof(ELEMENT));
                ELEMENT e2ee = malloc(sizeof(ELEMENT));
                ELEMENT e3ee = malloc(sizeof(ELEMENT));
                ELEMENT e4ee = malloc(sizeof(ELEMENT));
                ELEMENT e5ee = malloc(sizeof(ELEMENT));
                ELEMENT e6ee = malloc(sizeof(ELEMENT));
                ELEMENT e7ee = malloc(sizeof(ELEMENT));
                ELEMENT e8ee = malloc(sizeof(ELEMENT));
                ELEMENT e9ee = malloc(sizeof(ELEMENT));
                ELEMENT e0ee = malloc(sizeof(ELEMENT));
		
		 char *k1kk= "zadzad";
                 char *k2kk= "zdzaxcv";
                 char *k3kk= "m";
                 char *k4kk= "xaazzadzfdazfazfazfaz";
                 char *k5kk= "vvcccv";
                 char *k6kk= "vbbnn";
                 char *k7kk= "rvza";
                 char *k8kk= "aer";
                 char *k9kk= "pmmdazd";
                 char *k0kk= "dvh";
		(*e1ee).key=k1kk;
                (*e2ee).key=k2kk;
                (*e3ee).key=k3kk;
                (*e4ee).key=k4kk;
                (*e5ee).key=k5kk;
                (*e6ee).key=k6kk;
                (*e7ee).key=k7kk;
                (*e8ee).key=k8kk;
                (*e9ee).key=k9kk;
                (*e0ee).key=k0kk;

		
		tableHachage_ajout(e1ee,ma_table);
		tableHachage_ajout(e2ee,ma_table);
		tableHachage_ajout(e3ee,ma_table);
		tableHachage_ajout(e4ee,ma_table);
		tableHachage_ajout(e5ee,ma_table);
		tableHachage_ajout(e6ee,ma_table);
		tableHachage_ajout(e7ee,ma_table);
		tableHachage_ajout(e8ee,ma_table);
		tableHachage_ajout(e9ee,ma_table);
		tableHachage_ajout(e0ee,ma_table);
			
		assertneq(tableHachage_get(ki,ma_table),NULL);
                tableHachage_supprime(ki,ma_table);
                asserteq(tableHachage_get(ki,ma_table),NULL);
        }





}*/

snow_main();

