all: etape1_main

etape1_main :  etape1_main.c etape1.o
	gcc  etape1_main.c etape1.o -L../../lib/ -llist_hach -lfileTreatment -o etape1_main 


test_etape1_snow: etape1.o  
	gcc -Wall -DSNOW_ENABLED -g -I../../snow-v2.3.0/ -L../../lib -llist_hach etape1.o test_etape1_snow.c -o test_etape1_snow


etape1.o : etape1.c etape1.h
	gcc -c etape1.c etape1.h


cleanFile:
	rm fileA.txt
	rm fileB.txt
	rm traited.txt

clean : 
	rm etape1_main *.o


