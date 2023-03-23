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

// Struct containing game variables
struct game {
	char board[BOARD_SIZE];
	char current_player;
	char move;
	char winner;
};

//Functions
void print_board(char data[]);
void usage();
void update_board(struct game*);
char get_move(struct game*);
char win_check(struct game*);
void displayer(struct game*);
int play_again(void);


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
	char demoboard[BOARD_SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int do_play = 1;
	struct game *current_game = NULL;


//Show how to play
	print_board(demoboard);
	usage();

	do {
		if (!current_game)
			current_game = new_game();
			
		current_game->move = get_move(current_game);
		update_board(current_game);
		print_board(current_game->board);
		current_game->winner = win_check(current_game);
	
		if (current_game->current_player == PLAYER1)
			current_game->current_player = PLAYER2;
		else
			current_game->current_player = PLAYER1;
		
		if (current_game->winner != -1){
			displayer(current_game);
			do_play = play_again();
			free(current_game);
			current_game = NULL;
		}
				
	}
	while (do_play);

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
char get_move(struct game *current_game) {
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
	int i = current_game->move;
	// -49 convert the char into int for the array selecter
	i -= 49;
	current_game->board[i] = current_game->current_player;
}

char win_check(struct game *current_game) {
	char *data = current_game->board;

	// Horizontal wins
	for (int i = 0; i < BOARD_SIZE; i+=3){
		if (data[i] != EMPTY && data[i] == data[1+i] && data[1+i] == data[2+i])
			current_game->winner = data[i];
	}

	// Vertical wins	
	for (int i = 0; i <= 3; ++i){
		if (data[i] != EMPTY && data[i] == data[3+i] && data[3+i] == data[6+i])
			current_game->winner = data[i];
	}

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

void displayer(struct game *current_game){
	if (!current_game->winner)
		printf("It's a tie\n");
	else
		printf("Winner is %c\n", current_game->winner);
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
