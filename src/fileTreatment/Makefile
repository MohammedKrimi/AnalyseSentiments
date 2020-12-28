
main: fileTreatment.o
	gcc -Wall main.c fileTreatment.o -o main

libfileTreatment.a: fileTreatment.o
	ar rv libfileTreatment.a fileTreatment.o


fileTreatment.o:
	gcc -c fileTreatment.c

clean:
	rm *.o

