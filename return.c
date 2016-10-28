#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void user_input(int *px);

int main(void)
{
	int guess_count = 0;
	int number[4] = {0,6,0,0};
	int guess[4], *guess_ptr;
	guess_ptr = guess;
	
/*
	srand(time(NULL));

	for(int i = 0; i < 4 ; ++i){
		number[i] = rand() % 10;
	}

*/
	user_input(guess_ptr);
	printf("guess[0] = %d\n", guess[0]);
	printf("guess[1] = %d\n", guess[1]);
	printf("guess[2] = %d\n", guess[2]);
	printf("guess[3] = %d\n", guess[3]);
	printf("Congratulations!  You guessed the correct number in %d "
		   "attempts!\n", guess_count);



}

//TODO: to fix this garbage check to see if the numbers are equal in this function to not do the compare, will probably simplify things but confuse other stuff
void user_input(int *px)
{
	char guess[8];
		printf("%p\n", (void *)px);


		printf("Enter your guess: ");
		fgets(guess, sizeof(guess), stdin);
		if(strlen(guess) == 5){
			printf("%ld\n", sizeof(guess));
			//Turns the unicode character to it's appropiate number
			guess[4] = '\0';
			for(int i = 0; i < 4; ++i){
				guess[i] -= '0';
			}
		}
		px[0] = guess[0];
		px[1] = guess[1];
		px[2] = guess[2];
		px[3] = guess[3];


			
}


