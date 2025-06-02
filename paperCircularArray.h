#pragma once

/*
* Program: paperCircularArray.h
* Purpose: This is intended to show a basic circular array (buffer) and how it functions.
* This was originally coded as part of an extra credit assignment and it really helped me learn more about
* data structures and how memory is handled in C programs.
*
* Edits: This header file was created after the fact to bring the program in line with the standards that I learned
* after coding this program.
*/

/* 
* This value can be edited to allow for almost any size of buffer, since modulo operations to ensure the CircularArray data
* stays within the bounds of the size dictated here
*/

#define ARRAY_MAX_SIZE 5 // Defines the maximum size of the circular buffer

// The struct used as the buffer(CircularArray)
typedef struct CircularArray
{
	int array[ARRAY_MAX_SIZE];
	int elementCount;
	int read;
	int write;

} CircularArray;

// Function prototypes
CircularArray* initializeCircularArray();
bool isEmpty(CircularArray* arrayToCheck);
bool isFull(CircularArray* arrayToCheck);
void insertValueIntoArray(CircularArray* arrayToAddTo, int newValue);
int dequeueFromArray(CircularArray* arrayToDequeue);
void printCircularArray(CircularArray* arrayToPrint);
void searchCircularArray(CircularArray* arrayToSearch, int valueToFind);