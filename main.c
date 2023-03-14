/*\
|*| Tic Tac Toe
|*| This is an interactive console game, implemented in C.
|*| Created by ICT Elective students at Chiang Rai International School (CRIS)
|*| Release to the Public Domain under CC0-v1.0.
\*/

#include <stdlib.h> // malloc(), free()
#include <stdio.h>
#define BOARD_SIZE 9
#define PLAYER1 'X'
#define PLAYER2 'O'
#define EMPTY ' '
#define TIE 0
#define NOWINNER -1

/* TODO
where function take a single char data array, modify to take a struct

allocate a struct game and return a pointer
struct game* init_game();

...after play 
free game;
*/

//Functions
void print_board(char data[]);
void usage();
void update_board(struct game*);
char get_move(struct game*);
char win_check(char data[]);
void displayer(int winner);
int play_again(void);

// Struct containing game variables
struct game {
	char board[BOARD_SIZE];
	char current_player;
	char move;
	char winner;
};


// Create a new game struct and set initial values and return pointer
struct game *new_game() {
	struct game *pt = malloc(sizeof(struct game));
	for(int i = 0; i < BOARD_SIZE; ++i)
		pt->board[i] = EMPTY;
	pt->current_player = PLAYER1;
	return pt;
};

int main(void) {
//Boards and Player setup
	char board[BOARD_SIZE];
	char demoboard[BOARD_SIZE];
	int do_play = 1;
	struct game *current_game;

	while (do_play) {
		current_game = new_game();

	//Show how to play
		print_board(demoboard);
		usage();

		do {
			current_game->move = get_move(current_game);
			update_board(current_game);
			print_board(board);
			int winner = win_check(board);
		
			if (currentplayer == PLAYER1)
				currentplayer = PLAYER2;
			else
				currentplayer = PLAYER1;
			
			if (winner != -1){
				
				displayer(winner);
				do_play = play_again();
				break;
				//Break inner loop
			}
					
		}
		while (1);
	}

	return 0;
}

// Input the array board then it going to print the board
void print_board(char data[]){
	int i;

	printf("    +---+---+---+\n");
	for (i=8; i>=0; i-=3){
		printf("    | %c | %c | %c |\n    +---+---+---+\n", data[i-2], data[i-1], data[i]);
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
char get_move(struct game* current_game) {
	if (current_game->current_player == PLAYER1)
		printf("Player 1's turn. Input move: ");
	else
		printf("Player 2's turn. Input move: ");

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
				if (current_game->board[i-49] == ' ')	
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

//Store the input data in the board array
void update_board(struct game *current_game){
	int i;
	i = s;
	// -49 convert the char into int for the array selecter
	i -= 49;
	data[i] = player;
}

char win_check(char data[]) {
	// Horizontal wins
	if (data[0] != EMPTY && data[0] == data[1] && data[1] == data[2])
		return data[0];

	if (data[3] != EMPTY && data[3] == data[4] && data[4] == data[5])
		return data[3];

	if (data[6] != EMPTY && data[6] == data[7] && data[7]== data[8])
		return data[6];

	// Vertical wins
	if (data[0] != EMPTY && data[0] == data[3] && data[3] == data[6])
		return data[0];

	if (data[1] !=EMPTY && data[1] == data[4] && data[4] == data[7])
		return data[0];

	if (data[2] != EMPTY && data[2] == data[5] && data[5] == data[8])
		return data[2];

	// Crossed wins
	if (data[0] != EMPTY && data[0] == data[4] && data[4] == data[8])
		return data[0];
	
	if (data[2] != EMPTY && data[2] == data[4] && data[4] == data[6])
		return data[2];

	// Tie
	if (data[0]!=EMPTY&&data[1]!=EMPTY&&data[2]!=EMPTY&&data[3]!=EMPTY&&data[4]!=EMPTY&&data[5]!=EMPTY&&data[6]!=EMPTY&&data[7]!=EMPTY&&data[8]!=EMPTY)
		return TIE;

	// Game not over yet
	return NOWINNER;

}

void displayer(int winner){
	if (winner == 0)
		printf("It's a tie\n");
	else
		printf("Winner is %c\n", winner);
}

int play_again(void){
	
	char c;
	printf("DO YOU WANT TO PLAY AGAIN?\n Y / N\n");
	
	do {
		c = getchar();
		if (c == 'N' || c == 'n')
			return 0;
		
		if (c == 'Y' || c == 'y')
			return 1;
		
		if (c == ' ' || c == '\n' || c == '\t')
			continue;
		else
			printf("PLEASE TRY AGAIN\n");
		
		
	} while(1);

}
