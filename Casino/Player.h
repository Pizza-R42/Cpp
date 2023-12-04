#pragma once
#include <vector>
#include <string>
#include "Cards.h"
#include "Game.h"
//using namespace std;
class Player {
private:
	string name;
	double cash;
	int chips;
	double bet;
	int rouletteBet; //-1 = Black, -2 = Red

	
public:
	vector<Card> hand;
	Player();
	Player(string name);
	void SetName(string name);
	string GetName();
	void AddCash(double amt);
	double ViewCash();
	bool RemoveCash(double amt);
	bool Bet(double bet);
	double GetBet();
	int GetChips();
	void AddChips(int amt);
	bool RemoveChips(int amt);
	void SetRouletteBet(int bet);
	int GetRouletteBet();


};