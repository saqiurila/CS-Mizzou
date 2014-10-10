/**
*FNU Saqiurila
*14227763
*qsq35
*Oct 8
*/
#include <stdio.h>
#include <stdlib.h>
#include "minesweeper.h"

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Usage: ./minesweeper <number of bombs>\n");
		return 0;
	}
	PositionType board[BoardSize][BoardSize];
	int number=atoi(argv[1]);
	setBoard(board,number);
	
	while(1){
		int row,col;
		printf("Enter a row and col: ");
		scanf("%d%d",&row,&col);
		int result=processGuess(board,row-1,col-1);
		if(result==-1){
			printf("Invalid position\n");
		}
		else if(result==0){
			printf("The guess was already uncovered\n");
		}
		else if(result==1){
			board[row-1][col-1]=uncovered;
		}
		else{
			board[row-1][col-1]=uncoveredBomb;
			displayBoard(board);
			printf("Game over, you lose\n");
			return 0;
		}
		displayBoard(board);
	}
}