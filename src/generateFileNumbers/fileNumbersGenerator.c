#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv){
	
	FILE *fptr;
	int maxNumber = atoi(argv[2]);
	// Create a file
	fptr = fopen(argv[1], "w");
	for(int i = maxNumber; i >= 0; i--){
		fprintf(fptr, "%d ",i);
	}

	// Close the file
	fclose(fptr);
	

	return 0;
}
