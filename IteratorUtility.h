#ifndef ITERATOR_UTILITY_H
#define ITERATOR_UTILITY_H

// header files
#include <stdlib.h> // for malloc, free
#include <stdio.h>  // for printf
#include <math.h>   // for srand/rand
#include <time.h>   // for srand
#include "StandardConstants.h"

// constants
extern const int NOT_FOUND;

// structure definition
typedef struct IteratorStruct
   {
    int *array;
    int capacity;
    int size;
    int currentIndex;

   } IteratorType;

/*
Name: checkForResize
Process: checks for need to resize (increase capacity of) array,
         if necessary, creates new array with double the previous capacity,
         updates array, then returns original memory to OS
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: malloc, sizeof, free
*/
void checkForResize( IteratorType *iterator );

/*
Name: clearIterator
Process: clears all data in Iterator, returns memory to OS
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: free
*/
void clearIterator( IteratorType *iterator );

/*
Name: copyIterator
Process: copies all parts of iterator,
         creates new iterator array using dynamic memory,
         copies array
Function input/parameters: source Iterator data (Iterator *)
Function output/parameters: destination Iterator data (Iterator *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: malloc, sizeof
*/
void copyIterator( IteratorType *destIterator,
                                              const IteratorType *srcIterator );

/*
Name: displayIterator
Process: displays iterator data from beginning to end;
         shows current index within brackets
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: nFone
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: printf
*/
void displayIterator( IteratorType *iterator );

/*
Name: getValueAtCurrent
Process: returns the value at the current location in the iterator
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: none
Function output/returned: value at current index (int)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
int getValueAtCurrent( IteratorType *iterator );

/*
Name: hasNext
Process: reports if current index is not at the last element location,
         must be one line of code
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: none
Function output/returned: result of specified test (bool)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
bool hasNext( IteratorType *iterator );

/*
Name: hasPrev
Process: reports if current location is not at the first element location,
         must be one line of code
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: none
Function output/returned: result of specified test (bool)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
bool hasPrev( IteratorType *iterator );


/*
Name: initializeIterator
Process: initializes all data in Iterator,
         initializes array to DEFAULT_CAPACITY initial capacity
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: malloc
*/
void initializeIterator( IteratorType *iterator );

/*
Name: insertAtCurrent
Process: inserts value at current location,
         moves subsequent list up,
         maintains current location where new value was inserted
Function input/parameters: Iterator data (Iterator *), new value (int)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: checkForResize
*/
void insertAtCurrent( IteratorType *iterator, int newValue );

/*
Name: insertAtEnd
Process: inserts value at end of list,
         no change to current location
Function input/parameters: Iterator data (Iterator *), new value (int)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: checkForResize
*/
void insertAtEnd( IteratorType *iterator, int newValue );

/*
Name: insertAtFront
Process: inserts value at front of list,
         no change to current location
Function input/parameters: Iterator data (Iterator *), new value (int)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: checkForResize
*/
void insertAtFront( IteratorType *iterator, int newValue );

/*
Name: isEmpty
Process: checks for iterator array empty, if it is, returns true,
         otherwise returns false,
         must be one line of code
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: none
Function output/returned: result of specified test (bool)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
bool isEmpty( IteratorType *iterator );

/*
Name: moveNext
Process: moves iterator to the next location in the list (aka moveRight)
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: result of specified operation (bool)
Device input/file: none
Device output/monitor: none
Dependencies: hasNext
*/
bool moveNext( IteratorType *iterator );

/*
Name: movePrev
Process: moves iterator to the previous location in the list (aka moveLeft)
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: result of specified operation (bool)
Device input/file: none
Device output/monitor: none
Dependencies: hasPrev
*/
bool movePrev( IteratorType *iterator );

/*
Name: removeAtCurrent
Process: removes value if accessible, returns,
         current location remains the same,
         if data not accessible, returns NOT_FOUND,
         if last item removed, must reset iterator location
         to new last item
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: value removed from list (int)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
int removeAtCurrent( IteratorType *iterator );

/*
Name: setToFirst
Process: if data is accessible, sets current location to first element location,
         returns true, otherwise returns false
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: result of specified operation (bool)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
bool setToFirst( IteratorType *iterator );

/*
Name: setToLast
Process: if data is accessible, sets current location to last element location,
         returns true, otherwise returns false
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: result of specified operation (bool)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
bool setToLast( IteratorType *iterator );

#endif   // IteratorUtility.h


