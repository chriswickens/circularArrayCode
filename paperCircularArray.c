#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 5

typedef struct CircularArray
{
	int* array;
	int read;
	int write;

} CircularArray;


void initializeCircularArray(CircularArray* arrayToInitialize)
{
	CircularArray* newArray = (CircularArray*)malloc(sizeof(CircularArray));
	if (newArray == NULL)
	{
		printf("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	newArray->array = (int*)malloc(ARRAY_MAX_SIZE * sizeof(int));
	newArray->read = 0;
	newArray->write = 0;
}

int main(void)
{
	CircularArray* theArray = NULL;
	initializeCircularArray(&theArray);


	return 0;
}