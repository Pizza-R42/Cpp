#include "Player.h"

Player::Player() {
	cash = 0;
	bet = 0;
	name = "NULL";
	rouletteBet = 0;
	chips = 0;
}
bool Player::RemoveChips(int amt) {
	if (chips - amt < 0) {
		return false;
	}
	chips -= amt;
	return true;
}
Player::Player(string name) {
	this->name = name;
}
double Player::ViewCash() {
	return cash;
}
void Player::SetName(string name) {
	this->name = name;
}
string Player::GetName() {
	return name;
}
void Player::AddCash(double amt) {
	cash += amt;
}
bool Player::RemoveCash(double amt) {
	if (cash - amt < 0) {
		return false;
	}
	cash -= amt;
	return true;
}
bool Player::Bet(double bet) {
	this->bet = 0;
	if (!Player::RemoveChips(bet)) {
		return false;
	}
	this->bet = bet;
	return true;
}

double Player::GetBet() {
	return bet;
}
int Player::GetChips() {
	return chips;
}
void Player::AddChips(int amt) {
	chips += amt;
}


void Player::SetRouletteBet(int bet) {
	rouletteBet = bet;
}
int Player::GetRouletteBet() {
	return rouletteBet;
}