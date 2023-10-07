#pragma once
#include <string> 
class Board {
private:
	// 0:empty
	// 1:side1
	// 2:side2
	int boardArr[7][6];
public:
	Board(int x, int y);
	bool PlacePiece(int x, int player);
	bool CheckWin();
	bool CheckTie();
	void Print();
};

