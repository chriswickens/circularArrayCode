/*
* Program: paperCircularArray.c
* Purpose: This is intended to show a basic circular array (buffer) and how it functions.
* This was originally coded as part of an extra credit assignment and it really helped me learn more about
* data structures and how memory is handled in C programs.
* 
* Edits from the original code: The original code did not make use of .h files or function prototypes as this was not
* a requirement for that class at the time and I was still new to C coding. I have since gone back and created the necessary
* header file (paperCircularArray.h) to encapsulate the struct for the buffer and the macro for the ARRAY_MAX_SIZE and the necessary function prototypes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paperCircularArray.h"

// Initialize the CircularArray
CircularArray* initializeCircularArray()
{
	// Allocate memory for the CircularArray
	CircularArray* newArray = (CircularArray*)malloc(sizeof(CircularArray));

	// If the newArray is NULL, that means there was an error allocating memory
	if (newArray == NULL)
	{
		printf("Error allocating memory\n");
		exit(EXIT_FAILURE);
	}

	// Set the structure members to default values (0)
	newArray->elementCount = 0;
	newArray->read = 0;
	newArray->write = 0;
	return newArray;
}

// Checks if the passed in CircularArray is EMPTY
bool isEmpty(CircularArray* arrayToCheck)
{
	// If the elementCount is 0, the CircularArray is empty
	if (arrayToCheck->elementCount == 0)
	{
		printf("Array is empty!\n");
		return true;
	}

	// Otherwise the array is NOT empty
	return false;
}

// Checks if the passed in CircularArray is FULL
bool isFull(CircularArray* arrayToCheck)
{
	// If the elementCount is equal to the ARRAY_MAX_SIZE macro, it is full
	if (arrayToCheck->elementCount == ARRAY_MAX_SIZE)
	{
		printf("Array is full!\n");
		return true;
	}

	// Otherwise it is NOT full
	return false;
}

// Insert a value into the CircularArray
void insertValueIntoArray(CircularArray* arrayToAddTo, int newValue)
{
	// Check if the CircularArray is full (cannot insert a new value)
	if (isFull(arrayToAddTo))
	{
		return;
	}

	// Otherwise insert the new value:
	// Increase the element count
	arrayToAddTo->elementCount++;
	// Insert the newValue into the array using the arrays current "write" location
	arrayToAddTo->array[arrayToAddTo->write] = newValue;
	// Update the write location after the data has been added, ensure it is within the bounds of the array size
	arrayToAddTo->write = (arrayToAddTo->write + 1) % ARRAY_MAX_SIZE;
}

// Dequeue(remove) a value from the CircularArray
int dequeueFromArray(CircularArray* arrayToDequeue)
{
	// Check if the CircularArray is empty (isEmpty will show an error if needed)
	if (isEmpty(arrayToDequeue))
	{
		return -1;
	}

	// Otherwise, begin dequeue process
	// Get the value that will be dequeued based on the current CircularArray READ location
	int valueToDequeue = arrayToDequeue->array[arrayToDequeue->read];
	// Decrement the elementCount (since we are removing an value)
	arrayToDequeue->elementCount--;
	// Update the read location and ensure it is within the bounds of the array size
	arrayToDequeue->read = (arrayToDequeue->read + 1) % ARRAY_MAX_SIZE;
	return valueToDequeue;
}

// Print the CircularArray
void printCircularArray(CircularArray* arrayToPrint)
{
	// Check if the CircularArray is empty
	if (isEmpty(arrayToPrint))
	{
		return;
	}

	// Otherwise make a copy of the current index to use later
	int currentIndex = arrayToPrint->read;
	int count = 0;

	// Iterate over the values, as long as count is less than the number of elements
	while (count < arrayToPrint->elementCount)
	{
		// Print the index and the value stored there
		printf("Circular Index: %d, Value at index: %d\n", currentIndex, arrayToPrint->array[currentIndex]);
		count++; // Increment the count
		// Set the currentIndex to the next index location to print the next value, keep within bounds of array size
		currentIndex = (currentIndex + 1) % ARRAY_MAX_SIZE;
	}
}

// Search for a value in the CircularArray
void searchCircularArray(CircularArray* arrayToSearch, int valueToFind)
{
	// Check if the CircularArray is empty
	if (isEmpty(arrayToSearch))
	{
		return;
	}

	// Begin searching from the current read location
	int currentIndex = arrayToSearch->read;
	int count = 0;

	// Iterate over the values, as long as count is less than the number of elements
	while (count < arrayToSearch->elementCount)
	{
		// Check if the value at the current index is the same as the one passed in
		if (arrayToSearch->array[currentIndex] == valueToFind)
		{
			// Item was found
			printf("Found item at: %d\nValue being searched for: %d\nValue in array: %d", currentIndex, valueToFind, arrayToSearch->array[currentIndex]);
			return;
		}

		// Keep iterating by incrementing the count and the current index
		count++;
		currentIndex = (currentIndex + 1) % ARRAY_MAX_SIZE;
	}

	// If the value was not found
	printf("Value not found!\n");
}

// The main entry point for testing the CircularArray
int main(void)
{
	// Initialize the circular array
	CircularArray* theArray = initializeCircularArray();

	// Check if the array is empty
	isEmpty(theArray);

	// Check if the array is full
	isFull(theArray);
	printf("\n");

	// Inserting values
	insertValueIntoArray(theArray, 100);
	printf("Item 1 insertion:\n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 200);
	printf("Item 2 insertion:\n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 300);
	printf("Item 3 insertion:\n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 400);
	printf("Item 4 insertion:\n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 500);
	printf("Item 5 insertion:\n");
	printCircularArray(theArray);

	// Dequeue values
	printf("Dequeue 1: \n");
	printf("%d\n", dequeueFromArray(theArray));
	printCircularArray(theArray);
	printf("Dequeue 1: \n");
	printf("%d\n", dequeueFromArray(theArray));
	printCircularArray(theArray);

	printf("Dequeue 1: \n");
	printf("%d\n", dequeueFromArray(theArray));
	printCircularArray(theArray);

	// Insert more values
	insertValueIntoArray(theArray, 100);
	printf("Item 1 insertion:\n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 200);
	printf("Item 2 insertion:\n");
	printCircularArray(theArray);


	printf("Access item at index 4: %d\n", theArray->array[4]);

	insertValueIntoArray(theArray, 100);
	printf("Item 1 insertion:\n");
	printCircularArray(theArray);

	insertValueIntoArray(theArray, 200);
	printf("Item 2 insertion:\n");
	printCircularArray(theArray);


	/*
	* 
	* The lines below can be uncommented for more testing
	* 
	*/

	//printf("After filling array: \n");
	//printCircularArray(theArray);

	//printf("\nInsertion attempted on full array: \n");
	//insertValueIntoArray(theArray, 600);
	//printCircularArray(theArray);

	//printf("\nDequeue 100: \n");
	//printf("Value dequeued: %d\n", dequeueFromArray(theArray));
	//printCircularArray(theArray);

	//insertValueIntoArray(theArray, 5010);
	//printf("\nAdded a new element (5010): \n");
	//printCircularArray(theArray);
	//
	//printf("\nDequeue 1: \n");
	//printf("%d\n", dequeueFromArray(theArray));
	//printf("Out 1: \n");
	//printCircularArray(theArray);

	//printf("Dequeue 1: \n");
	//printf("%d\n", dequeueFromArray(theArray));

	//printf("Out 2: \n");
	//printCircularArray(theArray);

	//printf("Dequeue 1: \n");
	//printf("%d\n", dequeueFromArray(theArray));

	//printf("Out 3: \n");
	//printCircularArray(theArray);

	//printf("Dequeue 1: \n");
	//printf("%d\n", dequeueFromArray(theArray));

	//printf("Out 4: \n");
	//printCircularArray(theArray);

	//printf("Dequeue 1: \n");
	//printf("%d\n", dequeueFromArray(theArray));

	//printf("Out 5: \n");
	//printCircularArray(theArray);

	//printf("Dequeue 1: \n");
	//printf("%d\n", dequeueFromArray(theArray));
	//printf("Out 6: \n");
	//printCircularArray(theArray);

	//insertValueIntoArray(theArray, 100);
	//printf("Out 7: \n");
	//printCircularArray(theArray);

	//insertValueIntoArray(theArray, 200);
	//printf("Out 8: \n");
	//printCircularArray(theArray);

	//insertValueIntoArray(theArray, 300);
	//printf("Out 9: \n");
	//printCircularArray(theArray);

	//insertValueIntoArray(theArray, 400);
	//printf("Out 10: \n");
	//printCircularArray(theArray);

	//insertValueIntoArray(theArray, 500);
	//printf("Out 11: \n");
	//printCircularArray(theArray);

	//insertValueIntoArray(theArray, 600);
	//printf("Out 12: \n");
	//printCircularArray(theArray);

	//searchCircularArray(theArray, 400);

	free(theArray); // Free allocated memory
	return 0;
}
