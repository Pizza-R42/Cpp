#include "Board.h"
#include <iostream>
//#include <iterator>
using namespace std;

Board::Board(int xSize, int ySize) {
	for (int y = 0; y < size(boardArr[0]); y++) {
		for (int x = 0; x < size(boardArr); x++) {
			boardArr[x][y] = 0;
		}
	}
}

bool Board::PlacePiece(int x, int player) {
	for (int y = 0; y < size(boardArr[0]); y++) {
		if (boardArr[x][y] == 0) {
			boardArr[x][y] = player;
			return true;
		}
	}
	return false;
}


void Board::Print() {
	for (int y = size(boardArr[0])-1; y >= 0; y--) {
		for (int x = 0; x < size(boardArr); x++) {
			if (boardArr[x][y] > 0) {
				cout << "[" << boardArr[x][y] << "]";
			}
			else {
				cout << "[ ]";
			}
			
		}
		cout << endl;
	}
	cout << "\n(1)(2)(3)(4)(5)(6)(7)\n\n";
}

bool Board::CheckWin() {
	//Horizontal
	for (int y = 0; y < size(boardArr[0]); y++) {
		for (int x = 0; x < size(boardArr)-3; x++) {
			if (boardArr[x][y] != 0) {
				if (boardArr[x][y] == boardArr[x+1][y] &&
					boardArr[x][y] == boardArr[x+2][y] &&
					boardArr[x][y] == boardArr[x+3][y]) {
					return true;
				}
			}
		}
	}

	//Vertical
	for (int y = 0; y < size(boardArr[0])-3; y++) {
		for (int x = 0; x < size(boardArr); x++) {
			if (boardArr[x][y] != 0) {
				if (boardArr[x][y] == boardArr[x][y+1] &&
					boardArr[x][y] == boardArr[x][y+2] &&
					boardArr[x][y] == boardArr[x][y+3]) {
					return true;
				}
			}
		}
	}

	//Diag Up
	for (int y = 0; y < size(boardArr[0]) - 3; y++) {
		for (int x = 0; x < size(boardArr) - 3; x++) {
			if (boardArr[x][y] != 0) {
				if (boardArr[x][y] == boardArr[x+1][y+1] &&
					boardArr[x][y] == boardArr[x+2][y+2] &&
					boardArr[x][y] == boardArr[x+3][y+3]) {
					return true;
				}
			}
		}
	}
	//Diag Down
	for (int y = size(boardArr[0]) -1; y >= 0; y--) {
		for (int x = 0; x < size(boardArr) - 3; x++) {
			if (boardArr[x][y] != 0) {
				if (boardArr[x][y] == boardArr[x + 1][y - 1] &&
					boardArr[x][y] == boardArr[x + 2][y - 2] &&
					boardArr[x][y] == boardArr[x + 3][y - 3]) {
					return true;
				}
			}
		}
	}

	return false;
}

bool Board::CheckTie() {
	for (int y = 0; y < size(boardArr[0]); y++) {
		for (int x = 0; x < size(boardArr); x++) {
			if (boardArr[x][y] == 0) {
				return false;
			}
		}
	}
	return true;
}
