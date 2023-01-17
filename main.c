/*\
|*| Tic Tac Toe
|*| This is an interactive console game, implemented in C.
|*| Created by ICT Elective students at Chiang Rai International School (CRIS)
|*| Release to the Public Domain under CC0-v1.0.
\*/

#include <stdio.h>
#define BOARD_SIZE 9
#define EMPTY ' '
#define TIE 0
#define NOWINNER -1
/*
	TODO define symbolic constants for chars and use instead of literals throughout the program:

	PLAYER1
	PLAYER2
	EMPTY
*/

void print_board(char board[]);
void usage();
void update_board(char board[], char s, char player);
char get_move(char player, char board[]);
char win_check(char board[]);

int main(void) {
	
	char testboard[BOARD_SIZE] = {'X','O','X',' ',' ','O','X','O','O'};
	/* TODO use symbolic constants instead of literals
	char player1 = PLAYER1;
	...
	*/
	char player1 = 'X';
	char player2 = 'O';
	char demoboard[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};
	char board[BOARD_SIZE];
	for(int i = 0; i < BOARD_SIZE; ++i)
		board[i] = EMPTY;
	char currentplayer = player1;
	char s;

	print_board(board);
	usage();

	do {
		s = get_move(currentplayer, board);
		update_board(board, s, currentplayer);
		print_board(board);

		printf("%i", win_check(board));

		if (currentplayer == 'X')
			currentplayer = 'O';
		else
			currentplayer = 'X';
	}
	 while (1);

	return 0;
}

void print_board(char board[]){
	int i;

	printf("    +---+---+---+\n");
	for (i=8; i>=0; i-=3){
		printf("    | %c | %c | %c |\n    +---+---+---+\n", board[i-2], board[i-1], board[i]);
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
char get_move(char player, char board[]) {

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
				// TODO: Check slot occupancy
				if (board[c]!='X'||board[c]!='O')	
					return c; // Only valid input
				else {
					printf("Space occupied. Try again: ");
					break;
				}
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

/*
	Accept a board array and return a char representing the winner state:
		PLAYER1 : player 1 is the winner
		PLAYER2 : player 2 is the winenr
		 0 : players are tied
		-1 : no current winner
*/
/* TODO we can remove the second parameter `player` */
char win_check(char board[]) {
	// Horizontal wins
	if (board[0] != EMPTY && board[0] == board[1] ==board[2])
		return board[0];  /* TODO, don't do IO in a pure function - this is a side effect! */
	else if (board[3] != EMPTY && board[3] == board[4] == board[5])
		return board[3];
	else if (board[6] != EMPTY && board[6] == board[7] == board[8])
		return board[6];
	// Vertical wins
	else if (board[0] != EMPTY && board[0] == board[3] == board[6])
		return board[0];
	else if (board[1] !=EMPTY && board[1] == board[4] == board[8])
		return board[0];
	else if (board[2] != EMPTY && board[2] == board[4] == board[6])
		return board[2];
	// Tie
	else if (board[0]!=EMPTY&&board[1]!=EMPTY&&board[2]!=EMPTY&&board[3]!=EMPTY&&board[4]!=EMPTY&&board[5]!=EMPTY&&board[6]!=EMPTY&&board[7]!=EMPTY&&board[8]!=EMPTY)
		return TIE;
	// Game not over yet
	else
		return NOWINNER;
}
