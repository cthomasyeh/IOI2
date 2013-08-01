#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

//char board[8][8];

bool replace(char** board, char piece, int row, int column, int rowIncrease, int columnIncrease)
{
	if(rowIncrease == 0 && columnIncrease == 0) return false;
	int newRow = row + rowIncrease;
	int newCol = column + columnIncrease;
	if(newRow < 0 || newRow > 7) return false;
	if(newCol < 0 || newCol > 7) return false;
	if(board[newRow][newCol] == '.') return false;
	if(board[newRow][newCol] == piece) return true;
	if(replace(board, piece, newRow, newCol, rowIncrease, columnIncrease))
	{
		board[newRow][newCol] = piece;
		return true;
	}
	return false;
}

int main ()
{
 	char ** board;	
 	board = new char*[8];
	for (int i=0; i<8; i++) {
		board[i] = new char [8];
	}		
	//char board[8][8];
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			board[i][j] = '.';
	board[3][3] = 'W';
	board[3][4] = 'B';
	board[4][3] = 'B';
	board[4][4] = 'W';
	char piece = 'W';
	string square;
	cin >> square;
	while(square != "END")
	{
		int column = square[0] - 97;
		int row = atoi(&square[1]) - 1;
		board[row][column] = piece;
		for(int i = -1; i <= 1; i++)
			for(int j = -1; j <= 0; j++)
				replace( board, piece, row, column, i, j);
		if(piece == 'W') piece = 'B';
		else piece = 'W';
		cin >> square;
	}
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
			cout << board[i][j];
		cout << endl;
	}
	return 0;
}
