// header files
#include <stdlib.h> // for malloc, free
#include <stdio.h>  // for printf
#include <math.h>   // for srand/rand
#include <time.h>   // for srand
#include "StandardConstants.h"
#include "IteratorUtility.h"

// constants
const int NOT_FOUND = -99999;
const int DEFAULT_CAPACITY = 8;


void checkForResize( IteratorType *iterator )
    {
    // initialize variables / array
    int index;
    int *tempArray;

    // check if size is the same as capacity
    if( iterator->size == iterator->capacity)
        {
        // double the capacity
        iterator->capacity *= 2;

        // allocate memory to temporary array
        tempArray = (int *)malloc( sizeof(int) * iterator->capacity);

        // loop until end of array
        for(index = 0; index < iterator->size; index++)
            {
            // set temp array to the old array
            tempArray[index] = iterator->array[index];
            }
        // free old array
        free(iterator->array);

        // set old array to new array
        iterator->array = tempArray;
        }
    }

void clearIterator( IteratorType *iterator )
    {
    // free memory from the array
    free(iterator->array);

    // set capacity, size and current index to 0
    iterator->capacity = 0;
    iterator->size = 0;
    iterator->currentIndex = 0;
    }

void copyIterator( IteratorType *destIterator,
                                              const IteratorType *srcIterator )
    {
    // allocate memory to destination array
    destIterator = (IteratorType *)malloc( sizeof ( int ) );

    // set destination array to source array
    destIterator->array = srcIterator->array;

    // set all attributes of destination array to source arrau
    destIterator->currentIndex = srcIterator->currentIndex;
    destIterator->size = srcIterator->size;
    destIterator->capacity = srcIterator->capacity;
    }

void displayIterator( IteratorType *iterator )
    {
    // initialize variables
    int counter;

    // print title of display
        // function: printf
    printf("\nIterator Display\n");

    // loop to the end of the array
    for(counter = 0; counter <= iterator->size - 1; counter++ )
        {
        // check if the counter is the current index
        if(iterator->currentIndex == counter)
            {
            // if so, print brackets around current index
                // function: printf
            printf("[%d] ", iterator->array[counter]);
            }
        else
            {
            // if not current index, print integer normally
                // function: printf
            printf("%d ", iterator->array[counter]);
            }
        }
    // print endLine
        // function: printf
    printf("\n");
    }

int getValueAtCurrent( IteratorType *iterator )
    {
    // return the current index from iterator
    return iterator->currentIndex;
    }

bool hasNext( IteratorType *iterator )
    {
    // return result of current index being less than size - 1
    return iterator->currentIndex < iterator->size - 1;
    }

bool hasPrev( IteratorType *iterator )
    {
    // return result of current index being greater than 0
    return iterator->currentIndex > 0;
    }


void initializeIterator( IteratorType *iterator )
    {
    // set capacity to default (8)
    iterator->capacity = DEFAULT_CAPACITY;

    // set currentIndex and size to 0
    iterator->currentIndex = 0;
    iterator->size = 0;

    // allocate memory to array times size of default (8)
    iterator->array = ( int * )malloc( DEFAULT_CAPACITY * sizeof ( int ) );
    }

void insertAtCurrent( IteratorType *iterator, int newValue )
    {
    // initialize variables
    int index;

    // check if iterator needs a resize
        // function: checkForResize
    checkForResize(iterator);

    // set arrays current index to the new value
    iterator->array[iterator->currentIndex] = newValue;

    // loop to the end of the array
    for(index = 0; index < iterator->size; index++)
        {
        // set every index down one in the array
        iterator->array[iterator->capacity] = iterator->array[iterator->capacity + 1];
        }
    }

void insertAtEnd( IteratorType *iterator, int newValue )
    {
    // check if resize is needed
        // function: checkForResize
    checkForResize(iterator);

    // add one more space to the size
    iterator->size = iterator->size + 1;

    // set the last spot of array to new value
    iterator->array[iterator->size - 1] = newValue;
    }


void insertAtFront( IteratorType *iterator, int newValue )
    {
    // initialize variables
    int index;

    // add one more space to the size
    iterator->size = iterator->size + 1;

    // check if resize is needed
        // functionL checkForResize
    checkForResize(iterator);

    // loop to the end of the array
    for(index = iterator->size - 1; index > 0; index--)
        {
        // set each index up one in the array
        iterator->array[index] = iterator->array[index - 1];
        }
    // set first index to the new value
    iterator->array[0] = newValue;
    }

bool isEmpty( IteratorType *iterator )
    {
    // return result of size being greater than 0
    return iterator->size > 0;
    }

bool moveNext( IteratorType *iterator )
    {
    // check if next spot is open
    if(hasNext(iterator))
        {
        // set current index equal to the index ahead of it
        return (iterator->currentIndex = iterator->currentIndex + 1);
        }
    else
        {
        // if no spot is open, return false
        return false;
        }
    }

bool movePrev( IteratorType *iterator )
    {
    // check if previous spot is open
    if(hasPrev(iterator))
        {
        // set previous index equal to the current index
        return (iterator->currentIndex = iterator->currentIndex - 1);
        }
    else
        {
        // if previous spot not available, return false
        return false;
        }
    }

int removeAtCurrent( IteratorType *iterator )
    {
    // initialize variables
    int index;
    int removed;

    // check if elements are in array
    if(iterator->size > 0)
        {
        // set current index to removed variable
        removed = iterator->array[iterator->currentIndex];

        // check if current index is the same as size - 1
        if(iterator->currentIndex == iterator->size - 1)
            {
            // set current index to the index before it
            iterator->currentIndex = iterator->currentIndex - 1;
            }
        else
            {
            // loop to the end of the array from current index
            for(index = iterator->currentIndex; index < iterator->size - 1; index++)
                {
                // set the array index to the index ahead of it
                iterator->array[index] = iterator->array[index + 1];
                }
            }
        // decrement size
        iterator->size = iterator->size - 1;

        // return valued that was removed
        return removed;
        }
    // if data not found, returns NOT_FOUND
    return NOT_FOUND;
    }

bool setToFirst( IteratorType *iterator )
    {
    // check if data is in array
    if(iterator->size > 0)
        {
        // set current index to the front of the array
        iterator->currentIndex = iterator->array[0];
        // return data is accessible
        return true;
        }
    else
        {
        // if data not accessible, return false
        return false;
        }
    }

bool setToLast( IteratorType *iterator )
    {
    // check if data is in array
    if(iterator->size > 0)
        {
        // set current index to the last item in array
        iterator->currentIndex = iterator->size - 1;
        // return true since data was accessible
        return true;
        }
    else
        {
        // if data is not accessible, return false
        return false;
        }
    }




