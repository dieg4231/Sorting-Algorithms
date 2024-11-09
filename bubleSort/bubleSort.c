#include <stdio.h>
#include <stdlib.h>
#include "../util/nums2sort.h"

int main(int argc, char **argv){

	int *numberList = NULL;
    int maxSize = atoi(argv[2]);
	int numbersSize;
	int changes,aux;

	printf("MAX SIZE  %d \n",maxSize);
	numbersSize = readNumbersFromFile( argv[1], maxSize, &numberList );	
	printList(numberList, numbersSize);
	
	changes = 1;	
	while(changes != 0){
		changes = 0;
		for(int i = 1; i < numbersSize; i++){
			
			if( numberList[i] < numberList[i-1] ) {
				aux = numberList[i];
				numberList[i] = numberList[i-1];
				numberList[i-1] = aux;
				changes++;
			}  
		}
	}
	printList(numberList, numbersSize);
	free(numberList);
	return 0;
}
