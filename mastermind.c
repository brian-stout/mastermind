#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void compare(int number[], int guess[]);

int main(void)
{
	int number[4];
	srand(time(NULL));
	for(int i = 0; i < 4 ; ++i){
		number[i] = rand() % 10;
	}
	number[0] = 2;
	number[1] = 3;
	number[2] = 4;
	number[3] = 5;
	int guess[] = {2,3,0,0};
	compare(number, guess);


}


/*
	while(game == 1){
		char guess[8];
		printf("Enter your guess: ");
		fgets(guess, sizeof(guess), stdin);
		if(strlen(guess) != 5){
			printf("\nEnter a four digit number \n");
		}
		else{
			buf[4] = '\0';
		}
	
}
*/

void compare(int number[], int guess[])
{
	int red = 0;
	int white = 0;
	for(int i = 0; i < 4; ++i){
		if(number[i] == guess[i]){
			++red;
		}
	}
	printf("%d red, ", red);
	
}



