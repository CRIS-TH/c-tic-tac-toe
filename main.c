/*\
|*| Tic Tac Toe
|*| This is an interactive console game, implemented in C.
|*| Created by ICT Elective students at Chiang Rai International School (CRIS)
|*| Release to the Public Domain under CC0-v1.0.
\*/

#include <stdio.h>
#define BOARD_SIZE 9

void print_board(char board[]);
void usage();
void update_board(char board[], char s, char player);
char get_move(char player);
char win_check(char board[]);

int main(void) {
	
	char testboard[BOARD_SIZE];
	char player1 = 'X';
	char player2 = 'O';
	char demoboard[BOARD_SIZE] = {'7','8','9','4','5','6','1','2','3'};
	char board[BOARD_SIZE];
	for(int i = 0; i < BOARD_SIZE; ++i)
		board[i], testboard[i] = 'X';
	char currentplayer = player1;
	char s;

	print_board(testboard);
	win_check(testboard);

	/*print_board(demoboard);
	usage();
	s = get_move(currentplayer);
	update_board(board, s, currentplayer);
	print_board(board);*/

	return 0;
}

void print_board(char board[]){
	int i;

	printf("    +---+---+---+\n");
	for (i=0; i<BOARD_SIZE; i+=3){
		printf("    | %c | %c | %c |\n    +---+---+---+\n", board[i], board[i+1], board[i+2]);
	}
}

void usage() {

	printf(
		"\nThe Number corresponds to your number pad on the keyboard.\n"
		"By inputing number, you will fill the corresponding cell with your symbol.\n"
		"You will win if you match 3 of your symbols horizontally, vertically, or diagonally.\n\n"
	);
}

// Get valid char input from current player and return the int value
char get_move(char player) {

	if (player == 'X') {
		printf("Player 1's turn. Input move: ");
	} else {
		printf("Player 2's turn. Input move: ");
	}
	https://github.com/CRIS-TH/c-tic-tac-toe.git

	do {
		char c = getchar();

		switch (c) {
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				return c; // Only valid input
			case '\n':
			case ' ':
			case '\t':
				continue;
			default:
				printf("Invalid input `%c', try again.\n", c);
				break;
		}
	} while (1);
}

void update_board(char board[], char s, char player){
	int i;
	i = s;
	i -= 49;
	board[i] = player;
}

// Check if the game is over
char win_check(char board[]) {
	int amount = 0;
	for(int i = 0; i < BOARD_SIZE; ++i) {
		if(board[i] != ' '){
			++amount;
		}
	}
	
	printf("%i", amount);

	if (amount == 9) {
		//TODO: Display tie message through the function
		printf("\nTie\n");
	} else if (board[0]!=' ' && board[1]!=' ' && board[2]!=' ')
		printf("%c Win", board[0]);
}
