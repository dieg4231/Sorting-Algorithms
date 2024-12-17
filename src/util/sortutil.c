#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortutil.h"

int inputArgsHandler(int argc, char **argv, sortingParams *sp ){

	if(argc == 1){
		printf("ERROR: Mandatory parameters missing\n\t-p path  and  -m maxWorkingItems\n");
		return 1;
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

int printList2File(int *numberList, sortingParams *sp){
	FILE *filePtr;
	char *filePath;
	int pathSize;
    int hasExtension = 0;
    int extensionIdx;
    
	pathSize = strlen(sp->filePath);
	filePath = (char*) malloc( (pathSize + 8)*sizeof(char));
    
    for(extensionIdx = pathSize; extensionIdx >= 0; extensionIdx--){
    	if(sp->filePath[extensionIdx] == '.'){
    		hasExtension = 1;
    		break;
    	}
    }

    if(hasExtension){
    	for(int j = 0; j < extensionIdx; j++){
    		filePath[j] = sp->filePath[j];
   		}
    	filePath[extensionIdx] = '\0';
		strncat(filePath,POSTFIX,POSTFIX_SIZE);
   		strncat(filePath,sp->filePath + extensionIdx,pathSize - extensionIdx);
   	}else{
   		strncat(filePath,sp->filePath,pathSize);
   		strncat(filePath,POSTFIX,POSTFIX_SIZE);
   	}
	//printf("-- %s\n",filePath );
	//return 0;
	// Create a file
	filePtr = fopen(filePath, "w");
	if(filePtr == NULL){
		printf("ERROR: Something went wrong  while writing file.\n");
		fclose(filePtr);
		free(filePath);
		return 1;
	}

	for(int i = 0 ; i < sp->numItems; i++)
		fprintf(filePtr, "%d ",numberList[i]);	
	
	fclose(filePtr);
	free(filePath);
	return 0;
}

int readNumbersFromFile( sortingParams *sp, int **numberList ){
	FILE *file;
	int counter = 0;
	file = fopen(sp->filePath,"r");

	if(file == NULL){
		printf("ERROR: Something went wrong while reading file.\n");
		return 1;
	}
	
	while(fscanf(file,"%d", (*numberList) + counter   ) != EOF  && counter < sp->maxItems  )
		counter++;
	fclose(file);
	sp->numItems = counter;
	return 0;
}

