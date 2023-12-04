#include "Game.h"
#include "Input.h"
#include "Cards.h"
#include "Casino.h"
#include <iostream>
using namespace std;

void Game::PlayGame(){
	for (Player* p : players) {
		if (p->ViewCash() <= 0) {
			cout << endl << p->GetName() << " HAS NO CASH!\n\n";
			Casino::Home();
			break;
		}
	}
}
void BlackJack::PlayGame() {
	Game::PlayGame();
	BuyIn(100);
}

void Game::ExitGame() {
	for (Player* p : players) {
		p->AddCash(p->GetChips());
		p->RemoveChips(p->GetChips());
	}
}
void Game::BuyIn(int min) {
	for (Player* p : players) {
		cout << "....................................\n";
		cout << p->GetName() << ", Turn\n";
		while (true) {
			int input = 0;
			cout << "You have $" << p->ViewCash() << ", Minimum Buy In is " << min << endl;
			cout << "How Much Would You Like To Buy In For: ";
			cin >> input;
			if (input < min) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "\nMUST MEET MIN BUYIN!\n";
				continue;
			}

			if (input > p->ViewCash()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "\nYOU DO NOT HAVE ENOUGH\n";
				continue;
			}
			p->AddChips(input);
			p->RemoveCash(input);
			break;
		}
	}
}

void PrintHand(Player p) {
	cout << "Cards: \n";
	for (Card c : p.hand) {
		cout << "\t(" << c.GetName() << ")\n";
	}
	cout << endl;
}

void PrintHand(vector<Card> hand) {
	cout << "Cards: \n";
	for (Card c : hand) {
		cout << "\t(" << c.GetName() << ")\n";
	}
	cout << endl;
}
bool CheckBlackJack(vector<Card> hand) {
	Card card1  = hand.at(0);
	Card card2 = hand.at(1);

	if (card1.GetRank() == ACE && (card2.IsFace() || card2.GetRank() == TEN)) {
		return true;
	}
	if (card2.GetRank() == ACE && (card1.IsFace() || card1.GetRank() == TEN)) {
		return true;
	}
	
	return false;
}

BlackJack::BlackJack(){
	potMoney = 0;
	dealerStand = 16;
}
BlackJack::BlackJack(vector<Player*> players) {
	this->players = players;
	dealerStand = 16;
	potMoney = 0;
}
void BlackJack::ExitGame() {
	deck = Deck();
	Game::ExitGame();
	Casino::Home();
}
void BlackJack::GetBets() {
	int count = 0;
	for (Player* p : players) {
		while (true) {
			double bet = 0;
			cout << p->GetName() << ", You have " << p->GetChips() << " chips, Enter Your Bet Amount : ";
			cin >> bet;
			if (bet > 0) {
				if (!p->RemoveChips(bet)) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "\nYou Do Not Have Enough Chips!\n";
					continue;
				}
				potMoney += bet;
				break;
			}
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nINVALID INPUT\n";
		}
		count++;
	}
	cout << endl;

	if (count == 1) {
		potMoney *= 2;
	}
}

void BlackJack::EndHand(Player* winner, double money) {
	if (winner != nullptr) {
		cout << winner->GetName() << " WON $" << money << "\n";
		winner->AddChips(money);
	}
	else {
		cout <<" The Dealer WON!\n";
	}
	for (Player* p : players) {
		p->hand.clear();
	}
	potMoney = 0;
	string output = "Would You Like To Continue [y/n] ";
	cin.ignore();
	Input::YN(output) ? PlayHand() : BlackJack::ExitGame();
	
	
	
}
int BlackJack::GetHandValue(vector<Card> hand) {
	int value = 0;
	int numAces = 0;

	for (Card c : hand) {
		switch (c.GetRank()){
		case ACE:
			numAces++;
			value += 1;
			break;
		case TWO:
			value += 2;
			break;
		case THREE:
			value += 3;
			break;
		case FOUR:
			value += 4;
			break;
		case FIVE:
			value += 5;
			break;
		case SIX:
			value += 6;
			break;
		case SEVEN:
			value += 7;
			break;
		case EIGHT:
			value += 8;
			break;
		case NINE:
			value += 9;
			break;
		case TEN:
			value += 10;
			break;
		case JACK:
			value += 10;
			break;
		case QUEEN:
			value += 10;
			break;
		case KING:
			value += 10;
			break;
		default:
			break;
		}
	}

	while (numAces > 0 && value + 10 <= 21) {
		value += 10;
		numAces--;
	}
	return value;
}
void BlackJack::PlayHand() {
	GetBets();
	deck.Shuffle();
	Player* winningPlayer = nullptr;
	vector<Card> dealerHand;
	dealerHand.push_back(deck.PullCard());
	dealerHand.push_back(deck.PullCard());
	cout << "Dealer Card: " << dealerHand.at(0).GetName() << endl;
	if (CheckBlackJack(dealerHand)) {
		//BLACKJACK
		cout << "Dealer Has BLACKJACK!!!\n\nDealer's Hand:\n";
		for (Card c : dealerHand) {
			cout << "\t(" << c.GetName() << ")\n";
		}
		EndHand(nullptr, potMoney);
		return;
	}
	for (Player* player : players) {  
		Card card1 = deck.PullCard();
		Card card2 = deck.PullCard();
		player->hand.push_back(card1);
		player->hand.push_back(card2);

		if (CheckBlackJack(player->hand)) {
			//BLACKJACK
			cout << player->GetName() << " has BLACKJACK!!!\n\n";
			PrintHand(*player);
			EndHand(player, potMoney);
			return;
		}
		
	}
	for (Player* player : players) {
		cout << "----------------------------------\n";
		cout << player->GetName() << "'s Turn\n\n";
		PrintHand(*player);

		while (true) {

			string output = "What Would You Like To Do?\n1: Hit\n2: Stand\nEnter Your Choice: ";
			switch (Input::GetInput(output, 2)) {
			case 1:
				//Hit
				player->hand.push_back(deck.PullCard());
				cout << endl;
				PrintHand(*player);
				if (GetHandValue(player->hand) > 21) {
					//Bust
					cout << "BUST!\n";
					break;
				}
				continue;
				break;
			case 2:
				break;
			default:
				break;
			}
			break;
		}
	}

	while (GetHandValue(dealerHand) < dealerStand) {
		dealerHand.push_back(deck.PullCard());
	}
	int dealerHandValue = GetHandValue(dealerHand);
	if (dealerHandValue > 21) {
		dealerHandValue = 0;
	}
	cout << "----------------------------------\n";
	cout << "The Dealer's Hand: \n";
	PrintHand(dealerHand);
	for (Player* p : players) {
		int value = GetHandValue(p->hand);
		if (!winningPlayer && value <= 21 && value > dealerHandValue) {
			winningPlayer = p;
		}else if (winningPlayer && value > GetHandValue(winningPlayer->hand)) {
			winningPlayer = p;
		}

	}
	EndHand(winningPlayer, potMoney);




}
