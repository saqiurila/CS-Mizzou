/**
*FNU Saqiurila
*14227763
*qsq35
*Oct 8
*/
#include <stdio.h>
#include<time.h>
#include "minesweeper.h"

void setBoard(PositionType board[BoardSize][BoardSize],int numMines){
	int i,j;
	srand((unsigned)time(NULL));
	for(i=0;i<numMines;i++){
		int bombRow=rand()%(BoardSize-1);
		int bombCol=rand()%(BoardSize-1);
		if(board[bombRow][bombCol]!=coveredBomb){
			board[bombRow][bombCol]=coveredBomb;
		}
		else{
			i--;
		}
	}
	for(i=0;i<BoardSize;i++){
		for(j=0;j<BoardSize;j++){
			if(board[i][j]!=coveredBomb){
				board[i][j]=covered;
			}
		}
	}
}
void displayBoard(PositionType board[BoardSize][BoardSize]){
	int i,j;
	printf(" ");
	for(i=0;i<BoardSize;i++){
		printf("%5d",i+1);
	}
	printf("\n");
	for(i=0;i<BoardSize;i++){
		printf("%4d",i+1);
		for(j=0;j<BoardSize;j++){
			
			if(board[i][j]==covered||board[i][j]==coveredBomb){
				printf(" #   ");
			}
			else if(board[i][j]==uncovered){
				printf(" %d   ",adjacentBomb(board,i,j));
			}
			else if(board[i][j]==uncoveredBomb){
				printf(" @   ");
			}
		}
		printf("\n");
	}
}
int processGuess(PositionType board[BoardSize][BoardSize],int row,int col){
	if(row>BoardSize||row<0||col>BoardSize||col<0){
		return -1;
	}
	else if(board[row][col]==uncovered){
		return 0;
	}
	else if(board[row][col]==covered){
		return 1;
	}
	else if(board[row][col]==coveredBomb){
		return 2;
	}
}
int adjacentBomb(PositionType board[BoardSize][BoardSize],int row,int col){
	int number=0;
	if(row-1>=0){ 
		if(board[row-1][col]==coveredBomb){//above
			number++;
		}
		if(col-1>=0){
			if(board[row-1][col-1]==coveredBomb){//left above
				number++;
			}
			if(board[row][col-1]==coveredBomb){//left
				number++;
			}
		}
		if(col+1<BoardSize){
			if(board[row-1][col+1]==coveredBomb){//right above
				number++;
			}
			if(board[row][col+1]==coveredBomb){//right
				number++;
			}
		}
	}
	if(row+1<BoardSize-1){
		if(board[row+1][col]==coveredBomb){//below
			number++;
		}
		if(col-1>=0){
			if(board[row+1][col-1]==coveredBomb){//left below
				number++;
			}
		}
		if(col+1<BoardSize){
			if(board[row+1][col+1]==coveredBomb){//right below
				number++;
			}
		}
	}
	return number;
}
