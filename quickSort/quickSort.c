#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../util/nums2sort.h"

void maxHeapify(int **numberList, int index,int numbersSize){
	int l,r,largest;
	
	if (index == 0)
	{
		l = 1;
		r = 2;
	}else{

		l = index << 1;
		r = (index << 1) +1;
	}	
	//printf("--------pre----numbersSize = %d indx = %d  l = %d r = %d---\n",numbersSize,index,l,r );

	//printList(*numberList, numbersSize);

	if(l < numbersSize && (*numberList)[l] > (*numberList)[index])
		largest = l;
	else
		largest = index;
	if(r < numbersSize && (*numberList)[r] > (*numberList)[largest])
		largest = r;
	if(largest != index){
		int aux = (*numberList)[index];
		(*numberList)[index] = (*numberList)[largest];
		(*numberList)[largest] = aux;
		maxHeapify(numberList,largest ,numbersSize);
	}
	

	//printf("--------post-------\n");
	
	///printList(*numberList, numbersSize);

	return;
}

void maxHeap(int **numberList,int numbersSize){

	for(int i = floor(numbersSize/2); i >=0 ;i--)
		maxHeapify(numberList,i,numbersSize);

	return;
}

int main(int argc, char **argv){
	
	int *numberList = NULL;
        int maxSize = atoi(argv[2]);
	int numbersSize;
	int changes,aux;

	printf("MAX SIZE  %d \n",maxSize);

	numbersSize = readNumbersFromFile( argv[1], maxSize, &numberList );	
	printList(numberList, numbersSize);

	maxHeap(&numberList,numbersSize);
	int auxNumbersSize = numbersSize;
	for(int i = numbersSize; i > 0; i--){
		int aux = numberList[0];
		numberList[0] = numberList[i];
		numberList[i] = aux;
		maxHeapify(&numberList,0, --auxNumbersSize);

	}

	printList(numberList, numbersSize);
	free(numberList);
	return 0;
}
