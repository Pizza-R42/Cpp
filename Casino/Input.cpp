#include "Input.h"
#include <iostream>
using namespace std;
Input::Input(){}
int Input::GetInput(string output, int choices) {
	int choice = 0;

	while (true) {
		cout << output;
		cin >> choice;
		if (choice <= 0 || choice > choices) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nINVALID INPUT\n";
			continue;
		}
		break;

	}
	return choice;
}

bool Input::YN(string output) {
	
	while (true) {

		cout << output;
		string inp;
		getline(cin, inp);
		if (inp == "" || inp == "y" || inp == "Y") {
			//PlayHand();
			return true;
			break;
		}
		if (inp == "n" || inp == "N") {
			//ExitGame();
			return false;
			break;
		}
		cout << "\nINVALID INPUT!\n";
	}
}