#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	
	FILE *filePtr;
	char *filePath;
	int numElments;
	//Handler parametrs
	if(argc == 1){
		printf("ERROR: Mandatory parameters missing\n\t-p path  and  -m maxWorkingItems\n");
		return 1;
	}else{
		for(int i = 1; i < argc; i++){
			if(strcmp(argv[i],"-p") == 0){
				filePath = argv[i + 1];
				i++;
			}else if(strcmp(argv[i],"-m") == 0){
				numElments = atoi(argv[i + 1]);
				i++;
			}else{
				printf("Errror: No valid parameter %s \n", argv[i]);
				return 1;
			}
		}
	}

	// Create a file
	filePtr = fopen(filePath, "w");
	if(filePtr == NULL){
		printf("ERROR: Something went wrong reading file\n");
	}

	for(int i = numElments; i >= 0; i--){
		fprintf(filePtr, "%d ",i);
	}

	// Close file
	fclose(filePtr);
	
	return 0;
}
