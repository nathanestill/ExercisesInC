/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;
void printAddress();
int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(17);
    void *r = malloc(17);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("q points to %p\n", q);
    printf ("r points to %p\n", r);
    printf ("s points to %p\n", s);
    printAddress();
    return 0;
}
void printAddress(){
	int var3 = 5318008;
	printf("Address of var3 is %p\n", &var3);	
}

// 6. The difference is 32
