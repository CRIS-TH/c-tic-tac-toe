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
char get_move(char player);

int main(void) {

	char player1 = 'X';
	char player2 = 'O';
	char demoboard[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};
	char board[BOARD_SIZE];
	char currentplayer = player1;
	char storge;

	for (int i=1; i >= BOARD_SIZE; ++i)
		board[i] = ' ';
	
	print_board(demoboard);
	usage();
	storge = get_move(currentplayer);
	board[storge] = currentplayer;
	print_board(board);

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

	char board[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};

	printf(
		"\nThe Number corresponds to your number pad on the keyboard.\n"
		"By inputing number, you will fill the corresponding cell with your symbol.\n"
		"You will win if you match 3 of your symbols horizontally, vertically, or diagonally.\n\n"
	);
}

// Get valid input from current player and return it
char get_move(char player) {

	if (player == 'X') {
		printf("Player 1's turn. Input move: ");
	} else {
		printf("Player 2's turn. Input move: ");
	}
	

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
