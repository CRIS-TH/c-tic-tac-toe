/*\
|*| Tic Tac Toe
|*| This is an interactive console game, implemented in C.
|*| Created by ICT Elective students at Chiang Rai International School (CRIS)
|*| Release to the Public Domain under CC0-v1.0.
\*/

#include <stdio.h>
#define BOARD_SIZE 9

void print_board(char board[]);

int main(void) {
	
	char board[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};

	print_board(board);

	return 0;
}

void print_board(char board[]){
	int i;

	for (i=0; i<BOARD_SIZE; i++)
		printf("%c\n", board[i]);
		

}
