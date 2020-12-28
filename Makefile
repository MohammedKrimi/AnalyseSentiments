all : menu

menu : etape1_main
	cd ./src/etape1 && clear && ./etape1_main

etape1_main : list_hach
	cd ./src/etape1 && $(MAKE)

list_hach :
	cd ./lib && $(MAKE)