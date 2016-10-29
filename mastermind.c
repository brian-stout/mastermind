#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int compare(int number[], int guess[]);

void user_input(int *px);

int in_intarray(int a, int b[], int index);


int main(void)
{

	//Sets the seed for the random number generator
	srand(time(NULL));

	//Randomly generates four digits 0-9 and assigns them to an int array
	int number[4];
	for(int i = 0; i < 4 ; ++i){
		number[i] = rand() % 10;
	}

	//The main logic for the program.  compare() returns a 0
	//Upon a correct guess
	int cont = 1;
	int guess_count = 0;
	int guess[4], *guess_ptr;
	guess_ptr = guess;

	while(cont){
		++guess_count;
		user_input(guess_ptr);
		cont = compare(number, guess);
	}

	//On the off chance you guess correctly the first time, this will fix it
	char grammar[] = "attempts!";
	if(guess_count == 1){
		grammar[7] = '!';
		grammar[8] = '\0';
	}

	printf("Congratulations!  You guessed the correct number in %d "
		   "%s\n", guess_count, grammar);
}


/**
*	This function asks for user input appropiate for the program, handles
*		error checking ensuring the user is inputting valid guesses, and
*		converts the char type inputs to an int array
*
*	The user_input() function takes a pointer from the main() function
*		so that it can pass back each index of the array back so the main()
*		function can handle most of the program flow logic.
*
*	The error handling logic was created with the aide of McMaster who
*		attributed the code to Liam's scribble on the white board. In
*		addition I added a check to see if a value is greater than 9
*		which means it's an ASCII Character or invalid input
*/
void user_input(int *px)
{

	char guess[32];

	while(1){
		printf("Enter your guess: ");
		fgets(guess, sizeof(guess), stdin);
		if(strlen(guess) != 5){
			printf("Invalid input!\n");
			while(guess[strlen(guess)-1] != '\n'){
				fgets(guess, sizeof(guess), stdin);
			}
			continue;
		}

		int alpha_flag = 0;

		//Turns the unicode character to it's appropiate number
		for(int i = 0; i < 4; ++i){
			guess[i] -= '0';
			//Tests to see if user inputed a char and if so let the program know
			if(guess[i] > 9){
				alpha_flag = 1;
			}
		}
		if(alpha_flag == 0){
			//assigns the int array's ptr that was passed in the function the correct values
			px[0] = guess[0];
			px[1] = guess[1];
			px[2] = guess[2];
			px[3] = guess[3];
			break;
		}
		else{
			printf("Invalid Input\n");
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
*
*
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
