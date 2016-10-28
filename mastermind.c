#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int compare(int number[], int guess[]);
void user_input(int *px);

int main(void)
{
	int cont = 1;
	int guess_count = 0;
	int number[4] = {8,0,6,8};
	int guess[4], *guess_ptr;
	guess_ptr = guess;
/*
	srand(time(NULL));

	for(int i = 0; i < 4 ; ++i){
		number[i] = rand() % 10;
	}

*/

	while(cont){
		++guess_count;
		user_input(guess_ptr);
		printf("%d%d%d%d\n", guess[0], guess[1], guess[2], guess[3]);
		cont = compare(number, guess);
	}

//TODO: Fix the grammar and stuffs
	printf("Congratulations!  You guessed the correct number in %d "
		   "attempts!\n", guess_count);

 

}

void user_input(int *px)
{
	char guess[8];
	int cont = 1;

	while(cont){
		printf("Enter your guess: ");
		fgets(guess, sizeof(guess), stdin);
		if(strlen(guess) == 5){
			//Turns the unicode character to it's appropiate number
			guess[4] = '\0';
			for(int i = 0; i < 4; ++i){
				guess[i] -= '0';
			}
			//assigns the int array's ptr that was passed in the function the correct values
			px[0] = guess[0];
			px[1] = guess[1];
			px[2] = guess[2];
			px[3] = guess[3];
			cont = 0;
		}
		else{
			printf("Character must be 4 digits\n");
		}
	}
}


int compare(int number[], int guess[])
{
	int red = 0;
	int white = 0;
	int mask[] = {0,0,0,0};
	int cont = 0;


	//Tests to see if the numbers are equal before running other logic
	for(int i = 0; i < 4; ++i){
		if(number[i] != guess[i]){
			cont = 1;
		}
	}
	if(cont == 1){
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
				//Prevents reds from being counted as whites and sets a mask for that index
				if(j != i && number[i] == guess[j] && mask[i] == 0){
					white += 1;
					mask[i] = 1;
					break;
				}
				//Uses the index set previously to avoid whites from being counted again.
				else if(j == i && number[i] == guess[j] && mask[i] == 0){
					break;
				}
			}
		}
		printf("Number: %d%d%d%d \n", number[0],number[1],number[2],number[3]);
		printf("Guess:  %d%d%d%d \n", guess[0],guess[1],guess[2],guess[3]);
		printf("%d red, ", red);
		printf("%d white\n", white);
		return 1;
	}
	else{
		return 0;
	}
}



