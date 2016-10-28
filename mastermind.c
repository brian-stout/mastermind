#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void compare(int number[], char guess[]);
int user_input(int number[]);

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
	printf("The number is %d%d%d%d \n", number[0],number[1],number[2],number[3]);
	user_input(number);



}


int user_input(int number[])
{
	char guess[5];
	printf("Enter your guess: ");
	fgets(guess, sizeof(guess), stdin);
	printf("Debug: guess is currently %s \n", guess);
	printf("Debug: guess is this long %zd \n", strlen(guess));
	if(strlen(guess) != 4){
		printf("\nEnter a four digit number \n");
		return 0;
	}
	else{
		guess[4] = '\0';
		printf("debug: this is guess %s \n", guess);
		//compare(number, guess);
	}
	
}


void compare(int number[], char guess[])
{
	int red = 0;
	int white = 0;
	for(int i = 0; i < 4; ++i){
		if(number[i] == guess[i]){
			++red;
		}
	}
	printf("%d red, ", red);
	printf("%d white\n", white);
	
}



