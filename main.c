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

int main(void) {
	
	char player1 = 'X';
	char player2 = 'O';
	char board[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};

	print_board(board);

	return 0;
}

void print_board(char board[]){
	int i;

	printf("    +---+---+---+\n");
	for (i=0; i<BOARD_SIZE; i+=3){
		printf("    | %c | %c | %c |\n    +---+---+---+\n", board[i], board[i+1], board[i+2]);
	}
	usage();
}

void usage() {
	
	char board[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};
	
	// TODO: Call print board function for demo array
	// print_board(board)

	printf(
		"\nThe Number corresponds to your number pad on the keyboard.\n"
		"By inputing number, you will fill the corresponding cell with your symbol.\n"
		"You will win if you match 3 of your symbols horizontally, vertically, or diagonally.\n"
	);
}
