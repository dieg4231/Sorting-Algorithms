#ifndef sortutil
#define sortutil

typedef struct sortingParams {
    int maxItems;    /*The max values to read form file*/
	int numItems;    /*Not equal to maxSize  if file contains fewers values than maxSize*/
	char* filePath;
}  sortingParams; 

int inputArgsHandler(int argc, char **argv, sortingParams *sp );
void printList(int *numberList, int size);
int  readNumbersFromFile( sortingParams *sp, int **numberList );

#endif
