#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../util/nums2sort.h"

int main(int argc, char **argv){
	
	int *numberList = NULL;
    int maxSize = atoi(argv[2]);
	int numbersSize;
	int changes,aux;


	printf("MAX SIZE  %d \n",maxSize);
	numbersSize = readNumbersFromFile(argv[1], maxSize, &numberList);	
	printList(numberList, numbersSize);
	
	//Init sorting
	maxHeap(&numberList, numbersSize); // Get a max heap
	int auxNumbersSize = numbersSize;

	for(int i = numbersSize-1; i > 0; i--){
		int aux = numberList[0];
		numberList[0] = numberList[i]; // Swap root vs i node
		numberList[i] = aux;
		maxHeapify(&numberList,0, --auxNumbersSize); // call to heapify to ensure  the heap is a max heap 
	}
	//End sorting

	printList(numberList, numbersSize);
	free(numberList);
	return 0;
}
