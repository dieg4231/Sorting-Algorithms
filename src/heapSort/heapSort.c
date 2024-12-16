#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../util/nums2sort.h"

void maxHeapify(int **numberList, int index, int numbersSize){
	
	int l,r,largest;	
	//Left and right index
	if (index == 0){
		l = 1;
		r = 2;
	}else{
		l = index << 1;
		r = l +1;
	}	

	//Debug for small list
	printf("--------pre----numbersSize = %d indx = %d  l = %d r = %d---\n",numbersSize,index,l,r );
	printList(*numberList, numbersSize);
	if( l < numbersSize && (*numberList)[l] > (*numberList)[index])
		largest = l;
	else
		largest = index;
	if( r < numbersSize && (*numberList)[r] > (*numberList)[largest])
		largest = r;
	if(largest != index){
		int aux = (*numberList)[index];
		(*numberList)[index] = (*numberList)[largest];
		(*numberList)[largest] = aux;
		maxHeapify(numberList, largest, numbersSize); // recursive  : D
	}
	
	return;
}

//Create a max heap
void maxHeap(int **numberList, int numbersSize){
	for(int i = floor( numbersSize / 2 ); i >= 0; i--)
		maxHeapify(numberList,i,numbersSize);
	return;
}

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
