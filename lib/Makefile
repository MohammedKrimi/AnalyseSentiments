all : liblist_hach.a libfileTreatment.a

liblist_hach.a : list_hach.o
	ar -r liblist_hach.a  ../src/list_hach/list_hach.o

list_hach.o : ../src/list_hach/list_hach.c
	gcc -c ../src/list_hach/list_hach.c -o ../src/list_hach/list_hach.o

libfileTreatment.a : fileTreatment.o
	ar -rv libfileTreatment.a  ../src/fileTreatment/fileTreatment.o

fileTreatment.o : ../src/fileTreatment/fileTreatment.c
	gcc -c ../src/fileTreatment/fileTreatment.c -o ../src/fileTreatment/fileTreatment.o
