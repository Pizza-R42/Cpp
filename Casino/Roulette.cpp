#include "Game.h"
#include "Player.h"
#include "Input.h"
#include "Casino.h"
#include <iostream>

using namespace std;

RouletteSlot::RouletteSlot(){
	num = 0;
	color = BLACK;
}
RouletteSlot::RouletteSlot(int num, Color color) {
	this->num = num;
	this->color = color;
	
}
int RouletteSlot::GetNum() {
	return num;
}
Color RouletteSlot::GetColor() {
	return color;
}

Roulette::Roulette(vector<Player*> players) {
	this->players = players;
	board = new RouletteSlot[37];
	int red[]{
		1,3,5,7,9,11,14,16,18,19,21,23,25,27,30,32,34,36
	};

	for (int i = 1; i <= 36; i++) {
		for (int j = 0; j < 18; j++) {
			if (i == red[j]) {
				board[i] =  RouletteSlot(i, RED);
				break;
			}
			else if (j==17){
				board[i] = RouletteSlot(i, BLACK);
				break;
			}
		}
	}
}
void Roulette::PlayRound() {
	PlaceBets();
	Spin();
	CalculateBets();
}
void Roulette::BetColor(Player* p) {
	string output = "What Color Would You Like To Bet On?\n1: Red\n2: Black\nEnter Your Choice: ";
	int choice = Input::GetInput(output, 2);
	if (choice == 1) {
		p->SetRouletteBet(-2);
	}
	if (choice == 2) {
		p->SetRouletteBet(-1);
	}
}
void Roulette::BetNumber(Player* p) {
	while (true) {
		int inp;
		cout << "Enter Your Number To Bet On (1-36): ";
		cin >> inp;
		if (inp < 1 || inp > 36) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nINVALID INPUT!\n";
			continue;
		}
		p->SetRouletteBet(inp);
		break;
	}
}
void Roulette::PlaceBets() {
	for (Player* p : players) {
		cout << "...................................\n";
		cout << p->GetName() << "'s Turn\n";
		string output = "What Would You Like To Place Your Bets On\n1: Number\n2: Color\nEnter Your Choice: ";
		switch (Input::GetInput(output, 2)){
		case 1:
			BetNumber(p);
			break;
		case 2:
			BetColor(p);
			break;
		default:
			break;
		}

		
		while (true) {
			cout << "You Have " << p->GetChips() << " chips, How Much Do You Want To Bet: ";
			int inp;
			cin >> inp;
			if (inp > p->GetChips() || inp <= 0) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "\nINVALID INPUT!\n";
				continue;
			}
			p->Bet(inp);
			break;
		}
	}
}
void Roulette::CalculateBets() {
	for (Player* p : players) {
		int rBet = p->GetRouletteBet();
		if (rBet < 0) {
			if (rBet == -1 && winningSlot.GetColor() == BLACK) {
				//win
				int win = p->GetBet() * 2;
				cout << p->GetName() << " WON " << win << endl;
				p->AddChips(win);
			}
			if (rBet == -2 && winningSlot.GetColor() == RED) {
				//win
				int win = p->GetBet() * 2;
				cout << p->GetName() << " WON " << win << endl;
				p->AddChips(win);
			}
		}else if (rBet == winningSlot.GetNum()) {
			//win
			int win = p->GetBet() * 35;
			cout << p->GetName() << " WON " << win << endl;
			p->AddChips(win);
		}
	}
	cin.ignore();
	string output = "Do You Want To Continue [y/n] ";
	if (Input::YN(output)) {
		PlayRound();
	}
	else {
		ExitGame();
	}
	
	
}
void Roulette::Spin() {
	srand(static_cast<unsigned int>(time(nullptr)));
	winningSlot = board[(std::rand() % 35)];
	cout << ".........................................\n";
	string color;
	switch (winningSlot.GetColor()){
	case 0:
		color = "Red";
		break;
	case 1:
		color = "Black";
		break;
	default:
		break;
	}
	cout << "The ball landed on " << color << " " << winningSlot.GetNum() << "\n";
}

void Roulette::PlayGame() {
	Game::PlayGame();
	BuyIn(100);
	PlayRound();
}

void Roulette::ExitGame() {
	delete[] board;
	Game::ExitGame();
	Casino::Home();
	
}