/* LIBRARY DECLARATION*/
#include <stdio.h>
#include <string.h>

/*DEFINE MACROS*/
#define ARRAYWIDTH 4
#define ARRAYHEIGHT 6
#define MAX_WORD_SIZE 70

/*HANGMAN ARRAY*/
char hangman[ARRAYHEIGHT][ARRAYWIDTH] = {
	{ '_' , '_' , '_' , '_'},
	{ '|' , '/' , '|' , ' '},
	{ '|' , ' ' , 'O' , ' '},
	{ '|' , ' ' , '+' , ' '},
	{ '|' , ' ' , '^' , ' '},
	{ '-' , '-' , '-' , '-'}
};
char currentHangman[ARRAYHEIGHT][ARRAYWIDTH] = {
	{ ' ' , ' ' , ' ' , ' '},
	{ ' ' , ' ' , ' ' , ' '},
	{ ' ' , ' ' , ' ' , ' '},
	{ ' ' , ' ' , ' ' , ' '},
	{ ' ' , ' ' , ' ' , ' '},
	{ ' ' , ' ' , ' ' , ' '}
};

int hangmanX[17] = { 3, 2, 1, 0, 0, 0, 0, 0, 0, 1, 2, 3, 1, 2, 2, 2, 2 };
int hangmanY[17] = { 5, 5, 5, 5, 4, 3, 2, 1, 0, 0, 0, 0, 1, 1, 2, 3, 4 };

/*VARIABLE DECLARATION*/
int i, j;
int completed = 0;
int wordSize = 5;
int correct = 0;
int cnt = 0;
int unsolved = 0;
char word[MAX_WORD_SIZE] = "elephant";
char input;
char guess;

/*FUNCTIONS*/
void loadWord()
{
	int num;
	FILE* fptr;
	fptr = fopen("test.txt", "r");
	fscanf(fptr, "%d", &num);
	printf("Value of n=%d", num);
	fclose(fptr);
}


void promptUser() {
	//Prompts user for letter guess
	printf("Enter character guess:");
	scanf("%s", &input);
	printf("Guess: %c\n\r", input);
}

int main(){
	wordSize = strlen(word);
	char currentWordGuess[wordSize];
	
	//Fill current word with under score _
	for (i = 0; i < wordSize; i++) {
		currentWordGuess[i] = '_';
	}

	while (completed == 0) {
		promptUser();
	
		//Checks if guess is valid
		for (i = 0; i < wordSize; i++) {
			if (input == word[i]) {
				currentWordGuess[i] = word[i];
				correct = 1;
			}
		}

		//Add to hangman
		if (correct == 0) {
			currentHangman[hangmanY[cnt]][hangmanX[cnt]] = hangman[hangmanY[cnt]][hangmanX[cnt]];
			if (cnt < 17) {
				cnt++;
			}
		}
		else {
			correct = 0;
		}

		//Prints current word
		printf("Word: ");
		for (i = 0; i < wordSize; i++) {
			printf("%c ", currentWordGuess[i]);
		}
		printf("\n\r");
		//Prints the hang man
		for (int i = 0; i < ARRAYHEIGHT; i++) {
			printf("\n\r");
			for (int j = 0; j < ARRAYWIDTH; j++) {
				printf("%c", currentHangman[i][j]);
			}
		}
		printf("\n\r");
		
		//Check if game is over
		for (i = 0; i < wordSize; i++) {
			if (currentWordGuess[i] == '_') {
				unsolved++;
			}
		}

		if (cnt >= 17) {
			printf("\n\r");
			printf("---------- GAME OVER! ----------");
			return 0;
		}
		else if (unsolved == 0) {
			printf("\n\r");
			printf("---------- YOU WIN! ----------");
			return 0;
		} 
		else {
			unsolved = 0;
		}
	}

	return 0;
}
