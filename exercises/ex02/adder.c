/* 
@author: Nathan Estill
This program adds up 10 numbers that the user enters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int addNumbers(int* numbers, int counter);
int getNumbers(int* numbers);
int main(){
	int values[10];
	int* numbers = values;
	int counter = getNumbers(numbers);
	int sum = addNumbers(numbers, counter);
	printf("%d\n", sum);
}	

/* 
Collects the numbers that the user enters and stores them in the array pointed to.

numbers: a pointer that points to a allocated array.
*/
int getNumbers(int* numbers){
	printf("Enter up to 10 numbers to be added(Ctrl-D to compute):\n");
	int counter = 0;
	int DFlag = 0;
	do{
		char input[10];
		if (fgets(input, sizeof(input)+1,stdin) == NULL){
			DFlag = 1;
		}
		else{
			size_t len = strlen(input);
			if(input[len-1] != '\n'){
				printf("Woah there boy scout, you entered too many digits. Try again.\n");
			}
			else if(counter > 9){
				printf("Sorry bud, you can't enter any more numbers. Hit Ctrl-D to exit.\n");
			}
			else{
				int thisNumber = atoi(input);
				if(thisNumber == 0){
					printf("Sorry bro, entering 0 or a string doesn't do anything, try again.\n");
				}
				else{
					numbers[counter] = thisNumber;
					counter++;
				}
			}
		}
	} while(!DFlag);
	return counter;
}

/*
Adds the numbers in the array that is pointed to.

numbers: pointer to an array of numbers to be added
counter: counter that tell the program how many numbers are in the array
*/
int addNumbers(int* numbers, int counter){
	int i;
	int sum = 0;
	for(i = 0; i < counter; i++){
		sum += numbers[i];
	}
	return sum;
}
