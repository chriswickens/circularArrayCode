#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_MAX_SIZE 5

typedef struct CircularArray
{
	int array[ARRAY_MAX_SIZE];
	int elementCount;
	int read;
	int write;

} CircularArray;

bool isEmpty(CircularArray* arrayToCheck)
{
	if (arrayToCheck->elementCount == 0)
	{
		printf("Array is empty!\n");
		return true;
	}

	return false;
}

bool isFull(CircularArray* arrayToCheck)
{
	if (arrayToCheck->elementCount == ARRAY_MAX_SIZE)
	{
		printf("Array is full!\n");
		return true;
	}
	return false;
}

CircularArray* initializeCircularArray()
{
	CircularArray* newArray = (CircularArray*)malloc(sizeof(CircularArray));
	if (newArray == NULL)
	{
		printf("Error allocating memory\n");
		exit(EXIT_FAILURE);
	}

	newArray->elementCount = 0;
	newArray->read = 0;
	newArray->write = 0;
	return newArray;
}

void insertValueIntoArray(CircularArray* arrayToAddTo, int newValue)
{
	if (isFull(arrayToAddTo))
	{
		return;
	}

	arrayToAddTo->elementCount++;
	arrayToAddTo->array[arrayToAddTo->write] = newValue;
	arrayToAddTo->write = (arrayToAddTo->write + 1) % ARRAY_MAX_SIZE;
}

int dequeueFromArray(CircularArray* arrayToDequeue)
{
	if (isEmpty(arrayToDequeue))
	{
		return -1;
	}
	int valueToDequeue = arrayToDequeue->array[arrayToDequeue->read];
	arrayToDequeue->elementCount--;
	arrayToDequeue->read = (arrayToDequeue->read + 1) % ARRAY_MAX_SIZE;
	return valueToDequeue;
}

void printCircularArray(CircularArray* arrayToPrint)
{
	if (isEmpty(arrayToPrint))
	{
		return;
	}
	int currentIndex = arrayToPrint->read;
	int count = 0;
	while (count < arrayToPrint->elementCount)
	{
		printf("Circular Index: %d, Value at index: %d\n", currentIndex, arrayToPrint->array[currentIndex]);
		count++;
		currentIndex = (currentIndex + 1) % ARRAY_MAX_SIZE;
	}
}

int main(void)
{
	CircularArray* theArray = initializeCircularArray();

	isEmpty(theArray);
	isFull(theArray);
	printf("\n");

	insertValueIntoArray(theArray, 100);
	insertValueIntoArray(theArray, 200);
	insertValueIntoArray(theArray, 300);
	insertValueIntoArray(theArray, 400);
	insertValueIntoArray(theArray, 500);

	printf("After filling array: \n");
	printCircularArray(theArray);

	printf("\nInsertion attempted on full array: \n");
	insertValueIntoArray(theArray, 600);
	printCircularArray(theArray);

	printf("\nDequeue 100: \n");
	printf("Value dequeued: %d\n", dequeueFromArray(theArray));
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 5010);
	printf("\nAdded a new element (5010): \n");
	printCircularArray(theArray);
	
	printf("\nDequeue 1: \n");
	printf("%d\n", dequeueFromArray(theArray));
	printf("Out 4: \n");
	printCircularArray(theArray);
	printf("Dequeue 1: \n");
	printf("%d\n", dequeueFromArray(theArray));
	printf("Out 4: \n");
	printCircularArray(theArray);
	printf("Dequeue 1: \n");
	printf("%d\n", dequeueFromArray(theArray));
	printf("Out 4: \n");
	printCircularArray(theArray);
	printf("Dequeue 1: \n");
	printf("%d\n", dequeueFromArray(theArray));
	printf("Out 4: \n");
	printCircularArray(theArray);
	printf("Dequeue 1: \n");
	printf("%d\n", dequeueFromArray(theArray));
	printf("Out 4: \n");
	printCircularArray(theArray);
	printf("Dequeue 1: \n");
	printf("%d\n", dequeueFromArray(theArray));
	printf("Out 4: \n");
	printCircularArray(theArray);
	insertValueIntoArray(theArray, 100);
	printf("Out 4: \n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 200);
	printf("Out 4: \n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 300);
	printf("Out 4: \n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 400);
	printf("Out 4: \n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 500);
	printf("Out 4: \n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 600);
	printf("Out 4: \n");
	printCircularArray(theArray);

	free(theArray); // Free allocated memory
	return 0;
}
