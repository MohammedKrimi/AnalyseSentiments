#include "list_hach.h"
#include "../snow-v2.3.0/snow.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

describe(test_list_creer)
{
	before_each(){}
        after_each() {}
        it("verification_pointeur_Liste")
	{
		Liste ma_liste=malloc(sizeof(Liste));
		ma_liste=list_creer();
		assertneq(ma_liste,NULL);
	}
	 
	it("verification_pointeur_elm") 
	{
		                 
		Liste ma_liste=malloc(sizeof(Liste)); 		
		ma_liste=list_creer(); 
		asserteq((*ma_liste).elm,NULL);
	}
       	it("verification_pointeur_suiv")  		
       	{
                 Liste ma_liste=malloc(sizeof(Liste));   
		 ma_liste=list_creer(); 
		 asserteq((*ma_liste).suiv,NULL); 
	}


}
describe(test_list_estVide)
{
	before_each(){}
	after_each() {} 
	it("verification_liste_vide")
	{
		Liste ma_liste=malloc(sizeof(Liste));
		ma_liste=list_creer();
		asserteq( list_estVide(ma_liste),1);
	}	
	it("verification_liste_Not_vide")
	{   
		Liste ma_liste=malloc(sizeof(Liste));   
		ma_liste=list_creer();		
		ELEMENT e=malloc(sizeof(ELEMENT));
		(*ma_liste).elm=e;
		asserteq( list_estVide(ma_liste),0);	        
	} 

}
describe(test_ajoutTete)
{
	        before_each(){
			        }
		        after_each(){}
			        it("changement estvide")
					        {
							                ELEMENT eab = malloc(sizeof(eab));
									                Liste ma_liste=list_creer();
											                asserteq_int( list_estVide(ma_liste),1);
													                ma_liste=list_ajoutTete(ma_liste,eab);
															                asserteq_int( list_estVide(ma_liste),0);
																	        }
}


describe(test_list_rech)
{
	before_each() {}
	after_each() {}
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

	it("verification liste vide")
	{
		Liste ma_liste=list_creer();
		ELEMENT e = malloc(sizeof(e));
		char *mot = "puta";
		e = list_rech(ma_liste,mot);
		asserteq(e,NULL);
	}
	it("verification 5 element+ inside")
	{
	Liste ma_liste=list_creer();
	
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
	ma_liste=list_ajoutTete(ma_liste,e1);        
	ma_liste=list_ajoutTete(ma_liste,e2);		      
      	ma_liste=list_ajoutTete(ma_liste,e3);		        
	ma_liste=list_ajoutTete(ma_liste,e4);			        
	ma_liste=list_ajoutTete(ma_liste,e5);
	ma_liste=list_ajoutTete(ma_liste,e6);       
 	ma_liste=list_ajoutTete(ma_liste,e7);
	ma_liste=list_ajoutTete(ma_liste,e8);
	ma_liste=list_ajoutTete(ma_liste,e9);
	ma_liste=list_ajoutTete(ma_liste,e10);
	ma_liste=list_ajoutTete(ma_liste,e11);
	ma_liste=list_ajoutTete(ma_liste,e12);
	ma_liste=list_ajoutTete(ma_liste,e13); 
	ma_liste=list_ajoutTete(ma_liste,e14);
	ma_liste=list_ajoutTete(ma_liste,e15); 

	ELEMENT get1 = malloc(sizeof(ELEMENT));
	ELEMENT get2 = malloc(sizeof(ELEMENT));
	ELEMENT get3 = malloc(sizeof(ELEMENT));
	ELEMENT get4 = malloc(sizeof(ELEMENT));

	get1=list_rech(ma_liste,mot3);
	get2=list_rech(ma_liste,"groszizz");
	get3=list_rech(ma_liste,mot12);
	get4=list_rech(ma_liste,mot15);

	assertneq(get1,NULL);
	asserteq(get2,NULL);

	asserteq( (*get1).key, mot3);

 	assertneq(get3,NULL);
	assertneq(get4,NULL);
	asserteq((*get3).key,mot12);
	asserteq((*get4).key,mot15);





	}


	




}




snow_main();

