#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void compare(int number[], char guess[]);
void user_input(int number[]);

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


void user_input(int number[])
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
	compare(number, guess);

}


void compare(int number[], char guess[])
{
	int red = 0;
	int white = 0;
	int mask[] = {0,0,0,0};
	for(int i = 0; i < 4; ++i){
		if(number[i] == guess[i]){
			++red;
			mask[i] = 1;
		}
	}
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if((number[j] == guess[i]) && (mask[i] == 0)){
				++white;
			}
		}
	}
	printf("%d red, ", red);
	printf("%d white\n", white);
	
}



