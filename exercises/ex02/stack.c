/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
/*
1. It is intended to output a bunch of 42s I think
   I think that it will give random junk or error or something.
   The array that the pointer references is gone after the function ends so it should reference random stuff I think.
2. I do get a warning. It means that the stuff inside the address is deleted.
3. I think my initial guess is what's happening. It tries to reference a variable that no longer exists.
4. The same thing happens. But both addresses are the same address.
5. 
*/