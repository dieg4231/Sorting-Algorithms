#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortutil.h"

int inputArgsHandler(int argc, char **argv, sortingParams *sp ){

	if(argc == 1){
		printf("ERROR: Mandatory parameters missing\n\t-p path  and  -m maxWorkingItems\n");
	}
	for(int i = 1; i < argc; i++){
		if( strcmp(argv[i],"-p") == 0 ){
			//printf("Path is %s \n",argv[i + 1]);
			sp->filePath = argv[i + 1];
			i++;
		}
		else if( strcmp(argv[i],"-m") == 0 ){
			//printf("Maximum items to handle %s \n",argv[i + 1]);
			sp->maxItems = atoi(argv[i + 1]);
			i++;
		}
		else{
			printf("Incorrect parameter: %s\n",argv[i]);
			return 1;
		}

	}
	return 0;

}

void printList(int *numberList, int size){
	for(int i = 0 ; i < size; i++)
		printf("%d ",numberList[i]);	
	printf("\n");
}

int readNumbersFromFile( sortingParams *sp, int **numberList ){
	FILE *file;
	int counter = 0;
	file = fopen(sp->filePath,"r");

	if(file == NULL){
		printf("ERROR: Something went wrong reading file\n");
		return 1;
	}
	
	while(fscanf(file,"%d", (*numberList) + counter   ) != EOF  && counter < sp->maxItems  )
		counter++;
	fclose(file);
	sp->numItems = counter;
	return 0;
}

