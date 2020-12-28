#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/listSimpleChain.h"
#include "../lib/tableHachage.h"

//#include <list_hach.h>
int main()
{

	int nb=5;
       	TableHachage ma_table=malloc(sizeof(ma_table));
	ma_table = tableHachage_creer(nb);
		
		char* ki="oui";		
		ELEMENT e =malloc(sizeof(ELEMENT));
		e = tableHachage_get(ki,ma_table);
	return 1;
}
