#include "Input.h"
#include "Game.h"
#include "Casino.h"
#include "Bank.h"
#include "User.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
vector<Player*> Casino::people;
Player* Casino::currentPlayer;

void PlayBJ() {
	BlackJack game = BlackJack(Casino::people);
	game.PlayGame();
	game.PlayHand();
	
}

void PlayRoulette() {
	Roulette game = Roulette(Casino::people);
	game.PlayGame();
}

void Casino::PlaySlots() {
	string output;
	if (people.size() == 1) {
		if (people.at(0)->ViewCash() <= 0) {
			cout << "\nYOU HAVE NO CASH!\n\n";
			Casino::Home();
			return;
		}
		Slots game = Slots(people.at(0));
		game.PlayGame();
		return;
	}
	output = "Only 1 Person Can Play Slots\nWho Would Like To Play?\n";
	for (int i = 0; i < people.size(); i++) {
		output += to_string(i + 1) + ": " + people.at(i)->GetName() + "\n";
	}
	output += "Enter Player Num: ";
	int chosen = Input::GetInput(output, people.size()) - 1;
	if (people.at(chosen)->ViewCash() <= 0) {
		cout << "\nYOU HAVE NO CASH!\n\n";
		Casino::Home();
		return;
	}
	Slots game = Slots(people.at(chosen));
	game.PlayGame();
}

void GetUsers() {
	string output = "How many people are there including you? (MAX 5): ";
	int playerCount = Input::GetInput(output, 5);
	Casino::people.clear();
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < playerCount; i++) {
		cout << "User " << i + 1 << ": Enter Your Name : ";
		string name;
		getline(cin, name);
		Casino::AddUser(name);
	}
	Casino::Home();
}

void Casino::AddUser(string name) {
	Player* p = new Player(name);
	people.push_back(p);
}

void Casino::Games() {
	string games = "1: Blackjack\n2: Roulette\n3: Slots\nEnter Your Choice: ";
	switch (Input::GetInput(games, 3)) {
	case 1:
		PlayBJ();
		break;
	case 2:
		PlayRoulette();
		break;
	case 3:
		Casino::PlaySlots();
		break;
	default:
		break;
	}
}

void Casino::ATM() {
	string output = "Which User Are You?\n";
	for (int i = 0; i < Casino::people.size(); i++) {
		output += to_string(i+1) + ": " + Casino::people.at(i)->GetName() + "\n";
	}
	output += "Enter Your Choice: ";
	int usr = Input::GetInput(output, Casino::people.size());
	usr--;
	currentPlayer = Casino::people.at(usr);

	while (!Bank::HomeOptions()) {
		cout << "Invalid Option!\n\n";
	}
}

void Casino::Home() {
	
	cout << "Welcome To The Casino\n..............................\n\n";
	string output = "What Would You Like To Do?\n1: Withdraw Money\n2: Play a Game\n3: Leave\nEnter Your Choice: ";
	switch (Input::GetInput(output, 3)){
	case 1:
		//GetMoney
		ATM();
		Casino::Home();
		break;
	case 2:
		Games();
		break;
	case 3:
		break;
	default:
		break;
	}
}

int main() {
	Bank::InitBank();
	GetUsers();

	for (Player* p : Casino::people) {
		delete p;
	}
	Bank::EndBank();
	
}