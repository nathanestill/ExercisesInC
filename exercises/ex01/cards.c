/*
@author: Nathan Estill
C program that asks the user for a card and prints out a running count of the deck's overall value for Blackjack.
*/
#include <stdio.h>
#include <stdlib.h>

void getCardName(char *cardName);
int getCardValue(char cardName[3]);
void updateCount(int val);
int getLoopFlag(char card);

int main()
{
	char cardName[3];
	int val;
	do {
		char *cardPointer = cardName;
		getCardName(cardPointer);
		val = 0;
		val = getCardValue(cardName);
		if(val == -1){
			continue;
		}
		updateCount(val);
	} while (getLoopFlag(cardName[0]));
	return 0;
}

/*
Asks the user for a card name and stores the name.

cardName: place where the name is stored
*/
void getCardName(char *cardName){
	puts("Enter the card name: ");
	scanf("%2s", cardName);
}

/*
Returns the value associated with the inputted card name. If the answere is invalid, it will return -1.

cardName[3]: String where the card name is stored
val: value that each card has
*/
int getCardValue(char cardName[3]){
	int val = 0;
	switch(cardName[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			val = -1;
			break;
		default:
			val = atoi(cardName);
			if ((val < 1) || (val > 10)) {
				puts("I don't understand that value!");
				val = -1;
			}
	}
	return val;
}

/*
Updates and prints the current count of the deck.

val: the value of the most recent card.
*/
void updateCount(int val){
	static int count = 0;
	if ((val > 2) && (val < 7)) {
		count++;
	} else if (val == 10) {
		count--;
	}
	printf("Current count: %i\n", count);
}
/*
Returns the flag of when to stop the loop, if the user entered 'X'

card: the first character of the inputed card.
*/
int getLoopFlag(char card){
	return (card != 'X');
}