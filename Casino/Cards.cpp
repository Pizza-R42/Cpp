#include "Cards.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;


Card::Card() {
	rank = ACE;
	suit = SPADE;
	cardName = "NULL";
}

bool Card::IsFace() {
	if (rank == KING || rank == QUEEN || rank == JACK) {
		return true;
	}
	return false;
}
Card::Card(Rank r, Suit s) {
	rank = r;
	suit = s;
	switch (r) {
	case ACE:
		cardName = "Ace of ";
		break;
	case TWO:
		cardName = "2 of ";
		break;
	case THREE:
		cardName = "3 of ";
		break;
	case FOUR:
		cardName = "4 of ";
		break;
	case FIVE:
		cardName = "5 of ";
		break;
	case SIX:
		cardName = "6 of ";
		break;
	case SEVEN:
		cardName = "7 of ";
		break;
	case EIGHT:
		cardName = "8 of ";
		break;
	case NINE:
		cardName = "9 of ";
		break;
	case TEN:
		cardName = "10 of ";
		break;
	case JACK:
		cardName = "Jack of ";
		break;
	case QUEEN:
		cardName = "Queen of ";
		break;
	case KING:
		cardName = "King of ";
		break;
	default:
		break;
	}

	switch (s) {
	case SPADE:
		cardName += "Spades";
		break;
	case CLUB:
		cardName += "Clubs";
		break;
	case HEART:
		cardName += "Hearts";
		break;
	case DIAMOND:
		cardName += "Diamonds";
		break;
	default:
		break;
	}
}

Rank Card::GetRank() {
	return rank;
}
Suit Card::GetSuit() {
	return suit;
}
string Card::GetName() {
	return cardName;
}

Deck::Deck() {
	ResetDeck();
}
void Deck::ResetDeck() {
	deck.clear();
	int count = 0;
	for (int types = 0; types < 13; types++) {
		for (int suits = 0; suits < 4; suits++) {
			deck.push_back(Card(Rank(types), Suit(suits)));
			count++;
		}
	}
}

void Deck::Shuffle() {
	ResetDeck();
	random_device rd;
	mt19937 rng(rd());
	shuffle(deck.begin(), deck.end(), rng);
}


Card Deck::PullCard() {
	Card returnCard;
	if (deck.size() <= 0) {
		cout << "NO CARDS IN DECK!";
		return returnCard;
	}
	returnCard = deck.at(0);
	deck.erase(deck.begin());
	return returnCard;
}