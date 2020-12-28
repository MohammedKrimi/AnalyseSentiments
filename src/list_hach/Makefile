

main_list_hach: list_hach.o
	gcc main_list_hach.c list_hach.o -o main_list_hach 
test_tableHachage_snow: list_hach.o
	gcc -Wall  -DSNOW_ENABLED -g -I./snow-v2.3.0/ list_hach.o test_tableHachage_snow.c -o test_tableHachage_snow

test_list_hach_snow: list_hach.o
	gcc -Wall  -DSNOW_ENABLED -g -I./snow-v2.3.0/ list_hach.o test_list_hach_snow.c -o test_list_hach_snow

list_hach.o:
	gcc -Wall -c list_hach.c

clean:
	rm *.o
	rm test_list_hach_snow
	rm test_list_hach
