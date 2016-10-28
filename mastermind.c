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
	printf("The number is %d%d%d%d \n", number[0],number[1],number[2],number[3]);
	user_input(number);



}


int user_input(int number[])
{
	char guess[8];
	printf("Enter your guess: ");
	while(1){
		fgets(guess, sizeof(guess), stdin);
		if(strlen(guess) == 5){
			break;
		}
		else{
			printf("Please enter a four digit number: ");
		}

	}
		//Turns the unicode character to it's appropiate number
	guess[4] = '\0';
	for(int i = 0; i < 4; ++i){
		guess[i] -= '0';
	}
	printf("Debug guess[0]:%d\n", guess[0]);
	printf("Debug guess[1]:%d\n", guess[1]);
	printf("Debug guess[2]:%d\n", guess[2]);
	printf("Debug guess[3]:%d\n", guess[3]);
	compare(number, guess);

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



