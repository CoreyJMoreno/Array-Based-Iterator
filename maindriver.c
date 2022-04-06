// header files
#include "IteratorUtility.h"

// constant definitions
const int MAX_ARRAY_CAPACITY = 100;

// prototypes

// main function
int main( int argc, char *argv[] )
   {
    IteratorType iterator;
    int value, index, numItems = 8;

    // seed random generator
    srand( time( NULL ) );

    // set title
    printf( "\nIterator Test Program\n" );
    printf(   "=====================\n" );

    // initialize iterator
    initializeIterator( &iterator );

    // set values at front
    printf( "\nSetting values at front\n" );
    for( index = 0; index < numItems; index++ )
       {
        value = rand() % 100;

        printf( "\nSetting: %d\n", value );

        insertAtFront( &iterator, value );

        displayIterator( &iterator );

       }

    // set values at end
    printf( "\n\nSetting values at end\n" );
    for( index = 0; index < numItems; index++ )
       {
        value = rand() % 100;

        printf( "\nSetting: %d\n", value );

        insertAtEnd( &iterator, value );

        displayIterator( &iterator );
       }

    // moving right/next
    printf( "\nMoving right/next\n" );
    for( index = 0; index < numItems; index++ )
       {
        moveNext( &iterator );

        displayIterator( &iterator );
       }

    // move to end
    printf( "\nSetting to Last\n" );
    setToLast( &iterator );
    displayIterator( &iterator );

    // moving left/prev
    printf( "\nMoving left/prev\n" );
    for( index = 0; index < numItems; index++ )
       {
        movePrev( &iterator );

        displayIterator( &iterator );
       }

    // removing some values
    printf( "\nRemoving some values\n" );
    for( index = 0; index < numItems + 1; index++ )
       {
        value = removeAtCurrent( &iterator );

        printf( "Removing: %d\n", value );

        displayIterator( &iterator );
       }

    clearIterator( &iterator );

    return 0;
   }
