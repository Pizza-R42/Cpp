#include "Board.h"
#include <iostream>
#include <array>
using namespace std;

Board board(7, 6);

bool IsNumber(string str) {
	if (str.length() == 0) {
		return false;
	}
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}
int GetInput() {
	int slot;
	string slotStr;
	while (true) {
		cout << "\nEnter A Slot To Drop A Piece: ";
		getline(cin, slotStr);
		if (!IsNumber(slotStr)) {
			cout << "Enter Valid Input!";
			continue;
		}

		slot = stoi(slotStr);
		if (slot > 0 && slot <= 7) {
			return slot;
		}
		cout << "Enter Valid Input!";
	}
}


void TakeTurn(int side) {
	cout << "-----------------\n";
	cout << " PLAYER " << side << "'s TURN \n";
	cout << "-----------------\n\n";

	board.Print();
	
	if (!board.PlacePiece(GetInput() - 1, side)) {
		cout << "-THAT COLUM IS FULL!\n-Choose Another Colum\n";
		TakeTurn(side);
	}
	cout << endl;
	if (board.CheckWin()) {
		board.Print();
		cout << "\n--------------------\n";
		cout << "  Player " << side << " Wins!!!";
		cout << "\n--------------------\n";
		return;
	}
	if (board.CheckTie()) {
		board.Print();
		cout << "\n-----------------------\n";
		cout << "  Board Is Full (TIE)";
		cout << "\n-----------------------\n";
		return;
	}

	side == 1 ? TakeTurn(2) : TakeTurn(1);
	

}



int main()
{
	TakeTurn(1);
}




