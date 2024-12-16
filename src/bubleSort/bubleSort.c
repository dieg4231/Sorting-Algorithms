#include <stdio.h>
#include <stdlib.h>
#include "../util/sortutil.h"

int main(int argc, char **argv){

	int *numsPtr = NULL;  /*Pointer to numbers to sort*/
	int swapCounter;
	int aux;
	sortingParams sp; //Struct type

	if(inputArgsHandler(argc, argv,&sp)){
		printf("Error: Wrong parameters\n");
		return 1;
	}

	printf("MAX SIZE  %d \n",sp.maxItems);
	printf("path  %s \n",sp.filePath);

	numsPtr = (int *)malloc(sp.maxItems * sizeof(int) );
	if(numsPtr == NULL){
		printf("Error allocating  memory\n");
	}
	readNumbersFromFile(&sp, &numsPtr );	
	printList(numsPtr, sp.numItems);
	
	swapCounter = 1;	
	while(swapCounter != 0){  
		swapCounter = 0;
		for(int i = 1; i < sp.numItems; i++){
			
			if( numsPtr[i] < numsPtr[i-1] ) { //Bubble sort algorithm
				aux = numsPtr[i];
				numsPtr[i] = numsPtr[i-1];
				numsPtr[i-1] = aux;
				swapCounter++;
			}  
		}
	}
	printList(numsPtr, sp.numItems);
	free(numsPtr);
	return 0;
}
