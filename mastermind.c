#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int compare(int number[], int guess[]);
void user_input(int *px);
int in_intarray(int a, int b[], int index);

int main(void)
{
	int cont = 1;
	int guess_count = 0;
	int number[4] = {8,2,4,2};
	int guess[4], *guess_ptr;
	guess_ptr = guess;

	srand(time(NULL));

	for(int i = 0; i < 4 ; ++i){
		number[i] = rand() % 10;
	}



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

/**
*	This function asks for user input appropiate for the program, handles
*		error checking ensuring the user is inputting valid guesses, and
*		convers the char type inputs to an int array
*
*	The user_input() function takes a pointer from the main() function
*		so that it can pass back each index of the array back so the main()
*		function can handle most of the program flow logic.
*/
void user_input(int *px)
{

	char guess[32];

	while(1){
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
			break;
		}
		else{
			printf("Character must be 4 digits\n");
		}
	}
}


/**
*	This function takes two int arrays and determines if indexes have the 
*		same value (reds) or if an index contains a value in the array,
*		but not of the same index (whites) in addition, because 
*		of the rules of a game, a correctly checked number does not evalute
*		positively being "consumed."
*	
*	The function returns a value of 0 when number and guess are exactly the same
*		letting the program know to continue because the user has won
*
*	TODO: Remove reds from valid guesses and just find the amount of reds
*		that are also whites and subtract that from the white count
*/
int compare(int number[], int guess[])
{

	int cont = 0;

	//Tests to see if the numbers are equal before running other logic
	for(int i = 0; i < 4; ++i){
		if(number[i] != guess[i]){
			cont = 1;
		}
	}

	int red = 0;
	int white = 0;
	int valid_guesses[32];
	int valid_guesses_size = 0;

	if(cont == 1){
		//Tests for reds, adds valid values to valid guesses "consuming" the digit
		for(int i = 0; i < 4; ++i){
			if(number[i] == guess[i]){
				++red;
				//Assigning valid_guesses array with a "consumed" integer
				valid_guesses[valid_guesses_size] = guess[i];
				//Incrementing the size for in_intarray() function
				++valid_guesses_size;
			}
		}
		//Tests for whites, does the same thing as above for valid values
		for(int i = 0; i < 4; ++i){
			if(in_intarray(guess[i], number, 4) == 1){
				if(in_intarray(guess[i], valid_guesses, valid_guesses_size) == 0){
						++white;
						valid_guesses[valid_guesses_size] = guess[i];
						++valid_guesses_size;			
				}
			}	
		}
		printf("%d red, ", red);
		printf("%d white\n", white);
		return 1;
	}
	else{
		return 0;
	}
}


/**
*	Function takes in a array, and int, and a index 
*		number (how many elements in the array) and returns
*		one if that int is found anywhere in the array
*		zero if it doesn't
*/
int in_intarray(int a, int b[], int index)
{
	int r = 0;
	for(int i = 0; i < index; ++i){
		if(b[i] == a){
			r = 1;
		}
	}
	return r;
}




