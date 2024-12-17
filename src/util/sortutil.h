#ifndef sortutil
#define sortutil
#define POSTFIX_SIZE 8
#define POSTFIX "_sorted"


typedef struct sortingParams {
    int maxItems;    /*The max values to read form file*/
	int numItems;    /*Not equal to maxSize  if file contains fewers values than maxSize*/
	char* filePath;
}  sortingParams; 

int inputArgsHandler(int argc, char **argv, sortingParams *sp );
void printList(int *numberList, int size);
int printList2File(int *numberList, sortingParams *sp);
int  readNumbersFromFile( sortingParams *sp, int **numberList );

#endif
