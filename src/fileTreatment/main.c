#include <stdio.h>
#include <stdlib.h>
#include "fileTreatment.h"
#include <string.h>
#define MAXLIGNE 400
int main()
{

	file_treatment("../../data/movie_reviews.txt");
	
	split("test.txt",2);

	printf("Hello,World!\n");
	return 0;
}
