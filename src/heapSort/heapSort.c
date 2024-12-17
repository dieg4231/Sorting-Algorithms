#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../util/sortutil.h"

void maxHeapify(int **numsPtr, int idx, int numItems){
	
	int l,r,largestIdx;	

	//Left and right idx
	if (idx == 0){
		l = 1;
		r = 2;
	}else{
		l = idx << 1;
		r = l +1;
	}	

	//Debug for small list
	//printf("--------pre----numItems = %d indx = %d  l = %d r = %d---\n",numItems,idx,l,r );
	//printList(*numsPtr, numItems);
	
	if( l < numItems && (*numsPtr)[l] > (*numsPtr)[idx]){
		largestIdx = l;
	}else{
		largestIdx = idx;
	}
		
	if( r < numItems && (*numsPtr)[r] > (*numsPtr)[largestIdx]){
		largestIdx = r;
	}

	if(largestIdx != idx){
		int aux = (*numsPtr)[idx];
		(*numsPtr)[idx] = (*numsPtr)[largestIdx];
		(*numsPtr)[largestIdx] = aux;
		maxHeapify(numsPtr, largestIdx, numItems); // recursive  : D
	}
	
	return;
}

//Create a max heap
void maxHeap(int **numsPtr, int numItems){
	for(int i = floor( numItems / 2 ); i >= 0; i--)
		maxHeapify(numsPtr,i,numItems);
	return;
}

int main(int argc, char **argv){
	
	int *numsPtr = NULL;  /*Pointer to numbers to sort*/
	int aux;
	sortingParams sp; //Struct type

	if(inputArgsHandler(argc, argv,&sp)){
		printf("Error: Wrong parameters\n");
		return 1;
	}

	printf("Max handle numbers:  %d \n",sp.maxItems);
	printf("Path:  %s \n",sp.filePath);

	numsPtr = (int *)malloc(sp.maxItems * sizeof(int) );
	if(numsPtr == NULL){
		printf("Error allocating  memory\n");
	}
	printf("Reading numbers from file... \n");
	readNumbersFromFile(&sp, &numsPtr );	
	//printList(numsPtr, sp.numItems);
	
	//Init heapSort
	printf("Heap sort working ...\n");
	maxHeap(&numsPtr, sp.numItems); // Get a max heap
	int auxNumItems = sp.numItems;

	for(int i = sp.numItems - 1; i > 0; i--){
		aux = numsPtr[0];
		numsPtr[0] = numsPtr[i]; // Swap root vs i node
		numsPtr[i] = aux;
		maxHeapify(&numsPtr,0, --auxNumItems); // call to heapify to ensure  the heap is a max heap 
	}
	//End sorting
	printf("Writing sorted list to file...\n");
	if(printList2File(numsPtr, &sp)){
		printf("Error Writing sorted numberts to file.\n");
	}
	printf("Done bye.\n");

	free(numsPtr);
	return 0;
}
