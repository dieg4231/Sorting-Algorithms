#include <stdio.h>
#include <stdlib.h>

void printList(int *numberList, int size){
	for(int i = 0 ; i < size; i++)
		printf("%d ",numberList[i]);	
	printf("\n");
}

int  readNumbersFromFile( char *fileName, int  maxSize, int **numberList ){
	FILE *file;
	int count = 0;
	file = fopen(fileName,"r");
	printf("Reading file ... \n");
	if(file == NULL){
		printf("FILE ERROR\n");
		return 1;
	}

	*numberList = (int *)malloc(maxSize * sizeof(int) );

	while(fscanf(file,"%d", (*numberList)+count   ) != EOF  && count < maxSize  )
		count++;
	
	fclose(file);
	printf("Reading file DONE\n");
	printf("All numbers to sort: %d \n",count );
	
	return count;
}