/**
*FNU Saqiurila
*14227763
*qsq35
*Oct 8
*/
#ifndef FUNCTION_H_
#define FUNCTION_H_

typedef enum{
	covered,
	uncovered,
	coveredBomb,
	uncoveredBomb
}PositionType;

#define BoardSize 10

void setBoard(PositionType board[BoardSize][BoardSize],int numMines);
void displayBoard(PositionType board[BoardSize][BoardSize]);
int processGuess(PositionType board[BoardSize][BoardSize],int row,int col);
int adjacentBomb(PositionType board[BoardSize][BoardSize],int row,int col);

#endif
