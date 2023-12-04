#pragma once
#include <vector>
#include "Player.h"
#include "Cards.h"
using namespace std;
class Player;

class Game {
protected:
	vector<Player*> players;
public:
	virtual void PlayGame();
	virtual void ExitGame();
	void BuyIn(int min);
};

class CardGame : public Game {
protected:
	Deck deck;
};

class BlackJack : public CardGame {
private:
	int dealerStand;
	double potMoney;
public:

	BlackJack();
	BlackJack(vector<Player*> players);
	int GetHandValue(vector<Card> hand);
	void GetBets();
	void PlayHand();
	void PlayGame() override;
	void EndHand(Player* winner, double money);
	void ExitGame() override;
};

enum Symbol {
	CHERRY,
	LEMON,
	ORANGE,
	PLUM,
	BELL,
	BAR,
	SEVENS,
	MAX_SYMBOLS
};

class Slots : public Game {
private:
	Player* player;
	vector<Symbol> reels[3]; 
	Symbol landedReels[3];
	int credits;
public:
	Slots(Player* player);
	void InitializeReels();
	void Spin();
	int CheckWin(int spinAmt);
	string GetSymbolName(Symbol symbol);
	void PlayRound(int spinCost);
	void PlayGame() override;
	bool EnterMoney();
	void ExitGame() override;
};






enum Color {
	RED, BLACK
};



class RouletteSlot {
private:
	int num;
	Color color;
public:
	RouletteSlot();
	RouletteSlot(int num, Color color);
	int GetNum();
	Color GetColor();
};


class Roulette : public Game {
private:
	RouletteSlot* board;
	RouletteSlot winningSlot;
public:
	Roulette(vector<Player*> players);
	void PlayGame() override;
	void ExitGame() override;
	void PlaceBets();
	void BetColor(Player* p);
	void BetNumber(Player* p);
	void Spin();
	void CalculateBets();
	void PlayRound();
};




