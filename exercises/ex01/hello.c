#include <stdio.h>

int main() {
	int x = 5;
	int y = x + 1;
    printf("%d\n",y);
    return 0;
}

/*
Ex 1. 	
subq	$16, %rsp
movl	$5, -4(%rbp)
seems to make the int x = 5;

Ex 2.
I think that the program ignores making x as it is not relevent later.

Ex 3.
Printing x makes the code to run it show back up.

Ex 4.
I think that it just computes the value of y and ignores x.
I think optimization just ignores irrelevant code and adjusts relevent existing code.
