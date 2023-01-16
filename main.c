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
char get_move(char player, char board[]);
char win_check(char board[], char currentplayer);

int main(void) {
	
	char testboard[BOARD_SIZE] = {'X','O','X',' ',' ','O','X','O','O'};
	char player1 = 'X';
	char player2 = 'O';
	char demoboard[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};
	char board[BOARD_SIZE];
	for(int i = 0; i < BOARD_SIZE; ++i)
		board[i] = ' ';
	char currentplayer = player1;
	char s;

	print_board(board);
	usage();

	do {
		s = get_move(currentplayer, board);
		update_board(board, s, currentplayer);
		print_board(board);

		if (win_check(board, currentplayer) != 0)
			break;

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

// Check if the game is over
char win_check(char board[], char player) {
	// Horizontal wins
	if (board[0]==player && board[1]==player && board[2]==player)
		//TODO: Call the game over function if the game is over
		printf("%c Win\n", player);
	else if (board[3]==player && board[4]==player && board[5]==player)
		printf("%c Win\n", player);
	else if (board[6]==player && board[7]==player && board[8]==player)
		printf("%c Win", player);
	// Vertical wins
	else if (board[0]==player && board[3]==player && board[6]==player)
		printf("%c Win\n", player);
	else if (board[1]==player && board[4]==player && board[7]==player)
		printf("%c Win\n", player);
	else if (board[2]==player && board[5]==player && board[8]==player)
		printf("%c Win\n", player);
	// Crossed wins
	else if (board[0]==player && board[4]==player && board[8]==player)
		printf("%c Win\n", player);
	else if (board[2]==player && board[4]==player && board[6]==player)
		printf("%c Win\n", player);
	// Tie
	else if (board[0]!=' '&&board[1]!=' '&&board[2]!=' '&&board[3]!=' '&&board[4]!=' '&&board[5]!=' '&&board[6]!=' '&&board[7]!=' '&&board[8]!=' ')
		printf("Tie\n");
	// Game not over yet
	else
		return 0;
}
