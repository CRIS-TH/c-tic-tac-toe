/*\
|*| Tic Tac Toe
|*| This is an interactive console game, implemented in C.
|*| Created by ICT Elective students at Chiang Rai International School (CRIS)
|*| Release to the Public Domain under CC0-v1.0.
\*/

#include <stdio.h>
#define BOARD_SIZE 9
#define PLAYER1 'X'
#define PLAYER2 'O'
#define EMPTY ' '

void print_board(char board[]);
void usage();
void update_board(char board[], char s, char player);
char get_move(char player, char board[]);
char win_check(char board[], char currentplayer);

int main(void) {

//Functions
	char demoboard[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};
	char board[BOARD_SIZE];
	for(int i = 0; i < BOARD_SIZE; ++i)
		board[i] = EMPTY;
	char currentplayer = PLAYER1;
	char s;

//Show how to play
	print_board(board);
	usage();

	do {
		s = get_move(currentplayer, board);
		update_board(board, s, currentplayer);
		print_board(board);

		/* TODO
		if win_check is >= 0
			print_winner(char returned by win_check)
		else
			keep playing
		*/
		if (win_check(board, currentplayer) != 0)
			break;

		if (currentplayer == PLAYER1)
			currentplayer = PLAYER2;
		else
			currentplayer = PLAYER1;
	}
	 while (1);

	return 0;
}

// Input the array board then it going to print the board
void print_board(char board[]){
	int i;

	printf("    +---+---+---+\n");
	for (i=8; i>=0; i-=3){
		printf("    | %c | %c | %c |\n    +---+---+---+\n", board[i-2], board[i-1], board[i]);
	}
}

// Print how to use for the user
void usage() {

	printf(
		"\nThe Number corresponds to your number pad on the keyboard.\n"
		"By inputing number, you will fill the corresponding cell with your symbol.\n"
		"You will win if you match 3 of your symbols horizontally, vertically, or diagonally.\n\n"
	);
}

// Get valid char input from current player and return the int value
char get_move(char player, char board[]) {

	if (player == PLAYER1) {
		printf("Player 1's turn. Input move: ");
	} else {
		printf("Player 2's turn. Input move: ");
	}

	do {
		char c = getchar();
		int i;
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
				// -49 convert the '1' char to a 0 int for the array
				i = c;
				if (board[i-49] != PLAYER1 && board[i-49] != PLAYER2)	
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

//Storge the input data in the board array
void update_board(char board[], char s, char player){
	int i;
	i = s;
	// -49 convert the char into int for the array selecter
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
char win_check(char board[], char player) {
	/*
	TODO - the winning player can be determined from existing values

	if (board[0] != EMPTY && board[0] == board[1] == board[2])
		return board[0];
	*/

	// Horizontal wins
	if (board[0]==player && board[1]==player && board[2]==player)
		//TODO: Call the game over function if the game is over
		printf("%c Win\n", player);  /* TODO, don't do IO in a pure function - this is a side effect! */
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
