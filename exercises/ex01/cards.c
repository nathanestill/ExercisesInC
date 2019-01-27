#include <stdio.h>
#include <stdlib.h>

int getCardValue(char cardName[3]);
void updateCount(int val);
int main()
{
	char cardName[3];
	int count = 0;
	do {
		puts("Enter the cardName: ");
		scanf("%2s", cardName);
		int val = 0;
		val = getCardValue(cardName);
		if(val == -1){
			continue;
		}
		updateCount(val);
	} while (cardName[0] != 'X');
	return 0;
}
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
void updateCount(int val){
	static int count = 0;
	if ((val > 2) && (val < 7)) {
		count++;
	} else if (val == 10) {
		count--;
	}
	printf("Current count: %i\n", count);
}