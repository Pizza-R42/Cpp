#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string path = "scores.csv";
ofstream outf;
ifstream inf;

int GetInput() {
	int inp = 0;
	cout << "1. Enter their high score\n2. View existing high scores\n";
	cout << "Enter your choice: ";
	cin >> inp;
	return inp;
}

void SetHigh() {
	outf.open(path, ios::app);
	if (!outf.is_open()) {
		cout << path << " Not Opened!";
		return;
	}
	string name;
	int score;
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter Score: ";
	cin >> score;

	outf << name + "," << score << "\n";
	outf.close();
}

void ViewHigh() {
	inf.open(path);
	if (!inf.is_open()) {
		cout << "No high scores found!";
		return;
	}
	string line;
	
	while (getline(inf, line)) {

		int size = line.find(',');
		string name = line.substr(0, size);
		string score = line.substr(size+1);

		cout << score << " by " << name << endl;
	}
	inf.close();
}

int main()
{
	int choice = GetInput();
	switch (choice){
	case 1:
		SetHigh();
		break;
	case 2:
		ViewHigh();
		break;
	default:
		return 0;
		break;
	}
}


