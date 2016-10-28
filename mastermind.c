#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int compare(int number[], char guess[]);
int user_input(int number[]);

int main(void)
{
	int guess_count = 0;
	int number[4];
	srand(time(NULL));
	for(int i = 0; i < 4 ; ++i){
		number[i] = rand() % 10;
	}
	guess_count = user_input(number);
	printf("Congratulations!  You guessed the correct number in %d "
		   "attempts!\n", guess_count);



}

//TODO: to fix this garbage check to see if the numbers are equal in this function to not do the compare, will probably simplify things but confuse other stuff
int user_input(int number[])
{
	char guess[8];
	int cont = 1;
	int guess_count = 0;

	while(cont){
		printf("The number is %d%d%d%d \n", number[0],number[1],number[2],number[3]);
		printf("Enter your guess: ");
		fgets(guess, sizeof(guess), stdin);
		if(strlen(guess) == 5){
			//Turns the unicode character to it's appropiate number
			guess[4] = '\0';
			for(int i = 0; i < 4; ++i){
				guess[i] -= '0';
			}
			++guess_count; 
			cont = compare(number, guess);
		}
		else{
			printf("Character must be 4 digits\n");
		}

	}
	return guess_count;


}


int compare(int number[], char guess[])
{
	int red = 0;
	int white = 0;
	int mask[] = {0,0,0,0};
	int cont;

	//Tests to see if the numbers are equal before running other logic
	for(int i = 0; i < 4; ++i){
		if(number[i] != guess[i]){
			cont = 1;
		}
		else{
			cont = 0;
		}
	}
	//Tests for reds, and set mask position to 1 to make that digit off limits
	for(int i = 0; i < 4; ++i){
		if(number[i] == guess[i]){
			++red;
			mask[i] = 1;
		}
	}
	//Tests for whites
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if((number[j] == guess[i]) && (mask[i] == 0)){
				++white;
			}
		}
	}
	printf("%d red, ", red);
	printf("%d white\n", white);
	return cont;

}



